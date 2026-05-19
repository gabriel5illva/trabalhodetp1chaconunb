#ifndef ISERVICE_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define ISERVICE_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../entidades/HistoriaDeUsuario.hpp"
#include "../dominios/Codigo.hpp"
#include "../dominios/Email.hpp"
#include "../dominios/Estado.hpp"

/**
 * @class IServiceHistoriaDeUsuario
 * @brief Interface abstrata para os servi&ccedil;os relacionados a HistoriaDeUsuario.
 *
 * Esta interface declara as opera&ccedil;&otilde;es de cria&ccedil;&atilde;o, leitura,
 * atualiza&ccedil;&atilde;o, exclus&atilde;o, associa&ccedil;&atilde;o, listagem, movimenta&ccedil;&atilde;o
 * e altera&ccedil;&atilde;o de estado de hist&oacute;rias de usu&aacute;rio.
 */
class IServiceHistoriaDeUsuario {
public:
    /**
     * @brief Cria uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criar(const HistoriaDeUsuario &historia) = 0;

    /**
     * @brief L&ecirc; uma hist&oacute;ria de usu&aacute;rio a partir do c&oacute;digo.
     *
     * @param codigo Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @return Entidade HistoriaDeUsuario encontrada.
     */
    virtual HistoriaDeUsuario ler(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario com dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizar(const HistoriaDeUsuario &historia) = 0;

    /**
     * @brief Exclui uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigo Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluir(const Codigo &codigo) = 0;

    /**
     * @brief Estabelece associa&ccedil;&atilde;o entre hist&oacute;ria de usu&aacute;rio e pessoa.
     *
     * @param codigoHistoria Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

    /**
     * @brief Remove associa&ccedil;&atilde;o entre hist&oacute;ria de usu&aacute;rio e pessoa.
     *
     * @param codigoHistoria Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool removerPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um projeto.
     *
     * @param codigoProjeto Codigo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPorProjeto(const Codigo &codigoProjeto) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um plano de sprint.
     *
     * @param codigoPlano Codigo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPorPlanoDeSprint(const Codigo &codigoPlano) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a uma pessoa.
     *
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPorPessoa(const Email &emailPessoa) = 0;

    /**
     * @brief Move hist&oacute;ria de usu&aacute;rio de projeto para plano de sprint.
     *
     * @param codigoHistoria Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param codigoProjeto Codigo que identifica o projeto.
     * @param codigoPlano Codigo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool moverParaPlanoDeSprint(const Codigo &codigoHistoria,
                                        const Codigo &codigoProjeto,
                                        const Codigo &codigoPlano) = 0;

    /**
     * @brief Altera o estado de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigoHistoria Codigo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param estado Novo estado da hist&oacute;ria de usu&aacute;rio.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool alterarEstado(const Codigo &codigoHistoria, const Estado &estado) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServiceHistoriaDeUsuario() {}
};

#endif
