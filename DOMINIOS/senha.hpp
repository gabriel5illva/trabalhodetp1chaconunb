#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED
#include <string>

using namespace std;

class Senha{
    private:
        string senha;
        bool validar(string);
    public:
        bool setSenha(string);
        string getSenha();
};

inline string Senha::getSenha(){
    return senha;
}

#endif // SENHA_HPP_INCLUDED
