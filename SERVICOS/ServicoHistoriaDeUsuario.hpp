#ifndef SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../INTERFACES/IServicoHistoriaDeUsuario.hpp"
#include "ContainerHistoriaDeUsuario.hpp"

/**
 * @class ServicoHistoriaDeUsuario
 * @brief Implementa os servi&ccedil;os relacionados a hist&oacute;rias de usu&aacute;rio.
 *
 * Esta classe realiza a interface IServicoHistoriaDeUsuario e utiliza
 * ContainerHistoriaDeUsuario para armazenar e manipular hist&oacute;rias de
 * usu&aacute;rio cadastradas no sistema.
 */
class ServicoHistoriaDeUsuario : public IServicoHistoriaDeUsuario {
private:
    ContainerHistoriaDeUsuario *containerHistoriaDeUsuario;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoHistoriaDeUsuario();

    /**
     * @brief Define o cont&ecirc;iner de hist&oacute;rias de usu&aacute;rio utilizado pelo servi&ccedil;o.
     *
     * @param containerHistoriaDeUsuario Ponteiro para ContainerHistoriaDeUsuario.
     */
    void setContainerHistoriaDeUsuario(ContainerHistoriaDeUsuario *containerHistoriaDeUsuario);

    /**
     * @brief Cria uma nova hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario a ser cadastrada.
     * @return true se a hist&oacute;ria for cadastrada com sucesso.
     */
    bool criar(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Consulta uma hist&oacute;ria de usu&aacute;rio pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @return Entidade HistoriaDeUsuario encontrada.
     */
    HistoriaDeUsuario ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario com os dados atualizados.
     * @return true se a hist&oacute;ria for atualizada com sucesso.
     */
    bool atualizar(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Exclui uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigo C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @return true se a hist&oacute;ria for exclu&iacute;da com sucesso.
     */
    bool excluir(const Codigo &codigo) override;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um projeto.
     *
     * @param codigoProjeto C&oacute;digo do projeto.
     * @return true se houver hist&oacute;rias cadastradas.
     */
    bool listarPorProjeto(const Codigo &codigoProjeto) override;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um plano de sprint.
     *
     * @param codigoPlano C&oacute;digo do plano de sprint.
     * @return true se houver hist&oacute;rias cadastradas.
     */
    bool listarPorPlanoDeSprint(const Codigo &codigoPlano) override;
};

#endif
