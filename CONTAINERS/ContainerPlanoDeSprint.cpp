#include "../../Headers/SERVICOS/ContainerPlanoDeSprint.hpp"

bool ContainerPlanoDeSprint::inserir(const PlanoDeSprint &plano) {
    PlanoDeSprint planoEncontrado;

    if (buscar(plano.getCodigo(), planoEncontrado)) {
        return false;
    }

    planos.push_back(plano);
    return true;
}

bool ContainerPlanoDeSprint::buscar(const Codigo &codigo, PlanoDeSprint &plano) {
    for (PlanoDeSprint p : planos) {
        if (p.getCodigo().getCodigo() == codigo.getCodigo()) {
            plano = p;
            return true;
        }
    }

    return false;
}

bool ContainerPlanoDeSprint::atualizar(const PlanoDeSprint &plano) {
    for (int i = 0; i < (int) planos.size(); i++) {
        if (planos[i].getCodigo().getCodigo() == plano.getCodigo().getCodigo()) {
            planos[i] = plano;
            return true;
        }
    }

    return false;
}

bool ContainerPlanoDeSprint::remover(const Codigo &codigo) {
    for (int i = 0; i < (int) planos.size(); i++) {
        if (planos[i].getCodigo().getCodigo() == codigo.getCodigo()) {
            planos.erase(planos.begin() + i);
            return true;
        }
    }

    return false;
}

std::vector<PlanoDeSprint> ContainerPlanoDeSprint::listarTodos() {
    return planos;
}
