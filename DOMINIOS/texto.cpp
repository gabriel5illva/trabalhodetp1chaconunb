#include "texto.hpp"
#include <string>
#include <cctype>

using namespace std;

bool textoTamanhoValido(string texto){
    if(texto.empty() || texto.size() > 40)
        return false;
    return true;
}

bool textoExtremidadesValidas(string texto){
    if(texto.back() == ' ' || texto.back() == ',' || texto.back() == '.' ||
       texto.front() == ' ' || texto.front() == ',' || texto.front() == '.')
            return false;
    return true;
}

bool textoCaracteresValidos(string texto){
    for(size_t i = 0; i < texto.size(); i++){
        if(!(isalnum(texto[i]) || texto[i] == ' ' || texto[i] == ',' || texto[i] == '.'))
            return false;

        if(i < texto.size() - 1){
            if((texto[i] == ',' || texto[i] == '.') &&
            (texto[i+1] == ',' || texto[i+1] == '.'))
                return false;

            if(texto[i] == ' ' && !isalnum(texto[i+1]))
                return false;
        }
    }
    return true;
}

bool Texto::validar(string texto){
    return (textoTamanhoValido(texto) &&
           textoExtremidadesValidas(texto)&&
           textoCaracteresValidos(texto));
}

bool Texto::setTexto(string texto){
    if (!validar(texto))
        return false;
    this->texto = texto;
    return true;
}
