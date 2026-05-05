#ifndef PRIORIDADE_HPP_INCLUDED
#define PRIORIDADE_HPP_INCLUDED

#include <string>

using namespace std;

class Prioridade{
private:
    string prioridade;
    bool validar(string);

public:
    bool setPrioridade(string);
    string getPrioridade();
};

inline string Prioridade::getPrioridade(){
    return prioridade;
}

#endif // PRIORIDADE_HPP_INCLUDED
