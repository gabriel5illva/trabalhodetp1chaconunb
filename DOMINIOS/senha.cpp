#include "senha.hpp"
#include <cctype>

using namespace std;

bool caracteresValidos(string senha){
    for(char c : senha)
        if(!isalnum(c))
            return false;
    return true;
}

bool possuiCaracteres(const string& senha){
    bool minusculo = false;
    bool maiusculo = false;
    bool numero = false;

    for(char c : senha){
        if(isupper(c)) maiusculo = true;
        else if(islower(c)) minusculo = true;
        else if(isdigit(c)) numero = true;

        if(maiusculo && minusculo && numero)
            return true;
    }

    return false;
}

bool possuiCaractereSeguido(string senha){
    for(size_t i = 0; i < senha.size() - 1; i++){
        if(isalpha(senha[i]) && isalpha(senha[i+1]))
            return true;

        if(isdigit(senha[i]) && isdigit(senha[i+1]))
            return true;
    }
    return false;
}


bool Senha::validar(string senha){
    if(senha.size() != 6)
        return false;
    if(!caracteresValidos(senha))
        return false;
    if(!possuiCaracteres(senha))
        return false;
    if(possuiCaractereSeguido(senha))
        return false;
    return true;
}

bool Senha::setSenha(string senha){
    if(!validar(senha))
        return false;

    this->senha = senha;
    return true;
}

