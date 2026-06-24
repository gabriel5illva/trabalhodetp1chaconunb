#include "CntrApresentacaoControle.hpp"
#include <iostream>

// Inicializa todos os ponteiros como nulos para evitar acessos inválidos de memória
CntrApresentacaoControle::CntrApresentacaoControle() {
    apresentacaoAutenticacao = nullptr;
    apresentacaoPessoa = nullptr;
    apresentacaoProjeto = nullptr;
    apresentacaoPlanoDeSprint = nullptr;
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
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                if (apresentacaoAutenticacao != nullptr) {
                    if (apresentacaoAutenticacao->autenticar(emailSessao)) {
                        // Se autenticado com sucesso, entra no Menu Principal
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
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                if (apresentacaoPessoa != nullptr) {
                    // Se o método retornar false, significa que a conta foi excluída por dentro do menu
                    if (!apresentacaoPessoa->executar(email)) {
                        return; // Força o logout imediato e volta ao menu deslogado
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
                // ATUALIZADO: Dispara as telas reais de Sprint!
                if (apresentacaoPlanoDeSprint != nullptr) {
                    apresentacaoPlanoDeSprint->executar(email);
                } else {
                    std::cout << "\n[Erro] Modulo de planos de sprint indisponivel.\n";
                }
                break;
            case 4:
                std::cout << "\n[Modulo de Historia de Usuario em desenvolvimento...]\n";
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