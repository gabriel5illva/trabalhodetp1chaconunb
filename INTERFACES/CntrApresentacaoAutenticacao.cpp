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

        email.setEmail(textoEmail);
        senha.setSenha(textoSenha);

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
    Nome nome;

    try {
        nome.setNome(textoNome);
    }
    catch (const invalid_argument& e) {
        cout << "\nErro: " << e.what() << endl;
        return;
    }

    cout << "Email: ";
    getline(cin, textoEmail);
    Email email;

    try {
        email.setEmail(textoEmail);
    }
    catch (const invalid_argument& e) {
        cout << "\nErro: " << e.what() << endl;
        return;
    }

    cout << "Senha: ";
    getline(cin, textoSenha);
    Senha senha;

    try {
        senha.setSenha(textoSenha);
    }
    catch (const invalid_argument& e) {
        cout << "\nErro: " << e.what() << endl;
        return;
    }

    try {
        textoPapel = selecionarPapel();
    }
    catch (const invalid_argument& e) {
        cout << "\nErro: " << e.what() << endl;
        return;
    }

    Papel papel;
    papel.setPapel(textoPapel);

    bool cadastrado =
    ponteiroServico->cadastrar(
        email,
        senha,
        nome,
        papel
        );

    if(cadastrado){
            cout << "\nCadastro realizado com sucesso" << endl;
    }
    else{
        cout << "\nNao foi possivel realizar o cadastro" << endl;
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

string CntrApresentacaoAutenticacao::selecionarPapel() {
    int opcao;

    cout << "\nPapel:" << endl;
    cout << "1 - DESENVOLVEDOR" << endl;
    cout << "2 - MESTRE SCRUM" << endl;
    cout << "3 - PROPRIETARIO DE PRODUTO" << endl;
    cout << "Opcao: ";

    cin >> opcao;

    switch (opcao) {
        case 1:
            return "DESENVOLVEDOR";

        case 2:
            return "MESTRE SCRUM";

        case 3:
            return "PROPRIETARIO DE PRODUTO";

        default:
            throw invalid_argument("Papel invalido");
    }
}
