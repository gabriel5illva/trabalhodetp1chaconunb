#include "codigo.hpp"

bool Codigo::validar(string codigo){
        if(codigo.size() != 5)
            return false;
        if(!std::isupper(codigo[0])||!std::isupper(codigo[1]))
            return false;
        for (int i=2; i<=4; i++)
            if(!std::isdigit(codigo[i]))
                return false;
        return true;
}

bool Codigo::setCodigo(string codigo){
        if(!validar(codigo))
            return false;
        this->codigo=codigo;
        return true;
}
