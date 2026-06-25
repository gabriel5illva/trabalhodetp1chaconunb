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

std::vector<PlanoDeSprint> ServicoPlanoDeSprint::listarPorProjeto(const Codigo &codigoProjeto) {
    std::vector<PlanoDeSprint> sprintsFiltradas; // Vetor que iniciará vazio

    // Proteção de segurança caso o container em memória seja nulo
    if (containerPlanoDeSprint == nullptr) {
        return sprintsFiltradas;
    }

    // Obtém todos os planos de sprint salvos na memória
    std::vector<PlanoDeSprint> todasSprints = containerPlanoDeSprint->listarTodos();

    // Filtra adicionando ao vetor apenas as sprints que pertencem ao projeto informado
    for (const PlanoDeSprint &s : todasSprints) {
        if (s.getProjetoAssociado().getCodigo() == codigoProjeto.getCodigo()) {
            sprintsFiltradas.push_back(s);
        }
    }

    return sprintsFiltradas;
}
