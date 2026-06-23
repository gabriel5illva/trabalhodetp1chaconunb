#ifndef SERVICO_REQUISITOS_HPP_INCLUDED
#define SERVICO_REQUISITOS_HPP_INCLUDED

#include <vector>

#include "../INTERFACES/IServicoRequisitos.hpp"

#include "ContainerHistoriaDeUsuario.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerPlanoDeSprint.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class ServicoRequisitos
 * @brief Implementa os servi&ccedil;os relacionados a hist&oacute;rias de usu&aacute;rio.
 *
 * Esta classe realiza a interface IServicoRequisitos e utiliza cont&ecirc;ineres
 * para armazenar hist&oacute;rias de usu&aacute;rio e controlar associa&ccedil;&otilde;es simples
 * entre hist&oacute;rias, pessoas, projetos e planos de sprint.
 */
class ServicoRequisitos : public IServicoRequisitos {
private:
    /**
     * @struct AssociacaoHistoriaPessoa
     * @brief Representa a associa&ccedil;&atilde;o entre uma hist&oacute;ria de usu&aacute;rio e uma pessoa.
     */
    struct AssociacaoHistoriaPessoa {
        Codigo codigoHistoria;
        Email emailPessoa;
    };

    /**
     * @struct AssociacaoHistoriaProjeto
     * @brief Representa a associa&ccedil;&atilde;o entre uma hist&oacute;ria de usu&aacute;rio e um projeto.
     */
    struct AssociacaoHistoriaProjeto {
        Codigo codigoHistoria;
        Codigo codigoProjeto;
    };

    /**
     * @struct AssociacaoHistoriaPlano
     * @brief Representa a associa&ccedil;&atilde;o entre uma hist&oacute;ria de usu&aacute;rio e um plano de sprint.
     */
    struct AssociacaoHistoriaPlano {
        Codigo codigoHistoria;
        Codigo codigoPlano;
    };

    ContainerHistoriaDeUsuario *containerHistoriaDeUsuario;
    ContainerProjeto *containerProjeto;
    ContainerPlanoDeSprint *containerPlanoDeSprint;
    ContainerPessoa *containerPessoa;

    std::vector<AssociacaoHistoriaPessoa> associacoesPessoa;
    std::vector<AssociacaoHistoriaProjeto> associacoesProjeto;
    std::vector<AssociacaoHistoriaPlano> associacoesPlano;

public:
    /**
     * @brief Inicializa os ponteiros dos cont&ecirc;ineres como nulos.
     */
    ServicoRequisitos();

    /**
     * @brief Define o cont&ecirc;iner de hist&oacute;rias de usu&aacute;rio.
     *
     * @param containerHistoriaDeUsuario Ponteiro para ContainerHistoriaDeUsuario.
     */
    void setContainerHistoriaDeUsuario(ContainerHistoriaDeUsuario *containerHistoriaDeUsuario);

    /**
     * @brief Define o cont&ecirc;iner de projetos.
     *
     * @param containerProjeto Ponteiro para ContainerProjeto.
     */
    void setContainerProjeto(ContainerProjeto *containerProjeto);

    /**
     * @brief Define o cont&ecirc;iner de planos de sprint.
     *
     * @param containerPlanoDeSprint Ponteiro para ContainerPlanoDeSprint.
     */
    void setContainerPlanoDeSprint(ContainerPlanoDeSprint *containerPlanoDeSprint);

    /**
     * @brief Define o cont&ecirc;iner de pessoas.
     *
     * @param containerPessoa Ponteiro para ContainerPessoa.
     */
    void setContainerPessoa(ContainerPessoa *containerPessoa);

    /**
     * @brief Cria uma nova hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario a ser cadastrada.
     * @return true se a hist&oacute;ria de usu&aacute;rio for cadastrada com sucesso.
     */
    bool criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Consulta uma hist&oacute;ria de usu&aacute;rio pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @return Entidade HistoriaDeUsuario encontrada.
     */
    HistoriaDeUsuario lerHistoriaDeUsuario(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario com os dados atualizados.
     * @return true se a hist&oacute;ria de usu&aacute;rio for atualizada com sucesso.
     */
    bool atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Exclui uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigo C&oacute;digo da hist&oacute;ria de usu&aacute;rio a ser exclu&iacute;da.
     * @return true se a hist&oacute;ria de usu&aacute;rio for exclu&iacute;da com sucesso.
     */
    bool excluirHistoriaDeUsuario(const Codigo &codigo) override;

    /**
     * @brief Associa uma pessoa a uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigoHistoria C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email da pessoa a ser associada.
     * @return true se a associa&ccedil;&atilde;o for realizada com sucesso.
     */
    bool associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;

    /**
     * @brief Remove a associa&ccedil;&atilde;o entre uma pessoa e uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigoHistoria C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @param emailPessoa Email da pessoa a ser removida da associa&ccedil;&atilde;o.
     * @return true se a associa&ccedil;&atilde;o for removida com sucesso.
     */
    bool removerPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um projeto.
     *
     * @param codigoProjeto C&oacute;digo do projeto.
     * @return true se houver hist&oacute;rias associadas ao projeto.
     */
    bool listarHistoriasPorProjeto(const Codigo &codigoProjeto) override;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a um plano de sprint.
     *
     * @param codigoPlano C&oacute;digo do plano de sprint.
     * @return true se houver hist&oacute;rias associadas ao plano de sprint.
     */
    bool listarHistoriasPorPlanoDeSprint(const Codigo &codigoPlano) override;

    /**
     * @brief Lista hist&oacute;rias de usu&aacute;rio associadas a uma pessoa.
     *
     * @param emailPessoa Email da pessoa.
     * @return true se houver hist&oacute;rias associadas &agrave; pessoa.
     */
    bool listarHistoriasPorPessoa(const Email &emailPessoa) override;

    /**
     * @brief Move uma hist&oacute;ria de usu&aacute;rio de um projeto para um plano de sprint.
     *
     * @param codigoHistoria C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @param codigoProjeto C&oacute;digo do projeto de origem.
     * @param codigoPlano C&oacute;digo do plano de sprint de destino.
     * @return true se a movimenta&ccedil;&atilde;o for realizada com sucesso.
     */
    bool moverParaPlanoDeSprint(const Codigo &codigoHistoria,
                                const Codigo &codigoProjeto,
                                const Codigo &codigoPlano) override;

    /**
     * @brief Altera o estado de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigoHistoria C&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     * @param estado Novo estado da hist&oacute;ria de usu&aacute;rio.
     * @return true se o estado for alterado com sucesso.
     */
    bool alterarEstado(const Codigo &codigoHistoria, const Estado &estado) override;
};

#endif
