#include "papel.hpp"
#include <string>
#include <stdexcept>

bool Papel::validar(string papel){
    return papel == "DESENVOLVEDOR" ||
           papel == "MESTRE SCRUM" ||
           papel == "PROPRIETARIO DE PRODUTO";
}

bool Papel::setPapel(string papel){
    if(!validar(papel))
        throw invalid_argument("Formato de Papel invalido.");
    this->papel = papel;
    return true;
}
