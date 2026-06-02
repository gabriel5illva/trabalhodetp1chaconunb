#ifndef ISERVICO_REQUISITOS_HPP_INCLUDED
#define ISERVICO_REQUISITOS_HPP_INCLUDED

#include "../ENTIDADES/HistoriaDeUsuario.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Estado.hpp"

/**
 * @class IServicoRequisitos
 * @brief Interface de servi&ccedil;o para as opera&ccedil;&otilde;es relacionadas a requisitos.
 *
 * Esta interface define o contrato que deve ser provido pelo M&oacute;dulo Servi&ccedil;o Requisitos.
 * No contexto do sistema, os requisitos s&atilde;o representados por hist&oacute;rias de usu&aacute;rio.
 *
 * A interface concentra opera&ccedil;&otilde;es de cria&ccedil;&atilde;o, leitura, atualiza&ccedil;&atilde;o,
 * exclus&atilde;o, associa&ccedil;&atilde;o, listagem, movimenta&ccedil;&atilde;o e altera&ccedil;&atilde;o de estado
 * de hist&oacute;rias de usu&aacute;rio.
 */
class IServicoRequisitos {
public:
    /**
     * @brief Cria uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;

    /**
     * @brief L&ecirc; uma hist&oacute;ria de usu&aacute;rio a partir do c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @return Entidade HistoriaDeUsuario encontrada.
     */
    virtual HistoriaDeUsuario lerHistoriaDeUsuario(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario com os dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) = 0;

    /**
     * @brief Exclui uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigo C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluirHistoriaDeUsuario(const Codigo &codigo) = 0;

    /**
     * @brief Estabelece associa&ccedil;&atilde;o entre hist&oacute;ria de usu&aacute;rio e pessoa.
     *
     * @param codigoHistoria C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

    /**
     * @brief Remove associa&ccedil;&atilde;o entre hist&oacute;ria de usu&aacute;rio e pessoa.
     *
     * @param codigoHistoria C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool removerPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um projeto.
     *
     * @param codigoProjeto C&oacute;digo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarHistoriasPorProjeto(const Codigo &codigoProjeto) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um plano de sprint.
     *
     * @param codigoPlano C&oacute;digo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarHistoriasPorPlanoDeSprint(const Codigo &codigoPlano) = 0;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a uma pessoa.
     *
     * @param emailPessoa Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarHistoriasPorPessoa(const Email &emailPessoa) = 0;

    /**
     * @brief Move uma hist&oacute;ria de usu&aacute;rio de um projeto para um plano de sprint.
     *
     * @param codigoHistoria C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param codigoProjeto C&oacute;digo que identifica o projeto.
     * @param codigoPlano C&oacute;digo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool moverParaPlanoDeSprint(const Codigo &codigoHistoria,
                                        const Codigo &codigoProjeto,
                                        const Codigo &codigoPlano) = 0;

    /**
     * @brief Altera o estado de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigoHistoria C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param estado Novo estado da hist&oacute;ria de usu&aacute;rio.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool alterarEstado(const Codigo &codigoHistoria, const Estado &estado) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicoRequisitos() {}
};

#endif
