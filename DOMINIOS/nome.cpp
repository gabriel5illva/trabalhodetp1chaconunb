#include "nome.hpp"
#include <string>
#include <cctype>

bool apenasLetras(string nome){
    for (char c : nome){
        if(!isalpha(c))
            return false;
    }
    return true;
}

bool primeiroOuUltimoEmBranco(string nome){
    return nome.back() == ' ' || nome.front() == ' ';
}

bool temLetraEmSeguidaDeEspaco(string nome){
    size_t tamanho = nome.size();

    for(size_t i = 0; i < tamanho; i++){
        if(nome[i] == ' '){
            if(i == tamanho - 1 || !isalpha(nome[i+1])){
                return false;
            }
        }
    }
    return true;
}

bool Nome::validar(string nome){
    if(nome.size() > 10)
        return false;
    if(primeiroOuUltimoEmBranco(nome))
        return false;
    if (!temLetraEmSeguidaDeEspaco(nome))
        return false;
    if(!apenasLetras(nome))
        return false;
    return true;
}

bool Nome::setNome(string nome){
    if(!validar(nome))
        return false;

    this->nome = nome;
    return true;
}
