#ifndef SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED
#define SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED

#include "../interfaces/IServicePlanoDeSprint.hpp"

/**
 * @class ServicoPlanoDeSprint
 * @brief Implementa os servicos relacionados a PlanoDeSprint.
 *
 * Esta classe realiza a interface IServicePlanoDeSprint e concentra
 * operacoes da camada de servico relacionadas a entidade PlanoDeSprint.
 */
class ServicoPlanoDeSprint : public IServicePlanoDeSprint {
public:
    /**
     * @brief Cria um novo plano de sprint.
     *
     * @param plano Objeto da entidade PlanoDeSprint.
     * @return true se a operacao for realizada com sucesso.
     */
    bool criar(const PlanoDeSprint &plano) override;

    /**
     * @brief Le um plano de sprint a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return Objeto da entidade PlanoDeSprint.
     */
    PlanoDeSprint ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Objeto da entidade PlanoDeSprint.
     * @return true se a operacao for realizada com sucesso.
     */
    bool atualizar(const PlanoDeSprint &plano) override;

    /**
     * @brief Exclui um plano de sprint a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return true se a operacao for realizada com sucesso.
     */
    bool excluir(const Codigo &codigo) override;
};

#endif
