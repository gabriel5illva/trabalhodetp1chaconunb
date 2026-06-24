#include "ServicoPlanoDeSprint.hpp"

ServicoPlanoDeSprint::ServicoPlanoDeSprint() {
    containerPlanoDeSprint = nullptr;
}

void ServicoPlanoDeSprint::setContainerPlanoDeSprint(
    ContainerPlanoDeSprint *containerPlanoDeSprint
) {
    this->containerPlanoDeSprint = containerPlanoDeSprint;
}

bool ServicoPlanoDeSprint::criar(const PlanoDeSprint &plano) {
    if (containerPlanoDeSprint == nullptr) {
        return false;
    }

    return containerPlanoDeSprint->inserir(plano);
}

PlanoDeSprint ServicoPlanoDeSprint::ler(const Codigo &codigo) {
    PlanoDeSprint plano;

    if (containerPlanoDeSprint == nullptr) {
        return plano;
    }

    containerPlanoDeSprint->buscar(codigo, plano);

    return plano;
}

bool ServicoPlanoDeSprint::atualizar(const PlanoDeSprint &plano) {
    if (containerPlanoDeSprint == nullptr) {
        return false;
    }

    return containerPlanoDeSprint->atualizar(plano);
}

bool ServicoPlanoDeSprint::excluir(const Codigo &codigo) {
    if (containerPlanoDeSprint == nullptr) {
        return false;
    }

    return containerPlanoDeSprint->remover(codigo);
}

bool ServicoPlanoDeSprint::listarPorProjeto(const Codigo &codigoProjeto) {
    (void) codigoProjeto;

    if (containerPlanoDeSprint == nullptr) {
        return false;
    }

    return !containerPlanoDeSprint->listarTodos().empty();
}
