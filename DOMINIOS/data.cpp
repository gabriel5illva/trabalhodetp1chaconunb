#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "data.hpp"

using namespace std;

bool formatoValido(const string& data){
    if(data.size() != 10 || data[2] != '/' || data[5] != '/')
        return false;

    for(int i = 0; i < 10; i++){
        if(i == 2 || i == 5) continue;
        if(!isdigit(data[i])) return false;
    }

    return true;
}

int extrairDia(const string& data){
    return stoi(data.substr(0,2));
}

int extrairMes(const string& data){
    return stoi(data.substr(3,2));
}

int extrairAno(const string& data){
    return stoi(data.substr(6,4));
}

bool anoBissexto(int ano){
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int obterDiasNoMes(int mes, int ano){
    if(mes == 2)
        return anoBissexto(ano) ? 29 : 28;

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    return 31;
}

bool Data::validar(string data){
    if(!formatoValido(data))
        return false;

    int dia = extrairDia(data);
    int mes = extrairMes(data);
    int ano = extrairAno(data);

    if(mes < 1 || mes > 12)
        return false;

    if(ano < 2000 || ano > 2999)
        return false;

    int diasNoMes = obterDiasNoMes(mes, ano);

    if(dia < 1 || dia > diasNoMes)
        return false;

    return true;
}

bool Data::setData(string data){
    if(!validar(data)){
        throw invalid_argument("Formato de Data invalido.");
    }
    this->data = data;
    return true;
}
