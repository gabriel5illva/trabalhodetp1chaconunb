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
 * Esta classe armazena os dados b&aacute;sicos de uma pessoa,
 * incluindo email, nome, senha e papel no projeto.
 *
 * Cada atributo da entidade Pessoa &eacute; representado por uma
 * classe de dom&iacute;nio.
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
     * @param email Objeto da classe de dom&iacute;nio Email.
     */
    void setEmail(const Email &);

    /**
     * @brief Retorna o email da pessoa.
     *
     * @return Objeto da classe de dom&iacute;nio Email.
     */
    Email getEmail() const;

    /**
     * @brief Define o nome da pessoa.
     *
     * @param nome Objeto da classe de dom&iacute;nio Nome.
     */
    void setNome(const Nome &);

    /**
     * @brief Retorna o nome da pessoa.
     *
     * @return Objeto da classe de dom&iacute;nio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a senha da pessoa.
     *
     * @param senha Objeto da classe de dom&iacute;nio Senha.
     */
    void setSenha(const Senha &);

    /**
     * @brief Retorna a senha da pessoa.
     *
     * @return Objeto da classe de dom&iacute;nio Senha.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel da pessoa no projeto.
     *
     * @param papel Objeto da classe de dom&iacute;nio Papel.
     */
    void setPapel(const Papel &);

    /**
     * @brief Retorna o papel da pessoa no projeto.
     *
     * @return Objeto da classe de dom&iacute;nio Papel.
     */
    Papel getPapel() const;
};

#endif
