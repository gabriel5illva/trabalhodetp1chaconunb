#ifndef PLANO_DE_SPRINT_HPP_INCLUDED
#define PLANO_DE_SPRINT_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"

class PlanoDeSprint {
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;

    void setObjetivo(const Texto &);
    Texto getObjetivo() const;

    void setCapacidade(const Tempo &);
    Tempo getCapacidade() const;
};

#endif
