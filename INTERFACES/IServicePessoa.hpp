#ifndef ISERVICE_PESSOA_HPP_INCLUDED
#define ISERVICE_PESSOA_HPP_INCLUDED

#include "../entidades/Pessoa.hpp"

/**
 * @class IServicePessoa
 * @brief Interface abstrata para os servi&ccedil;os relacionados a Pessoa.
 *
 * Esta interface declara as opera&ccedil;&otilde;es de cria&ccedil;&atilde;o, leitura,
 * atualiza&ccedil;&atilde;o e exclus&atilde;o de pessoas.
 */
class IServicePessoa {
public:
    /**
     * @brief Cria uma pessoa.
     *
     * @param pessoa Entidade Pessoa a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criar(const Pessoa &pessoa) = 0;

    /**
     * @brief L&ecirc; uma pessoa a partir do email.
     *
     * @param email Email que identifica a pessoa.
     * @return Entidade Pessoa encontrada.
     */
    virtual Pessoa ler(const Email &email) = 0;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param pessoa Entidade Pessoa com dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizar(const Pessoa &pessoa) = 0;

    /**
     * @brief Exclui uma pessoa.
     *
     * @param email Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluir(const Email &email) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicePessoa() {}
};

#endif
