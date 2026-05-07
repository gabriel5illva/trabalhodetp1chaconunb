#ifndef PLANO_DE_SPRINT_HPP_INCLUDED
#define PLANO_DE_SPRINT_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"

/**
 * @class PlanoDeSprint
 * @brief Representa um plano de sprint do projeto.
 *
 * Esta classe armazena os dados basicos de um plano de sprint,
 * incluindo codigo, objetivo e capacidade.
 *
 * Cada atributo da entidade PlanoDeSprint e representado por uma
 * classe de dominio.
 */
class PlanoDeSprint {
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;

public:
    /**
     * @brief Define o codigo do plano de sprint.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o codigo do plano de sprint.
     *
     * @return Objeto da classe de dominio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o objetivo do plano de sprint.
     *
     * @param objetivo Objeto da classe de dominio Texto.
     */
    void setObjetivo(const Texto &);

    /**
     * @brief Retorna o objetivo do plano de sprint.
     *
     * @return Objeto da classe de dominio Texto.
     */
    Texto getObjetivo() const;

    /**
     * @brief Define a capacidade do plano de sprint.
     *
     * @param capacidade Objeto da classe de dominio Tempo.
     */
    void setCapacidade(const Tempo &);

    /**
     * @brief Retorna a capacidade do plano de sprint.
     *
     * @return Objeto da classe de dominio Tempo.
     */
    Tempo getCapacidade() const;
};

#endif
