#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
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

bool Email::validar(string email){
    size_t pos = email.find('@');
    if(pos != string::npos){
        string partelocal = email.substr(0,pos);
        if(partelocal.size() > tamanhoMaxParteLocal)
            return false;
        if(comecaOuTerminaComEspecial(partelocal))
            return false;
        for(char c : partelocal){
                if(!caractereValido(c))
                    return false;
        }

        string partedominio = email.substr(pos+1);
        if(partedominio.size() > tamanhoMaxParteDominio)
            return false;

        vector<string> partes;
        stringstream ss(partedominio);
        string parte;

        while (getline(ss, parte, '.')) {
            partes.push_back(parte);
        }

        for (const string& p : partes) {
            if(p.empty())
                return false;
            if(comecaOuTerminaComEspecial(p))
                return false;
            for(char c : p){
                if(!caractereValido(c))
                    return false;
            }
        }
        return true;
    }
    else
        return false;
}

bool Email::setEmail(string email) {
    if (!validar(email))
        return false;

    this->email = email;
    return true;
}
