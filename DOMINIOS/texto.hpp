#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED
#include <string>

using namespace std;

class Texto{
    private:
        string texto;
        bool validar(string);
    public:
        bool setTexto(string);
        string getTexto();
};

inline string Texto::getTexto(){
    return texto;
}

#endif // TEXTO_HPP_INCLUDED
