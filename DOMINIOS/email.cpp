#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include "email.hpp"

using namespace std;

bool caractereValido(char c){
    return isalpha(c) || isdigit(c) || c == '.' || c == '-';
}

bool comecaOuTerminaComEspecial(const string& s){
    if(s.empty()) return true;

    return s.front() == '.' || s.front() == '-' ||
           s.back()  == '.' || s.back()  == '-';
}

bool validarParteLocal(const string& parte, int limite){
    if(parte.empty() || parte.size() > limite)
        return false;

    if(comecaOuTerminaComEspecial(parte))
        return false;

    for(char c : parte){
        if(!caractereValido(c))
            return false;
    }

    return true;
}

bool validarSegmentoDominio(const string& segmento){
    if(segmento.empty())
        return false;

    if(comecaOuTerminaComEspecial(segmento))
        return false;

    for(char c : segmento){
        if(!caractereValido(c))
            return false;
    }

    return true;
}

bool validarDominio(const string& dominio, int limite){
    if(dominio.empty() || dominio.size() > limite)
        return false;

    vector<string> partes;
    stringstream ss(dominio);
    string parte;

    while(getline(ss, parte, '.')){
        partes.push_back(parte);
    }

    for(const string& p : partes){
        if(!validarSegmentoDominio(p))
            return false;
    }

    return true;
}


bool Email::validar(string email){
    size_t pos = email.find('@');
    if(pos == string::npos || email.find('@', pos + 1) != string::npos)
        return false;

    string parteLocal = email.substr(0, pos);
    string parteDominio = email.substr(pos + 1);

    if(!validarParteLocal(parteLocal, tamanhoMaxParteLocal))
        return false;

    if(!validarDominio(parteDominio, tamanhoMaxParteDominio))
        return false;

    return true;
}

bool Email::setEmail(string email) {
    if (!validar(email)){
        throw invalid_argument("Formato de Email invalido.");
    }

    this->email = email;
    return true;
}
