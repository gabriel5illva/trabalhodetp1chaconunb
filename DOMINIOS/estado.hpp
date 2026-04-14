#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED
#include <string>

using namespace std;

class Estado{
    private:
        string estado;
        bool validar(string);
    public:
        bool setEstado(string);
        string getEstado();
};

inline string Estado::getEstado(){
    return estado;
}

#endif // ESTADO_HPP_INCLUDED
