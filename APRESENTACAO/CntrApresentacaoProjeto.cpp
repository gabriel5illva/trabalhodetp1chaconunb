#include "CntrApresentacaoProjeto.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

void CntrApresentacaoProjeto::setServicoProjeto(IServicoProjeto *servico) {
    this->servicoProjeto = servico;
}

void CntrApresentacaoProjeto::setServicoPessoa(IServicoPessoa *servico) {
    this->servicoPessoa = servico;
}

void CntrApresentacaoProjeto::setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico) {
    this->servicoHistoriaDeUsuario = servico;
}

void CntrApresentacaoProjeto::setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) {
    this->servicoPlanoDeSprint = servico;
}

void CntrApresentacaoProjeto::executar(const Email &emailLogado) {
    int opcao;

    Pessoa usuarioLogado = servicoPessoa->ler(emailLogado);
    std::string papelLogado = usuarioLogado.getPapel().getPapel();

    bool isPO = (papelLogado == "PROPRIETARIO DE PRODUTO");

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "             GESTAO DE PROJETOS          \n";
        std::cout << "  Usuario: " << usuarioLogado.getNome().getNome() << "\n";
        std::cout << "  Papel:   " << papelLogado << "\n";
        std::cout << "=========================================\n";

        if (isPO) {
            std::cout << "1 - Criar novo Projeto (C)\n";
        } else {
            std::cout << "1 - [BLOQUEADO] Criar novo Projeto\n";
        }

        std::cout << "2 - Ler dados de um Projeto (R)\n";

        if (isPO) {
            std::cout << "3 - Editar um Projeto (U)\n";
            std::cout << "4 - Excluir um Projeto (D)\n";
        } else {
            std::cout << "3 - [BLOQUEADO] Editar um Projeto\n";
            std::cout << "4 - [BLOQUEADO] Excluir um Projeto\n";
        }

        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            return;
        }

        if (opcao == 1) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas PROPRIETARIO DE PRODUTO pode criar projetos.\n";
                continue;
            }

            std::string entCodigo;
            std::string entNome;
            std::string entDataInicio;
            std::string entDataTermino;

            std::cout << "\n--- CRIAR PROJETO ---\n";
            std::cout << "Codigo do Projeto (Ex: AB123): ";
            std::cin >> entCodigo;

            std::cin.ignore(10000, '\n');

            std::cout << "Nome do Projeto (Ate 10 letras): ";
            std::getline(std::cin, entNome);

            std::cout << "Data de Inicio (DD/MM/AAAA): ";
            std::cin >> entDataInicio;

            std::cout << "Data de Termino (DD/MM/AAAA): ";
            std::cin >> entDataTermino;

            try {
                Codigo cod;
                cod.setCodigo(entCodigo);

                Nome n;
                n.setNome(entNome);

                Data dInicio;
                dInicio.setData(entDataInicio);

                Data dTermino;
                dTermino.setData(entDataTermino);

                Projeto novoProj;
                novoProj.setCodigo(cod);
                novoProj.setNome(n);
                novoProj.setInicio(dInicio);
                novoProj.setTermino(dTermino);
                novoProj.setEmailAssociado(emailLogado);

                if (servicoProjeto->criar(novoProj)) {
                    std::cout << "\n[Sucesso] Projeto criado com sucesso!\n";
                } else {
                    std::cout << "\n[Erro] Ja existe um projeto com este codigo.\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        else if (opcao == 2) {
            std::string entCodigo;

            std::cout << "\nDigite o Codigo do projeto a ser buscado: ";
            std::cin >> entCodigo;

            try {
                Codigo cod;
                cod.setCodigo(entCodigo);

                Projeto proj = servicoProjeto->ler(cod);

                if (proj.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Projeto nao encontrado.\n";
                } else {
                    std::cout << "\n--- DADOS DO PROJETO ---\n";
                    std::cout << "Codigo:  " << proj.getCodigo().getCodigo() << "\n";
                    std::cout << "Nome:    " << proj.getNome().getNome() << "\n";
                    std::cout << "Inicio:  " << proj.getInicio().getData() << "\n";
                    std::cout << "Termino: " << proj.getTermino().getData() << "\n";

                    char verHistorias;

                    std::cout << "\nDeseja listar as Historias de Usuario deste projeto? (S/N): ";
                    std::cin >> verHistorias;

                    if (verHistorias == 'S' || verHistorias == 's') {
                        if (servicoHistoriaDeUsuario == nullptr) {
                            std::cout << "\n[Erro Interno] O modulo de historias de usuario nao foi interligado.\n";
                        } else {
                            std::vector<HistoriaDeUsuario> historiasDoProj =
                                servicoHistoriaDeUsuario->listarPorProjeto(proj.getCodigo());

                            if (historiasDoProj.empty()) {
                                std::cout << "Nenhuma Historia de Usuario vinculada a este projeto.\n";
                            } else {
                                std::cout << "\nHistorias de Usuario do Projeto:\n";

                                for (size_t i = 0; i < historiasDoProj.size(); ++i) {
                                    std::cout << (i + 1) << "- "
                                              << historiasDoProj[i].getCodigo().getCodigo() << " | "
                                              << historiasDoProj[i].getTitulo().getTexto() << " ["
                                              << historiasDoProj[i].getEstado().getEstado() << "]\n";
                                }
                            }
                        }
                    }

                    char verSprints;

                    std::cout << "\nDeseja listar os Planos de Sprint deste projeto? (S/N): ";
                    std::cin >> verSprints;

                    if (verSprints == 'S' || verSprints == 's') {
                        if (servicoPlanoDeSprint == nullptr) {
                            std::cout << "\n[Erro Interno] O modulo de planos de sprint nao foi interligado.\n";
                        } else {
                            bool existemSprints =
                                servicoPlanoDeSprint->listarPorProjeto(proj.getCodigo());

                            if (!existemSprints) {
                                std::cout << "Nenhum Plano de Sprint vinculado a este projeto.\n";
                            } else {
                                std::cout << "Existem Planos de Sprint vinculados a este projeto.\n";
                            }
                        }
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        else if (opcao == 3) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas PROPRIETARIO DE PRODUTO pode editar projetos.\n";
                continue;
            }

            std::string entCodigo;

            std::cout << "\nDigite o Codigo do projeto que deseja EDITAR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod;
                cod.setCodigo(entCodigo);

                Projeto proj = servicoProjeto->ler(cod);

                if (proj.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Projeto nao encontrado.\n";
                } else {
                    std::string novoNome;
                    std::string novaDataInicio;
                    std::string novaDataTermino;

                    std::cin.ignore(10000, '\n');

                    std::cout << "\nNovo Nome (Atual: " << proj.getNome().getNome() << "): ";
                    std::getline(std::cin, novoNome);

                    std::cout << "Nova Data de Inicio (Atual: " << proj.getInicio().getData() << "): ";
                    std::cin >> novaDataInicio;

                    std::cout << "Nova Data de Termino (Atual: " << proj.getTermino().getData() << "): ";
                    std::cin >> novaDataTermino;

                    Nome n;
                    n.setNome(novoNome);

                    Data dInicio;
                    dInicio.setData(novaDataInicio);

                    Data dTermino;
                    dTermino.setData(novaDataTermino);

                    proj.setNome(n);
                    proj.setInicio(dInicio);
                    proj.setTermino(dTermino);

                    if (servicoProjeto->atualizar(proj)) {
                        std::cout << "\n[Sucesso] Projeto atualizado com sucesso!\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao atualizar projeto.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        else if (opcao == 4) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas PROPRIETARIO DE PRODUTO pode excluir projetos.\n";
                continue;
            }

            std::string entCodigo;

            std::cout << "\nDigite o Codigo do projeto que deseja EXCLUIR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod;
                cod.setCodigo(entCodigo);

                char confirm;

                std::cout << "Tem certeza que deseja excluir o projeto " << entCodigo << "? (S/N): ";
                std::cin >> confirm;

                if (confirm == 'S' || confirm == 's') {
                    if (servicoProjeto->excluir(cod)) {
                        std::cout << "\n[Sucesso] Projeto excluido do sistema.\n";
                    } else {
                        std::cout << "\n[Erro] Projeto nao encontrado.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        else {
            std::cout << "\nOpcao invalida. Tente novamente.\n";
        }
    }
}
