#include "CntrApresentacaoPessoa.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

void CntrApresentacaoPessoa::setServicoPessoa(IServicoPessoa *servico) {
    this->servicoPessoas = servico;
}

void CntrApresentacaoPessoa::cadastrar() {
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

        if (servicoPessoas == nullptr) {
            std::cout << "\n[Erro] Servico de usuarios indisponivel.\n";
            return;
        }

        if (servicoPessoas->criar(novaPessoa)) {
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

// CORREÇÃO AQUI: Retorna bool e foca no CRUD do Perfil
bool CntrApresentacaoPessoa::executar(const Email &email) {
    int opcao;

    while (true) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "             GERENCIAR PERFIL            \n";
        std::cout << "-----------------------------------------\n";
        std::cout << "1 - Visualizar meus dados (Read)\n";
        std::cout << "2 - Atualizar minha senha (Update)\n";
        std::cout << "3 - Excluir minha conta (Delete)\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            Pessoa p = servicoPessoas->ler(email);
            std::cout << "\n--- MEUS DADOS ---\n";
            std::cout << "E-mail: " << p.getEmail().getEmail() << "\n";
        } 
        else if (opcao == 2) {
            std::string novaSenhaControle;
            std::cout << "\nDigite a nova senha: ";
            std::cin >> novaSenhaControle;
            try {
                Senha novaSenha;
                novaSenha.setSenha(novaSenhaControle);
                Pessoa p;
                p.setEmail(email);
                p.setSenha(novaSenha);
                
                if (servicoPessoas->atualizar(p)) {
                    std::cout << "\n[Sucesso] Senha atualizada com sucesso!\n";
                } else {
                    std::cout << "\n[Erro] Falha ao atualizar dados.\n";
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        } 
        else if (opcao == 3) {
            char confirmacao;
            std::cout << "\nAVISO: Esta acao nao pode ser desfeita.\n";
            std::cout << "Deseja mesmo excluir a sua conta? (S/N): ";
            std::cin >> confirmacao;
            if (confirmacao == 'S' || confirmacao == 's') {
                if (servicoPessoas->excluir(email)) {
                    std::cout << "\n[Sucesso] Conta eliminada. Adeus!\n";
                    return false; // Conta excluída, forçar logout
                } else {
                    std::cout << "\n[Erro] Nao foi possivel excluir a conta.\n";
                }
            }
        } 
        else if (opcao == 0) {
            return true; // Voltar sem excluir a conta
        } 
        else {
            std::cout << "\nOpcao invalida.\n";
        }
    }
}