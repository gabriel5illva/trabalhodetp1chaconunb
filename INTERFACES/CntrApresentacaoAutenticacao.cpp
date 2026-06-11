#include "CntrApresentacaoAutenticacao.hpp"

#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Senha.hpp"
#include "../DOMINIOS/Nome.hpp"
#include "../DOMINIOS/Papel.hpp"


#include<iostream>
#include<string>
#include <limits>

using namespace std;

void CntrApresentacaoAutenticacao::autenticar(
    IServicoAutenticacao* ponteiroServico
) {
    string textoEmail;
    string textoSenha;

    cout << "\n=== LOGIN ===" << endl;

    cout << "Email: ";
    cin >> textoEmail;

    cout << "Senha: ";
    cin >> textoSenha;

    try {
        Email email;
        Senha senha;

        email.setValor(textoEmail);
        senha.setValor(textoSenha);

        bool autenticado =
            ponteiroServico->autenticar(
                email,
                senha
            );

        if (autenticado) {
            cout << "\nLogin realizado com sucesso." << endl;
        }
        else {
            cout << "\nEmail ou senha incorretos." << endl;
        }
    }
    catch (...) {
        cout << "\nDados invalidos." << endl;
    }
}

void CntrApresentacaoAutenticacao::cadastrar(
    IServicoAutenticacao* ponteiroServico
) {
    string textoNome;
    string textoEmail;
    string textoSenha;
    string textoPapel;

    cout << "\n=== CADASTRO ===" << endl;

    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, textoNome);

    cout << "Email: ";
    getline(cin, textoEmail);

    cout << "Senha: ";
    getline(cin, textoSenha);

    cout << "Papel: ";
    getline(cin, textoPapel);

    try {
        Nome nome;
        Email email;
        Senha senha;
        Papel papel;

        nome.setValor(textoNome);
        email.setValor(textoEmail);
        senha.setValor(textoSenha);
        papel.setValor(textoPapel);

        bool cadastrado =
            ponteiroServico->cadastrar(
                email,
                senha,
                nome,
                papel
            );

        if (cadastrado) {
            cout << "\nCadastro realizado com sucesso." << endl;
        }
        else {
            cout << "\nNao foi possivel realizar o cadastro." << endl;
        }
    }
    catch (...) {
        cout << "\nDados invalidos." << endl;
    }
}

void CntrApresentacaoAutenticacao::executar(
    IServicoAutenticacao* ponteiroServico
) {
    int opcao;

    do {
        cout << "\n=================================" << endl;
        cout << "          AUTENTICACAO           " << endl;
        cout << "=================================" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Cadastrar" << endl;
        cout << "0 - Sair" << endl;
        cout << "\nOpcao: ";

        cin >> opcao;

        switch (opcao) {
            case 1:
                autenticar(ponteiroServico);
                break;

            case 2:
                cadastrar(ponteiroServico);
                break;

            case 0:
                cout << "\nEncerrando..." << endl;
                break;

            default:
                cout << "\nOpcao invalida." << endl;
        }

    } while (opcao != 0);
}
