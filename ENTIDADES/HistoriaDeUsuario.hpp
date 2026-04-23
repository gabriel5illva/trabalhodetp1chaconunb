#ifndef HISTORIA_DE_USUARIO_HPP_INCLUDED
#define HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Estado.hpp"

class HistoriaDeUsuario {
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;

    void setTitulo(const Texto &);
    Texto getTitulo() const;

    void setPapel(const Texto &);
    Texto getPapel() const;

    void setAcao(const Texto &);
    Texto getAcao() const;

    void setValor(const Texto &);
    Texto getValor() const;

    void setEstimativa(const Tempo &);
    Tempo getEstimativa() const;

    void setPrioridade(const Prioridade &);
    Prioridade getPrioridade() const;

    void setEstado(const Estado &);
    Estado getEstado() const;
};

#endif
