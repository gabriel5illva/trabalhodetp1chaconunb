#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED
#include <string>

class Estado{
    private:
        string estado;
        bool validar(string);
    public:
        bool setEstado(string);
        string getEstado();
};

inline string getEstado(){
    return estado;
}

#endif // ESTADO_HPP_INCLUDED
