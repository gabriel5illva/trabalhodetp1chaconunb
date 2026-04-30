#ifndef SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED
#define SERVICO_PLANO_DE_SPRINT_HPP_INCLUDED

#include "../interfaces/IServicePlanoDeSprint.hpp"

class ServicoPlanoDeSprint : public IServicePlanoDeSprint {
public:
    bool criar(const PlanoDeSprint &) override;
    PlanoDeSprint ler(const Codigo &) override;
    bool atualizar(const PlanoDeSprint &) override;
    bool excluir(const Codigo &) override;
};

#endif
