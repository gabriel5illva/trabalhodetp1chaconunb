#ifndef SERVICO_PROJETOS_HPP_INCLUDED
#define SERVICO_PROJETOS_HPP_INCLUDED

#include "../INTERFACES/IServicoProjetos.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerPlanoDeSprint.hpp"

/**
 * @class ServicoProjetos
 * @brief Implementa os servi&ccedil;os relacionados a projetos e planos de sprint.
 *
 * Esta classe realiza a interface IServicoProjetos e utiliza cont&ecirc;ineres
 * para armazenar projetos e planos de sprint em mem&oacute;ria.
 */
class ServicoProjetos : public IServicoProjetos {
private:
    ContainerProjeto *containerProjeto;
    ContainerPlanoDeSprint *containerPlanoDeSprint;

public:
    /**
     * @brief Inicializa os ponteiros dos cont&ecirc;ineres como nulos.
     */
    ServicoProjetos();

    /**
     * @brief Define o cont&ecirc;iner de projetos utilizado pelo servi&ccedil;o.
     *
     * @param containerProjeto Ponteiro para ContainerProjeto.
     */
    void setContainerProjeto(ContainerProjeto *containerProjeto);

    /**
     * @brief Define o cont&ecirc;iner de planos de sprint utilizado pelo servi&ccedil;o.
     *
     * @param containerPlanoDeSprint Ponteiro para ContainerPlanoDeSprint.
     */
    void setContainerPlanoDeSprint(ContainerPlanoDeSprint *containerPlanoDeSprint);

    /**
     * @brief Cria um novo projeto no sistema.
     *
     * @param projeto Entidade Projeto a ser cadastrada.
     * @return true se o projeto for cadastrado com sucesso.
     */
    bool criarProjeto(const Projeto &projeto) override;

    /**
     * @brief Consulta um projeto pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo do projeto a ser consultado.
     * @return Entidade Projeto encontrada.
     */
    Projeto lerProjeto(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um projeto cadastrado.
     *
     * @param projeto Entidade Projeto com os dados atualizados.
     * @return true se o projeto for atualizado com sucesso.
     */
    bool atualizarProjeto(const Projeto &projeto) override;

    /**
     * @brief Exclui um projeto cadastrado.
     *
     * @param codigo C&oacute;digo do projeto a ser exclu&iacute;do.
     * @return true se o projeto for exclu&iacute;do com sucesso.
     */
    bool excluirProjeto(const Codigo &codigo) override;

    /**
     * @brief Lista os projetos associados a uma pessoa.
     *
     * @param email Email da pessoa associada aos projetos.
     * @return true se houver projetos associados &agrave; pessoa.
     */
    bool listarProjetosPorPessoa(const Email &email) override;

    /**
     * @brief Cria um novo plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint a ser cadastrada.
     * @return true se o plano de sprint for cadastrado com sucesso.
     */
    bool criarPlanoDeSprint(const PlanoDeSprint &plano) override;

    /**
     * @brief Consulta um plano de sprint pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo do plano de sprint a ser consultado.
     * @return Entidade PlanoDeSprint encontrada.
     */
    PlanoDeSprint lerPlanoDeSprint(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint com os dados atualizados.
     * @return true se o plano de sprint for atualizado com sucesso.
     */
    bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) override;

    /**
     * @brief Exclui um plano de sprint.
     *
     * @param codigo C&oacute;digo do plano de sprint a ser exclu&iacute;do.
     * @return true se o plano de sprint for exclu&iacute;do com sucesso.
     */
    bool excluirPlanoDeSprint(const Codigo &codigo) override;

    /**
     * @brief Lista os planos de sprint associados a um projeto.
     *
     * @param codigoProjeto C&oacute;digo do projeto associado aos planos de sprint.
     * @return true se houver planos de sprint associados ao projeto.
     */
    bool listarPlanosPorProjeto(const Codigo &codigoProjeto) override;
};

#endif
