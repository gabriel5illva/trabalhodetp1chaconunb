#include "../../Headers/servicos/ServicoPlanoDeSprint.hpp"

bool ServicoPlanoDeSprint::criar(const PlanoDeSprint &) {
    return true;
}

PlanoDeSprint ServicoPlanoDeSprint::ler(const Codigo &) {
    PlanoDeSprint plano;
    return plano;
}

bool ServicoPlanoDeSprint::atualizar(const PlanoDeSprint &) {
    return true;
}

bool ServicoPlanoDeSprint::excluir(const Codigo &) {
    return true;
}
