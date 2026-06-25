#include "CntrApresentacaoAutenticacao.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

void CntrApresentacaoAutenticacao::setServicoAutenticacao(IServicoAutenticacao *servico) {
    this->servicoAutenticacao = servico;
}

bool CntrApresentacaoAutenticacao::autenticar(Email &email) {
    std::string entradaEmail, entradaSenha;

    while (true) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "              TELA DE LOGIN              \n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Digite seu e-mail (ou '0' para voltar): ";
        std::cin >> entradaEmail;

        if (entradaEmail == "0") return false;

        std::cout << "Digite sua senha: ";
        std::cin >> entradaSenha;

        try {
            Email objEmail;
            objEmail.setEmail(entradaEmail); 
            Senha objSenha;
            objSenha.setSenha(entradaSenha);

            if (servicoAutenticacao->autenticar(objEmail, objSenha)) {
                std::cout << "\nAutenticacao realizada com sucesso!\n";
                email = objEmail;
                return true;
            } else {
                std::cout << "\n[Falha] E-mail ou senha incorretos.\n";
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "\n[Erro de Formato] " << e.what() << "\n";
        }
    }
}