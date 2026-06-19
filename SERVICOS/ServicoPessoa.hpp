#ifndef SERVICO_PESSOA_HPP_INCLUDED
#define SERVICO_PESSOA_HPP_INCLUDED

#include"../SQLite/sqlite3.h"
#include "../INTERFACES/IServicoAutenticacao.hpp"
#include <string>

// Estrutura mantida para o método de leitura (Read)
struct EntidadePessoa {
    Nome nome;
    Email email;
    Senha senha;
    Papel papel;
};

class ServicoPessoa : public IServicoAutenticacao {
private:
    sqlite3* db;
    const std::string nomeBanco = "sistema.db";

    // Método auxiliar para abrir o banco e criar a tabela se não existir
    bool inicializarBanco();

public:
    ServicoPessoa();
    ~ServicoPessoa();

    // --- Métodos herdados de IServicoAutenticacao ---
    bool autenticar(const Email &email, const Senha &senha) override;
    bool cadastrar(const Email &email, const Senha &senha, const Nome &nome, const Papel &papel) override;

    // --- Métodos do CRUD para a entidade Pessoa ---
    bool criarPessoa(const Nome &nome, const Email &email, const Senha &senha, const Papel &papel);
    bool lerPessoa(const Email &email, EntidadePessoa &pessoaRetorno);
    bool editarPessoa(const Email &email, const Nome &novoNome, const Senha &novaSenha, const Papel &novoPapel);
    bool excluirPessoa(const Email &email);
};

#endif // SERVICO_PESSOA_HPP_INCLUDED
