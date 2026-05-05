#include "estado.hpp"
#include <string>
#include <stdexcept>

bool Estado::validar(string estado){
    return estado == "A FAZER" ||
           estado == "FAZENDO" ||
           estado == "FEITO";
}

bool Estado::setEstado(string estado){
    if(!validar(estado))
        throw invalid_argument("Formato de Estado invalido.");
    this->estado = estado;
    return true;
}
