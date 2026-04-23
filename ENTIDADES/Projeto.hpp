#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Data.hpp"

class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;

    void setNome(const Nome &);
    Nome getNome() const;

    void setInicio(const Data &);
    Data getInicio() const;

    void setTermino(const Data &);
    Data getTermino() const;
};

#endif
