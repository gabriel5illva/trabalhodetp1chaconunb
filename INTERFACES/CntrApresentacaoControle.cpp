#include "CntrApresentacaoControle.hpp"
#include <iostream>

void CntrApresentacaoControle::setApresentacaoAutenticacao(IApresentacaoAutenticacao *apresentacao) {
    this->apresentacaoAutenticacao = apresentacao;
}

void CntrApresentacaoControle::setApresentacaoUsuario(IApresentacaoUsuario *apresentacao) {
    this->apresentacaoUsuario = apresentacao;
}

void CntrApresentacaoControle::executar() {
    int opcao;
    Email emailSessao; // Armazenará o e-mail do usuário autenticado

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
                if (apresentacaoAutenticacao != nullptr && apresentacaoUsuario != nullptr) {
                    // Se a autenticação tiver sucesso, emailSessao é preenchido por referência
                    if (apresentacaoAutenticacao->autenticar(emailSessao)) {
                        // Direciona para o menu principal logado passando a sessão
                        apresentacaoUsuario->executar(emailSessao);
                    }
                } else {
                    std::cout << "\n[Erro] Modulos de autenticacao/usuario nao conectados.\n";
                }
                break;

            case 2:
                if (apresentacaoUsuario != nullptr) {
                    apresentacaoUsuario->cadastrar();
                } else {
                    std::cout << "\n[Erro] Modulo de usuario nao conectado.\n";
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
