#include "../../Headers/entidades/PlanoDeSprint.hpp"

void PlanoDeSprint::setCodigo(const Codigo &codigo) {
    this->codigo = codigo;
}

Codigo PlanoDeSprint::getCodigo() const {
    return codigo;
}

void PlanoDeSprint::setObjetivo(const Texto &objetivo) {
    this->objetivo = objetivo;
}

Texto PlanoDeSprint::getObjetivo() const {
    return objetivo;
}

void PlanoDeSprint::setCapacidade(const Tempo &capacidade) {
    this->capacidade = capacidade;
}

Tempo PlanoDeSprint::getCapacidade() const {
    return capacidade;
}
