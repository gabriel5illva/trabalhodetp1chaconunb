#include "CntrApresentacaoHistoriaDeUsuario.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <stdexcept>

void CntrApresentacaoHistoriaDeUsuario::setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico) {
    this->servicoHistoriaDeUsuario = servico;
}

void CntrApresentacaoHistoriaDeUsuario::setServicoPessoa(IServicoPessoa *servico) {
    this->servicoPessoa = servico;
}

void CntrApresentacaoHistoriaDeUsuario::setServicoProjeto(IServicoProjeto *servico) {
    this->servicoProjeto = servico;
}
void CntrApresentacaoHistoriaDeUsuario::setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) {
    this->servicoPlanoDeSprint = servico;
}

void CntrApresentacaoHistoriaDeUsuario::executar(const Email &emailLogado) {
    int opcao;

    Pessoa usuarioLogado = servicoPessoa->ler(emailLogado);
    std::string papelLogado = usuarioLogado.getPapel().getPapel();
    
    // Regras de Permissão
    bool isPO = (papelLogado == "PROPRIETARIO DE PRODUTO");
    bool isSM = (papelLogado == "MESTRE SCRUM"); // Nova permissão

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "       GESTAO DE HISTORIAS DE USUARIO    \n";
        std::cout << "  Usuario: " << usuarioLogado.getNome().getNome() << "\n";
        std::cout << "  Papel:   " << papelLogado << "\n";
        std::cout << "=========================================\n";
        
        if (isPO) std::cout << "1 - Criar nova Historia (C)\n";
        else std::cout << "1 - [BLOQUEADO] Criar nova Historia (Apenas PO)\n";
        
        std::cout << "2 - Ler dados de uma Historia (R)\n";

        if (isPO) std::cout << "3 - Editar uma Historia\n"; 
        else std::cout << "3 - [BLOQUEADO] Editar uma Historia (Apenas PO)\n";
        
        if (isPO) std::cout << "4 - Excluir uma Historia (D)\n";
        else std::cout << "4 - [BLOQUEADO] Excluir uma Historia (Apenas PO)\n";
        
        // --- NOVAS OPÇÕES DO MESTRE SCRUM ---
        if (isSM) {
            std::cout << "5 - Estabelecer Associacao com Pessoa\n";
            std::cout << "6 - Remover Associacao com Pessoa\n";
        } else {
            std::cout << "5 - [BLOQUEADO] Associar Pessoa (Apenas MESTRE SCRUM)\n";
            std::cout << "6 - [BLOQUEADO] Remover Associacao (Apenas MESTRE SCRUM)\n";
        }

        if (isPO || isSM) {
            std::cout << "7 - Alterar Estado da Historia (Quadro Kanban)\n"; 
        } else {
            std::cout << "7 - [BLOQUEADO] Alterar Estado (Apenas PO ou SM)\n";
        }

        if (isSM) {
            std::cout << "8 - Mover Historia para Plano de Sprint\n";
        } else {
            std::cout << "8 - [BLOQUEADO] Mover para Sprint (Apenas MESTRE SCRUM)\n";
        }
        // =========================================================

        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "=========================================\n";

        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "\nEntrada invalida. Digite um numero.\n";

            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida

            continue;
        }   

        if (opcao == 0){
            return;
        }

        // --- OPÇÃO 1: CREATE ---
        if (opcao == 1) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas o PROPRIETARIO DE PRODUTO gerencia a criacao de historias.\n";
                continue;
            }
            std::string entCodigo, entTitulo, entPapel, entAcao, entValor, entPrioridade, entEstado;
            int entEstimativa;
            
            std::cout << "\n--- CRIAR HISTORIA DE USUARIO ---\n";
            std::cout << "Codigo (Ex: HU123): ";
            std::cin >> entCodigo;
            
            std::cin.ignore(10000, '\n');
            std::cout << "Titulo: ";
            std::getline(std::cin, entTitulo);
            std::cout << "Papel (Ex: Como um cliente...): ";
            std::getline(std::cin, entPapel);
            std::cout << "Acao (Ex: Eu quero acessar...): ";
            std::getline(std::cin, entAcao);
            std::cout << "Valor (Ex: Para que eu possa...): ";
            std::getline(std::cin, entValor);

            std::cout << "Estimativa (em dias, Ex: 5): ";
            std::cin >> entEstimativa;

            // CORREÇÃO: Limpa o buffer se o utilizador digitar letras na estimativa
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                entEstimativa = -1; // Vai forçar a classe Tempo a lançar invalid_argument
            }
            
            std::cout << "Prioridade (ALTA, MEDIA, BAIXA): ";
            std::cin >> entPrioridade;
            
            std::cin.ignore(10000, '\n');
            std::cout << "Estado (A FAZER, FAZENDO, FEITO): ";
            std::getline(std::cin, entEstado);

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                Texto tit; tit.setTexto(entTitulo);
                Texto pap; pap.setTexto(entPapel);
                Texto aca; aca.setTexto(entAcao);
                Texto val; val.setTexto(entValor);
                Tempo est; est.setTempo(entEstimativa);
                Prioridade pri; pri.setPrioridade(entPrioridade);
                Estado sta; sta.setEstado(entEstado);

                HistoriaDeUsuario novaHistoria;
                novaHistoria.setCodigo(cod);
                novaHistoria.setTitulo(tit);
                novaHistoria.setPapel(pap);
                novaHistoria.setAcao(aca);
                novaHistoria.setValor(val);
                novaHistoria.setEstimativa(est);
                novaHistoria.setPrioridade(pri);
                novaHistoria.setEstado(sta);

                if (servicoHistoriaDeUsuario->criar(novaHistoria)) {
                    std::cout << "\n[Sucesso] Historia de Usuario criada com sucesso!\n";
                } else {
                    std::cout << "\n[Erro] Ja existe uma historia com este codigo.\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 2: READ ---
        else if (opcao == 2) {
            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia: ";
            std::cin >> entCodigo;
            
            try {
                Codigo cod; cod.setCodigo(entCodigo);
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                } else {
                    std::cout << "\n--- DADOS DA HISTORIA ---\n";
                    std::cout << "Codigo:     " << historia.getCodigo().getCodigo() << "\n";
                    std::string projAtual = historia.getProjetoAssociado().getCodigo();
                    std::cout << "Projeto:    " << (projAtual.empty() ? "Nenhum (No Backlog)" : projAtual) << "\n";
                    std::cout << "Titulo:     " << historia.getTitulo().getTexto() << "\n";
                    std::cout << "Titulo:     " << historia.getTitulo().getTexto() << "\n";
                    std::cout << "Papel:      " << historia.getPapel().getTexto() << "\n";
                    std::cout << "Acao:       " << historia.getAcao().getTexto() << "\n";
                    std::cout << "Valor:      " << historia.getValor().getTexto() << "\n";
                    std::cout << "Estimativa: " << historia.getEstimativa().getTempo() << " dias\n";
                    std::cout << "Prioridade: " << historia.getPrioridade().getPrioridade() << "\n";
                    std::cout << "Estado:     " << historia.getEstado().getEstado() << "\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 3: UPDATE ---
        else if (opcao == 3) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas o PROPRIETARIO DE PRODUTO edita historias.\n";
                continue;
            }
            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia que deseja EDITAR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                } else {
                    std::string nTitulo, nPapel, nAcao, nValor, nPrioridade, nEstado;
                    int nEstimativa;

                    std::cin.ignore(10000, '\n');
                    std::cout << "\nNovo Titulo: "; std::getline(std::cin, nTitulo);
                    std::cout << "Novo Papel: "; std::getline(std::cin, nPapel);
                    std::cout << "Nova Acao: "; std::getline(std::cin, nAcao);
                    std::cout << "Novo Valor: "; std::getline(std::cin, nValor);

                    std::cout << "Nova Estimativa: "; std::cin >> nEstimativa;

                    // CORREÇÃO: Limpa o buffer também na atualização
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        nEstimativa = -1;
                    }

                    std::cout << "Nova Prioridade (ALTA, MEDIA, BAIXA): "; std::cin >> nPrioridade;
                    
                    std::cin.ignore(10000, '\n');
                    std::cout << "Novo Estado (A FAZER, FAZENDO, FEITO): "; std::getline(std::cin, nEstado);

                    char associarProj;
                    std::string projAtual = historia.getProjetoAssociado().getCodigo(); // Declarado apenas UMA vez!
                    
                    std::cout << "\nEsta historia esta atualmente no projeto: " 
                              << (projAtual.empty() ? "NENHUM" : projAtual) << "\n";
                    std::cout << "Deseja alterar/estabelecer o Projeto desta historia? (S/N): ";
                    std::cin >> associarProj;
                    
                    if (associarProj == 'S' || associarProj == 's') {
                        std::string nCodProj;
                        std::cout << "Digite o Codigo do novo Projeto (Ex: PR123): ";
                        std::cin >> nCodProj;

                        Codigo codP; codP.setCodigo(nCodProj);

                        // VALIDACAO CRÍTICA: Verifica se o projeto existe e se é um Projeto válido
                        if (servicoProjeto == nullptr) {
                            std::cout << "\n[Erro Interno] Servico de projetos nao interligado.\n";
                        } else {
                            Projeto projValido = servicoProjeto->ler(codP);
                            if (projValido.getCodigo().getCodigo() == "") {
                                std::cout << "\n[Erro] Codigo invalido! O projeto nao existe ou nao pertence a classe de Projetos.\n";
                            } else {
                                historia.setProjetoAssociado(codP); // Só associa se passar no teste!
                                std::cout << "\n[Sucesso] Validado! Historia vinculada ao projeto: " << projValido.getNome().getNome() << "\n";
                            }
                        }
                    }

                    Texto tit; tit.setTexto(nTitulo);
                    Texto pap; pap.setTexto(nPapel);
                    Texto aca; aca.setTexto(nAcao);
                    Texto val; val.setTexto(nValor);
                    Tempo est; est.setTempo(nEstimativa);
                    Prioridade pri; pri.setPrioridade(nPrioridade);
                    Estado sta; sta.setEstado(nEstado);

                    historia.setTitulo(tit);
                    historia.setPapel(pap);
                    historia.setAcao(aca);
                    historia.setValor(val);
                    historia.setEstimativa(est);
                    historia.setPrioridade(pri);
                    historia.setEstado(sta);

                    if (servicoHistoriaDeUsuario->atualizar(historia)) {
                        std::cout << "\n[Sucesso] Historia atualizada com sucesso!\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao atualizar a historia.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 4: DELETE ---
        else if (opcao == 4) {
            if (!isPO) {
                std::cout << "\n[Acesso Negado] Apenas o PROPRIETARIO DE PRODUTO pode excluir historias.\n";
                continue;
            }
            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia que deseja EXCLUIR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                char confirm;
                std::cout << "Tem certeza que deseja excluir a historia " << entCodigo << "? (S/N): ";
                std::cin >> confirm;
                
                if (confirm == 'S' || confirm == 's') {
                    if (servicoHistoriaDeUsuario->excluir(cod)) {
                        std::cout << "\n[Sucesso] Historia excluida do sistema.\n";
                    } else {
                        std::cout << "\n[Erro] Historia nao encontrada.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        // Opção 5: Associar pessoas as historias
        else if (opcao == 5) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas o MESTRE SCRUM pode associar pessoas as historias.\n";
                continue;
            }

            std::string entCodigo, entEmail;
            std::cout << "\nDigite o Codigo da Historia: ";
            std::cin >> entCodigo;
            
            std::cout << "Digite o E-mail do usuario que assumira a Historia: ";
            std::cin >> entEmail;

            try {
                // 1. Verifica se a história existe
                Codigo cod; cod.setCodigo(entCodigo);
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                    continue;
                }

                // 2. Verifica se a pessoa existe no sistema
                Email emailBusca; emailBusca.setEmail(entEmail);
                Pessoa dev = servicoPessoa->ler(emailBusca);

                if (dev.getEmail().getEmail() == "") {
                    std::cout << "\n[Erro] Nenhum usuario cadastrado com este e-mail.\n";
                    continue;
                }

                // 3. Estabelece a associação
                historia.setEmailAssociado(emailBusca);

                if (servicoHistoriaDeUsuario->atualizar(historia)) {
                    std::cout << "\n[Sucesso] Historia associada a " << dev.getNome().getNome() << " com sucesso!\n";
                } else {
                    std::cout << "\n[Erro] Falha ao salvar associacao.\n";
                }

            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        // --- OPÇÃO 6: REMOVER ASSOCIAÇÃO ---
        else if (opcao == 6) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas o MESTRE SCRUM pode remover associacoes.\n";
                continue;
            }

            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia para remover o usuario associado: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                } else {
                    // Cria um email vazio para limpar a associação
                    Email emailVazio; 
                    historia.setEmailAssociado(emailVazio);

                    if (servicoHistoriaDeUsuario->atualizar(historia)) {
                        std::cout << "\n[Sucesso] Associacao removida. A historia agora esta sem dono.\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao remover associacao.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }


        // --- OPÇÃO 7: ALTERAR ESTADO ---
        else if (opcao == 7) {

            if (!isPO && !isSM) {
                std::cout << "\n[Acesso Negado] Apenas PROPRIETARIO DE PRODUTO ou MESTRE SCRUM podem alterar o estado.\n";
                continue; // Interrompe e volta ao menu
            }

            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia que deseja mover: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                } else {
                    std::string nEstado;
                    
                    std::cout << "\nEstado Atual: " << historia.getEstado().getEstado() << "\n";
                    
                    std::cin.ignore(10000, '\n');
                    std::cout << "Novo Estado (A FAZER, FAZENDO, FEITO): "; 
                    std::getline(std::cin, nEstado);

                    Estado sta; 
                    sta.setEstado(nEstado);

                    historia.setEstado(sta);

                    if (servicoHistoriaDeUsuario->atualizar(historia)) {
                        std::cout << "\n[Sucesso] Historia movida para '" << nEstado << "' com sucesso!\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao atualizar o estado da historia.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }

        // --- OPÇÃO 8: MOVER PARA SPRINT (APENAS MESTRE SCRUM) ---
        else if (opcao == 8) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas o MESTRE SCRUM pode mover historias para Sprints.\n";
                continue;
            }

            std::string entCodigo;
            std::cout << "\nDigite o Codigo da Historia que deseja mover para a Sprint: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; cod.setCodigo(entCodigo);
                HistoriaDeUsuario historia = servicoHistoriaDeUsuario->ler(cod);

                if (historia.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Historia nao encontrada.\n";
                } else {
                    std::string sprintAtual = historia.getSprintAssociada().getCodigo();
                    std::string projAtual = historia.getProjetoAssociado().getCodigo();

                    std::cout << "\n--- Status Atual da Historia ---\n";
                    std::cout << "Projeto: " << (projAtual.empty() ? "Nenhum" : projAtual) << "\n";
                    std::cout << "Sprint:  " << (sprintAtual.empty() ? "Nenhuma" : sprintAtual) << "\n";

                    std::string nCodSprint;
                    std::cout << "\nDigite o Codigo do Plano de Sprint para o qual deseja mover (Ex: SP123): ";
                    std::cin >> nCodSprint;
                                    
                    Codigo cSprint; cSprint.setCodigo(nCodSprint);
                                    
                    // VALIDACAO CRÍTICA: Verifica se a Sprint existe no banco/memória de Sprints
                    if (servicoPlanoDeSprint == nullptr) {
                        std::cout << "\n[Erro Interno] Servico de Sprints nao interligado.\n";
                    } else {
                        PlanoDeSprint sprintValida = servicoPlanoDeSprint->ler(cSprint);
                        if (sprintValida.getCodigo().getCodigo() == "") {
                            std::cout << "\n[Erro] Codigo invalido! Esta Sprint nao existe no sistema.\n";
                        } else {
                            historia.setSprintAssociada(cSprint); // Só move se existir de fato!
                            std::cout << "\n[Sucesso] Validado! Historia movida para a Sprint com sucesso.\n";
                        }
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        
        else {
            if (opcao < 0 || opcao > 8) {
                std::cout << "\nOpcao invalida. Tente novamente.\n";
            }
        }
    }
}