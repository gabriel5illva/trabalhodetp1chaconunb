#ifndef SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED
#define SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED

#include "../interfaces/IServicePlanoDeSprint.hpp"

/**
 * @class ServicoPlanoDeSprint
 * @brief Implementa os servi&ccedil;os relacionados a PlanoDeSprint.
 *
 * Esta classe realiza a interface IServicePlanoDeSprint e concentra
 * opera&ccedil;&otilde;es da camada de servi&ccedil;o relacionadas &agrave; entidade PlanoDeSprint.
 */
class ServicoPlanoDeSprint : public IServicePlanoDeSprint {
public:
    bool criar(const PlanoDeSprint &plano) override;
    PlanoDeSprint ler(const Codigo &codigo) override;
    bool atualizar(const PlanoDeSprint &plano) override;
    bool excluir(const Codigo &codigo) override;
    bool listarPorProjeto(const Codigo &codigoProjeto) override;
};

#endif
