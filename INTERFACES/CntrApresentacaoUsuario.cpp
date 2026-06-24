#include "CntrApresentacaoUsuario.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

void CntrApresentacaoUsuario::setServicoUsuarios(IServicoUsuarios *servico) {
    this->servicoUsuarios = servico;
}

void CntrApresentacaoUsuario::cadastrar() {
    std::string entradaEmail, entradaSenha;

    std::cout << "\n-----------------------------------------\n";
    std::cout << "            TELA DE CADASTRO             \n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Digite um E-mail valido: ";
    std::cin >> entradaEmail;
    std::cout << "Digite uma Senha valida: ";
    std::cin >> entradaSenha;

    try {
        Email objEmail;
        objEmail.setEmail(entradaEmail);
        Senha objSenha;
        objSenha.setSenha(entradaSenha);

        Pessoa novaPessoa;
        novaPessoa.setEmail(objEmail);
        novaPessoa.setSenha(objSenha);

        if (servicoUsuarios == nullptr) {
            std::cout << "\n[Erro] Servico de usuarios indisponivel.\n";
            return;
        }

        if (servicoUsuarios->criar(novaPessoa)) {
            std::cout << "\n[Sucesso] Cadastro realizado! Voce ja pode fazer login.\n";
        } else {
            std::cout << "\n[Erro] E-mail ja cadastrado no sistema.\n";
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "\n[Erro de Formato] " << e.what() << "\nCadastro cancelado.\n";
    }

    std::cout << "Pressione ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void CntrApresentacaoUsuario::executar(const Email &email) {
    int opcao;

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "              MENU PRINCIPAL             \n";
        std::cout << "          Sessao: " << email.getEmail() << "\n";
        std::cout << "=========================================\n";
        std::cout << "1 - Pessoas\n";
        std::cout << "2 - Projetos\n";
        std::cout << "3 - Plano de Sprint\n";
        std::cout << "4 - Historia de Usuario\n";
        std::cout << "0 - Sair\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "\n[Modulo de Pessoas em desenvolvimento...]\n";
                break;
            case 2:
                std::cout << "\n[Modulo de Projetos em desenvolvimento...]\n";
                break;
            case 3:
                std::cout << "\n[Modulo de Plano de Sprint em desenvolvimento...]\n";
                break;
            case 4:
                std::cout << "\n[Modulo de Historia de Usuario em desenvolvimento...]\n";
                break;
            case 0:
                std::cout << "\nFazendo logout e retornando ao menu inicial...\n";
                return; // Sai do método executar() e retorna ao loop da CntrApresentacaoControle
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n";
                break;
        }
    }
}
