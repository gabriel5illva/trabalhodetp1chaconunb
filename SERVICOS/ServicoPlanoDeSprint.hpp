#ifndef SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED
#define SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED

#include "../INTERFACES/IServicoPlanoDeSprint.hpp"
#include "ContainerPlanoDeSprint.hpp"

/**
 * @class ServicoPlanoDeSprint
 * @brief Implementa os servi&ccedil;os relacionados a planos de sprint.
 *
 * Esta classe realiza a interface IServicoPlanoDeSprint e utiliza
 * ContainerPlanoDeSprint para armazenar e manipular planos de sprint
 * cadastrados no sistema.
 */
class ServicoPlanoDeSprint : public IServicoPlanoDeSprint {
private:
    ContainerPlanoDeSprint *containerPlanoDeSprint;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoPlanoDeSprint();

    /**
     * @brief Define o cont&ecirc;iner de planos de sprint utilizado pelo servi&ccedil;o.
     *
     * @param containerPlanoDeSprint Ponteiro para ContainerPlanoDeSprint.
     */
    void setContainerPlanoDeSprint(ContainerPlanoDeSprint *containerPlanoDeSprint);

    /**
     * @brief Cria um novo plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint a ser cadastrada.
     * @return true se o plano de sprint for cadastrado com sucesso.
     */
    bool criar(const PlanoDeSprint &plano) override;

    /**
     * @brief Consulta um plano de sprint pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo do plano de sprint.
     * @return Entidade PlanoDeSprint encontrada.
     */
    PlanoDeSprint ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint com os dados atualizados.
     * @return true se o plano de sprint for atualizado com sucesso.
     */
    bool atualizar(const PlanoDeSprint &plano) override;

    /**
     * @brief Exclui um plano de sprint.
     *
     * @param codigo C&oacute;digo do plano de sprint.
     * @return true se o plano de sprint for exclu&iacute;do com sucesso.
     */
    bool excluir(const Codigo &codigo) override;

    /**
     * @brief Lista planos de sprint associados a um projeto.
     *
     * @param codigoProjeto C&oacute;digo do projeto.
     * @return true se houver planos de sprint cadastrados.
     */
    bool listarPorProjeto(const Codigo &codigoProjeto) override;
};

#endif /** SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED planos de sprint associados a um projeto.
        *
        * @param codigoProjeto C&oacute;digo do projeto.
        */
