#include "ServicoPessoa.hpp"
#include <iostream>

ServicoPessoa::ServicoPessoa() {
    if (!inicializarBanco()) {
        std::cerr << "Erro fatal: Nao foi possivel inicializar o banco de dados." << std::endl;
    }
}

ServicoPessoa::~ServicoPessoa() {
    if (db) {
        sqlite3_close(db);
    }
}

bool ServicoPessoa::inicializarBanco() {
    int rc = sqlite3_open(nomeBanco.c_str(), &db);
    if (rc != SQLITE_OK) {
        return false;
    }

    // Cria a tabela usando o EMAIL como PRIMARY KEY (garante e-mails únicos)
    std::string sql = "CREATE TABLE IF NOT EXISTS pessoas ("
                      "email TEXT PRIMARY KEY, "
                      "senha TEXT NOT NULL, "
                      "nome TEXT NOT NULL, "
                      "papel TEXT NOT NULL);";

    char* mensagemErro = nullptr;
    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensagemErro);

    if (rc != SQLITE_OK) {
        sqlite3_free(mensagemErro);
        return false;
    }
    return true;
}

// --- Implementação dos métodos de IServicoAutenticacao ---

bool ServicoPessoa::autenticar(const Email &email, const Senha &senha) {
    std::string sql = "SELECT senha FROM pessoas WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    // Vincula o email na query
    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_STATIC);

    bool autenticado = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Extrai a senha criptografada/armazenada no banco
        std::string senhaBanco = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

        // Compara com a senha fornecida pelo usuário
        if (senhaBanco == senha.getSenha()) {
            autenticado = true; // Retorna 1
        }
    }

    sqlite3_finalize(stmt);
    return autenticado; // Se falhar ou não achar, retorna 0
}

bool ServicoPessoa::cadastrar(const Email &email, const Senha &senha, const Nome &nome, const Papel &papel) {
    return criarPessoa(nome, email, senha, papel);
}

// --- Implementação do CRUD de Pessoa ---

bool ServicoPessoa::criarPessoa(const Nome &nome, const Email &email, const Senha &senha, const Papel &papel) {
    std::string sql = "INSERT INTO pessoas (email, senha, nome, papel) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    // Vincula os parâmetros com segurança
    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, nome.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, papel.getPapel().c_str(), -1, SQLITE_STATIC);

    // SQLITE_DONE significa que o insert foi executado com sucesso
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return (rc == SQLITE_DONE); // Retorna falso se o e-mail já existir (violação de PRIMARY KEY)
}

bool ServicoPessoa::lerPessoa(const Email &email, EntidadePessoa &pessoaRetorno) {
    std::string sql = "SELECT nome, senha, papel FROM pessoas WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_STATIC);

    bool encontrado = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string txtNome  = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string txtSenha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string txtPapel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        // Alimenta o objeto de retorno usando os setters dos seus Domínios
        pessoaRetorno.email = email;
        pessoaRetorno.nome.setNome(txtNome);
        pessoaRetorno.senha.setSenha(txtSenha);
        pessoaRetorno.papel.setPapel(txtPapel);

        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}

bool ServicoPessoa::editarPessoa(const Email &email, const Nome &novoNome, const Senha &novaSenha, const Papel &novoPapel) {
    std::string sql = "UPDATE pessoas SET nome = ?, senha = ?, papel = ? WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, novoNome.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, novaSenha.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, novoPapel.getPapel().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, email.getEmail().c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    // Verifica se alguma linha foi de fato modificada
    return (rc == SQLITE_DONE && sqlite3_changes(db) > 0);
}

bool ServicoPessoa::excluirPessoa(const Email &email) {
    std::string sql = "DELETE FROM pessoas WHERE email = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.getEmail().c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    // Retorna verdadeiro se deletou o registro do banco
    return (rc == SQLITE_DONE && sqlite3_changes(db) > 0);
}
