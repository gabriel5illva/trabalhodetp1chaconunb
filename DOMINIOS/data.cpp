#include <iostream>
#include <string>
#include "data.hpp"

bool Data::validar(string data){
    if(data.size() != 10 || data[2] != '/' || data[5] != '/')
        return false;

    for(int i = 0; i < 10 ; i++){
        if(i == 2 || i == 5){
            continue;
        }
        if(!isdigit(data[i])){
            throw invalid_argument("Data contem caracteres invalidos.");
        }
    }

    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if(mes < 1 || mes > 12)
        return false;

    if(ano < 2000 || ano > 2999)
        return false;

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    int diasNoMes;

    if(mes == 2){
        if(bissexto){
            diasNoMes = 29;
        }
        else{
            diasNoMes = 28;
        }
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        diasNoMes = 30;
    }
    else{
        diasNoMes = 31;
    }

    if(dia < 1 || dia > diasNoMes)
        return false;

    return true;
}


bool Data::setData(string data){
    if(!validar(data))
        return false;
    this->data=data;
    return true;
}
