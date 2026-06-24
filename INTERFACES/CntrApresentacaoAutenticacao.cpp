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
        std::cout << "Digite seu e-mail (or '0' para voltar): ";
        std::cin >> entradaEmail;

        if (entradaEmail == "0") {
            return false; // Cancela a operação e volta para o menu da CntrApresentacaoControle
        }

        std::cout << "Digite sua senha: ";
        std::cin >> entradaSenha;

        try {
            Email objEmail;
            objEmail.setEmail(entradaEmail);
            Senha objSenha;
            objSenha.setSenha(entradaSenha);

            if (servicoAutenticacao == nullptr) {
                std::cout << "\n[Erro] Servico de autenticacao indisponivel.\n";
                return false;
            }

            if (servicoAutenticacao->autenticar(objEmail, objSenha)) {
                std::cout << "\nAutenticacao realizada com sucesso!\n";
                email = objEmail; // Define o e-mail da sessão
                return true;      // Retorna verdadeiro para a controladora principal liberar o acesso
            } else {
                std::cout << "\n[Falha] E-mail ou senha incorretos.\n";
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "\n[Erro de Formato] " << e.what() << "\n";
        }

        std::cout << "Pressione ENTER para tentar novamente...";
        std::cin.ignore();
        std::cin.get();
    }
}
