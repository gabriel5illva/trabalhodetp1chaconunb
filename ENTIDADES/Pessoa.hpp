#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Papel.hpp"

/**
 * @class Pessoa
 * @brief Representa uma pessoa cadastrada no sistema.
 *
 * A classe Pessoa armazena os dados básicos de um usuário do sistema,
 * incluindo email, nome, senha e papel no projeto.
 *
 * Cada atributo da entidade Pessoa é representado por uma classe de domínio,
 * conforme a estrutura exigida no trabalho.
 */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:
    /**
     * @brief Define o email da pessoa.
     *
     * @param email Objeto da classe de domínio Email.
     */
    void setEmail(const Email &);

    /**
     * @brief Retorna o email da pessoa.
     *
     * @return Objeto da classe de domínio Email.
     */
    Email getEmail() const;

    /**
     * @brief Define o nome da pessoa.
     *
     * @param nome Objeto da classe de domínio Nome.
     */
    void setNome(const Nome &);

    /**
     * @brief Retorna o nome da pessoa.
     *
     * @return Objeto da classe de domínio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a senha da pessoa.
     *
     * @param senha Objeto da classe de domínio Senha.
     */
    void setSenha(const Senha &);

    /**
     * @brief Retorna a senha da pessoa.
     *
     * @return Objeto da classe de domínio Senha.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel da pessoa no projeto.
     *
     * @param papel Objeto da classe de domínio Papel.
     */
    void setPapel(const Papel &);

    /**
     * @brief Retorna o papel da pessoa no projeto.
     *
     * @return Objeto da classe de domínio Papel.
     */
    Papel getPapel() const;
};

#endif
