#include "CntrApresentacaoPlanoDeSprint.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <stdexcept>

void CntrApresentacaoPlanoDeSprint::setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) {
    this->servicoPlanoDeSprint = servico;
}

void CntrApresentacaoPlanoDeSprint::setServicoPessoa(IServicoPessoa *servico) {
    this->servicoPessoa = servico;
}

void CntrApresentacaoPlanoDeSprint::executar(const Email &emailLogado) {
    int opcao;

    // 1. Identifica o utilizador e o seu papel para aplicar as permissões
    Pessoa usuarioLogado = servicoPessoa->ler(emailLogado);
    std::string papelLogado = usuarioLogado.getPapel().getPapel();
    
    // Apenas MESTRE SCRUM pode realizar alterações estruturais nas Sprints
    bool isSM = (papelLogado == "MESTRE SCRUM");

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "           GESTAO PLANO DE SPRINT        \n";
        std::cout << "  Usuario: " << usuarioLogado.getNome().getNome() << "\n";
        std::cout << "  Papel:   " << papelLogado << "\n";
        std::cout << "=========================================\n";
        
        if (isSM) {
            std::cout << "1 - Criar novo Plano de Sprint (C)\n";
        } else {
            std::cout << "1 - [BLOQUEADO] Criar novo Plano de Sprint\n";
        }
        
        std::cout << "2 - Ler dados de um Plano de Sprint (R)\n";
        
        if (isSM) {
            std::cout << "3 - Editar um Plano de Sprint (U)\n";
            std::cout << "4 - Excluir um Plano de Sprint (D)\n";
        } else {
            std::cout << "3 - [BLOQUEADO] Editar um Plano de Sprint\n";
            std::cout << "4 - [BLOQUEADO] Excluir um Plano de Sprint\n";
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

        if (opcao == 0) {
            return; // Retorna para o menu de controle principal
        }

        // --- OPÇÃO 1: CREATE ---
        if (opcao == 1) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas MESTRE SCRUM pode criar planos de sprint.\n";
                continue;
            }
            std::string entCodigo, entObjetivo;
            int entCapacidade;
            
            std::cout << "\n--- CRIAR PLANO DE SPRINT ---\n";
            std::cout << "Codigo do Plano de Sprint (Ex: AB123): ";
            std::cin >> entCodigo;
            
            std::cin.ignore(10000, '\n'); // Limpa o buffer
            std::cout << "Objetivo do Sprint (Ate 40 caracteres): ";
            std::getline(std::cin, entObjetivo);
            
            std::cout << "Capacidade do Sprint (Tempo em dias de 1 a 365): ";
            std::cin >> entCapacidade;

            try {
                Codigo cod; 
                cod.setCodigo(entCodigo);
                
                Texto obj;
                obj.setTexto(entObjetivo);
                
                Tempo cap;
                cap.setTempo(entCapacidade);

                PlanoDeSprint novoPlano;
                novoPlano.setCodigo(cod);
                novoPlano.setObjetivo(obj);
                novoPlano.setCapacidade(cap);

                if (servicoPlanoDeSprint->criar(novoPlano)) {
                    std::cout << "\n[Sucesso] Plano de Sprint criado com sucesso!\n";
                } else {
                    std::cout << "\n[Erro] Ja existe um plano de sprint com este codigo.\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 2: READ ---
        else if (opcao == 2) {
            std::string entCodigo;
            std::cout << "\nDigite o Codigo do plano de sprint a buscar: ";
            std::cin >> entCodigo;
            
            try {
                Codigo cod; 
                cod.setCodigo(entCodigo);
                PlanoDeSprint plano = servicoPlanoDeSprint->ler(cod);

                if (plano.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Plano de Sprint nao encontrado.\n";
                } else {
                    std::cout << "\n--- DADOS DO PLANO DE SPRINT ---\n";
                    std::cout << "Codigo:     " << plano.getCodigo().getCodigo() << "\n";
                    std::cout << "Objetivo:   " << plano.getObjetivo().getTexto() << "\n";
                    std::cout << "Capacidade: " << plano.getCapacidade().getTempo() << " dias\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 3: UPDATE ---
        else if (opcao == 3) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas MESTRE SCRUM pode editar planos de sprint.\n";
                continue;
            }
            std::string entCodigo;
            std::cout << "\nDigite o Codigo do plano de sprint que deseja EDITAR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; 
                cod.setCodigo(entCodigo);
                PlanoDeSprint plano = servicoPlanoDeSprint->ler(cod);

                if (plano.getCodigo().getCodigo() == "") {
                    std::cout << "\n[Erro] Plano de Sprint nao encontrado.\n";
                } else {
                    std::string novoObjetivo;
                    int novaCapacidade;

                    std::cin.ignore(10000, '\n');
                    std::cout << "\nNovo Objetivo (Atual: " << plano.getObjetivo().getTexto() << "): ";
                    std::getline(std::cin, novoObjetivo);
                    
                    std::cout << "Nova Capacidade em dias (Atual: " << plano.getCapacidade().getTempo() << "): ";
                    std::cin >> novaCapacidade;
                    
                    // Associar Projeto ao Plano de sprint.
                    char associarProj;
                    std::string projAtual = plano.getProjetoAssociado().getCodigo();
                    
                    std::cout << "\nEste Plano de Sprint esta atualmente no projeto: " 
                              << (projAtual.empty() ? "NENHUM" : projAtual) << "\n";
                    std::cout << "Deseja alterar/estabelecer o Projeto deste Plano de Sprint? (S/N): ";
                    std::cin >> associarProj;
                    
                    if (associarProj == 'S' || associarProj == 's') {
                        std::string nCodProj;
                        std::cout << "Digite o Codigo do novo Projeto (Ex: PR123): ";
                        std::cin >> nCodProj;
                        
                        Codigo codP; codP.setCodigo(nCodProj);
                        plano.setProjetoAssociado(codP); // Associa o projeto na entidade
                    }

                    Texto obj;
                    obj.setTexto(novoObjetivo);
                    
                    Tempo cap;
                    cap.setTempo(novaCapacidade);

                    // Atualiza os dados na entidade local
                    plano.setObjetivo(obj);
                    plano.setCapacidade(cap);

                    if (servicoPlanoDeSprint->atualizar(plano)) {
                        std::cout << "\n[Sucesso] Plano de Sprint atualizado com sucesso!\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao atualizar o plano de sprint.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 4: DELETE ---
        else if (opcao == 4) {
            if (!isSM) {
                std::cout << "\n[Acesso Negado] Apenas MESTRE SCRUM pode excluir planos de sprint.\n";
                continue;
            }
            std::string entCodigo;
            std::cout << "\nDigite o Codigo do plano de sprint que deseja EXCLUIR: ";
            std::cin >> entCodigo;

            try {
                Codigo cod; 
                cod.setCodigo(entCodigo);
                char confirm;
                std::cout << "Tem certeza que deseja excluir o plano " << entCodigo << "? (S/N): ";
                std::cin >> confirm;
                
                if (confirm == 'S' || confirm == 's') {
                    if (servicoPlanoDeSprint->excluir(cod)) {
                        std::cout << "\n[Sucesso] Plano de Sprint excluido do sistema.\n";
                    } else {
                        std::cout << "\n[Erro] Plano de Sprint nao encontrado.\n";
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