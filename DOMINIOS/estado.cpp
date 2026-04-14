#include "estado.hpp"
#include <string>

bool Estado::validar(string estado){
    return estado == "A FAZER" || estado == "FAZENDO" || estado == "FEITO";
}

bool Estado::setEstado(string estado){
    if(!validar(estado))
        return false;
    this->estado = estado;
    return true;
}
