#include "CntrApresentacaoControle.hpp"
#include <iostream>
#include <limits>

// Inicializa todos os ponteiros como nulos para evitar falhas de segmentação em memória
CntrApresentacaoControle::CntrApresentacaoControle() {
    apresentacaoAutenticacao = nullptr;
    apresentacaoPessoa = nullptr;
    apresentacaoProjeto = nullptr;
    apresentacaoPlanoDeSprint = nullptr;
    apresentacaoHistoriaDeUsuario = nullptr; // INCLUÍDO
}

void CntrApresentacaoControle::setApresentacaoAutenticacao(IApresentacaoAutenticacao *apresentacao) {
    this->apresentacaoAutenticacao = apresentacao;
}

void CntrApresentacaoControle::setApresentacaoPessoa(IApresentacaoPessoa *apresentacao) {
    this->apresentacaoPessoa = apresentacao;
}

void CntrApresentacaoControle::setApresentacaoProjeto(IApresentacaoProjeto *apresentacao) {
    this->apresentacaoProjeto = apresentacao;
}

void CntrApresentacaoControle::setApresentacaoPlanoDeSprint(IApresentacaoPlanoDeSprint *apresentacao) {
    this->apresentacaoPlanoDeSprint = apresentacao;
}

void CntrApresentacaoControle::setApresentacaoHistoriaDeUsuario(IApresentacaoHistoriaDeUsuario *apresentacao) {
    this->apresentacaoHistoriaDeUsuario = apresentacao; // INCLUÍDO
}

void CntrApresentacaoControle::executar() {
    int opcao;
    Email emailSessao;

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "             SISTEMA INICIAL             \n";
        std::cout << "=========================================\n";
        std::cout << "1 - Autenticar\n";
        std::cout << "2 - Cadastrar\n";
        std::cout << "0 - Sair\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "\nEntrada invalida. Digite um numero.\n";

            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida

            continue;
        }   

        switch (opcao) {
            case 1:
                if (apresentacaoAutenticacao != nullptr) {
                    if (apresentacaoAutenticacao->autenticar(emailSessao)) {
                        // Se for autenticado com sucesso, entra no Menu Principal
                        menuPrincipal(emailSessao);
                    }
                } else {
                    std::cout << "\n[Erro] Modulo de autenticacao indisponivel.\n";
                }
                break;
            case 2:
                if (apresentacaoPessoa != nullptr) {
                    apresentacaoPessoa->cadastrar();
                } else {
                    std::cout << "\n[Erro] Modulo de cadastro indisponivel.\n";
                }
                break;
            case 0:
                std::cout << "\nEncerrando o sistema. Ate logo!\n";
                return;
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n";
                break;
        }
    }
}

void CntrApresentacaoControle::menuPrincipal(const Email &email) {
    int opcao;

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "              MENU PRINCIPAL             \n";
        std::cout << "          Sessao: " << email.getEmail() << "\n";
        std::cout << "=========================================\n";
        std::cout << "1 - Pessoas (Gerenciar Perfil)\n";
        std::cout << "2 - Projetos\n";
        std::cout << "3 - Plano de Sprint\n";
        std::cout << "4 - Historia de Usuario\n";
        std::cout << "0 - Sair (Logout)\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "\nEntrada invalida. Digite um numero.\n";

            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida

            continue;
        }   

        switch (opcao) {
            case 1:
                if (apresentacaoPessoa != nullptr) {
                    // Se o método retornar false, significa que a conta foi excluída por dentro
                    if (!apresentacaoPessoa->executar(email)) {
                        return; // Força logout imediato e volta à tela deslogada
                    }
                } else {
                    std::cout << "\n[Erro] Modulo de pessoas indisponivel.\n";
                }
                break;
            case 2:
                if (apresentacaoProjeto != nullptr) {
                    apresentacaoProjeto->executar(email); 
                } else {
                    std::cout << "\n[Erro] Modulo de projetos indisponivel.\n";
                }
                break;
            case 3:
                if (apresentacaoPlanoDeSprint != nullptr) {
                    apresentacaoPlanoDeSprint->executar(email);
                } else {
                    std::cout << "\n[Erro] Modulo de planos de sprint indisponivel.\n";
                }
                break;
            case 4:
                // ATUALIZADO: Dispara as telas reais de Historias de Usuario!
                if (apresentacaoHistoriaDeUsuario != nullptr) {
                    apresentacaoHistoriaDeUsuario->executar(email);
                } else {
                    std::cout << "\n[Erro] Modulo de historias de usuario indisponivel.\n";
                }
                break;
            case 0:
                std::cout << "\nEfetuando logout...\n";
                return;
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n";
                break;
        }
    }
}