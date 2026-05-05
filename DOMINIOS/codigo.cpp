#include "codigo.hpp"
#include <cctype>
#include <stdexcept>

using namespace std;

bool caracteresCodigo(string codigo){
    if(!isupper(codigo[0]) || !isupper(codigo[1]))
        return false;

    for(int i = 2; i < 5; i++){
        if(!isdigit(codigo[i]))
            return false;
    }

    return true;
}

bool Codigo::validar(string codigo){
    if(codigo.size() != 5)
        return false;

    if(!caracteresCodigo(codigo))
        return false;

    return true;
}

bool Codigo::setCodigo(string codigo){
    if(!validar(codigo))
        throw invalid_argument("Formato de Codigo invalido.");
    this->codigo = codigo;
    return true;
}
