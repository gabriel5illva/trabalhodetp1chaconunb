#include "prioridade.hpp"
#include <string>
#include <stdexcept>

bool Prioridade::validar(string prioridade){
    return prioridade == "ALTA" ||
           prioridade == "MEDIA" ||
           prioridade == "BAIXA";
}

bool Prioridade::setPrioridade(string prioridade){
    if(!validar(prioridade))
        throw invalid_argument("Formato de Prioridade invalido.");
    this->prioridade = prioridade;
    return true;
}
