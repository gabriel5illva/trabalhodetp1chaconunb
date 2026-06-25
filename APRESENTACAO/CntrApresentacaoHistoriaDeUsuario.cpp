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
        
        std::cout << "5 - Listar Historias por Plano de Sprint\n";
        
        // --- NOVAS OPÇÕES DO MESTRE SCRUM ---
        if (isSM) {
            std::cout << "6 - Estabelecer Associacao com Pessoa\n";
            std::cout << "7 - Remover Associacao com Pessoa\n";
        } else {
            std::cout << "6 - [BLOQUEADO] Associar Pessoa (Apenas MESTRE SCRUM)\n";
            std::cout << "7 - [BLOQUEADO] Remover Associacao (Apenas MESTRE SCRUM)\n";
        }

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
                    std::string projAtual = historia.getProjetoAssociado().getCodigo();
                    
                    std::cout << "\nEsta historia esta atualmente no projeto: " 
                              << (projAtual.empty() ? "NENHUM" : projAtual) << "\n";
                    std::cout << "Deseja alterar/estabelecer o Projeto desta historia? (S/N): ";
                    std::cin >> associarProj;
                    
                    if (associarProj == 'S' || associarProj == 's') {
                        std::string nCodProj;
                        std::cout << "Digite o Codigo do novo Projeto (Ex: PR123): ";
                        std::cin >> nCodProj;
                        
                        Codigo codP; codP.setCodigo(nCodProj);
                        historia.setProjetoAssociado(codP); // Associa na entidade
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
        
        // --- OPÇÃO 5: LISTAR POR SPRINT ---
        else if (opcao == 5) {
            std::string entCodigoSprint;
            std::cout << "\nDigite o Codigo do Plano de Sprint para listar as Historias: ";
            std::cin >> entCodigoSprint;

            try {
                Codigo codSprint; codSprint.setCodigo(entCodigoSprint);
                std::cout << "\nConsultando historias vinculadas a sprint " << entCodigoSprint << "...\n";
                if (servicoHistoriaDeUsuario->listarPorPlanoDeSprint(codSprint)) {
                    std::cout << "[Resultado] Existem historias cadastradas para esta sprint.\n";
                } else {
                    std::cout << "[Resultado] Nenhuma historia encontrada.\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
            std::cout << "Pressione ENTER para continuar...";
            std::cin.ignore(10000, '\n'); std::cin.get();
        }

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

        // --- OPÇÃO 7: REMOVER ASSOCIAÇÃO ---
        else if (opcao == 7) {
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
        
        else {
            if (opcao < 0 || opcao > 8) {
                std::cout << "\nOpcao invalida. Tente novamente.\n";
            }
        }
    }
}