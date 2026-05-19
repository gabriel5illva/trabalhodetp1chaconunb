#ifndef ISERVICE_PROJETO_HPP_INCLUDED
#define ISERVICE_PROJETO_HPP_INCLUDED

#include "../entidades/Projeto.hpp"
#include "../dominios/Email.hpp"

/**
 * @class IServiceProjeto
 * @brief Interface abstrata para os servi&ccedil;os relacionados a Projeto.
 *
 * Esta interface declara as opera&ccedil;&otilde;es de cria&ccedil;&atilde;o, leitura,
 * atualiza&ccedil;&atilde;o, exclus&atilde;o e listagem de projetos.
 */
class IServiceProjeto {
public:
    /**
     * @brief Cria um projeto.
     *
     * @param projeto Entidade Projeto a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criar(const Projeto &projeto) = 0;

    /**
     * @brief L&ecirc; um projeto a partir do c&oacute;digo.
     *
     * @param codigo Codigo que identifica o projeto.
     * @return Entidade Projeto encontrada.
     */
    virtual Projeto ler(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Entidade Projeto com dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizar(const Projeto &projeto) = 0;

    /**
     * @brief Exclui um projeto.
     *
     * @param codigo Codigo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluir(const Codigo &codigo) = 0;

    /**
     * @brief Lista projetos associados a uma pessoa.
     *
     * @param email Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPorPessoa(const Email &email) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServiceProjeto() {}
};

#endif
