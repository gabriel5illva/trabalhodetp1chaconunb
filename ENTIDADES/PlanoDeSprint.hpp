#ifndef PLANO_DE_SPRINT_HPP_INCLUDED
#define PLANO_DE_SPRINT_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"

/**
 * @class PlanoDeSprint
 * @brief Representa um plano de sprint do projeto.
 *
 * Esta classe armazena os dados b&aacute;sicos de um plano de sprint,
 * incluindo c&oacute;digo, objetivo e capacidade.
 *
 * Cada atributo da entidade PlanoDeSprint &eacute; representado por uma
 * classe de dom&iacute;nio.
 */
class PlanoDeSprint {
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;

public:
    /**
     * @brief Define o c&oacute;digo do plano de sprint.
     *
     * @param codigo Objeto da classe de dom&iacute;nio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o c&oacute;digo do plano de sprint.
     *
     * @return Objeto da classe de dom&iacute;nio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o objetivo do plano de sprint.
     *
     * @param objetivo Objeto da classe de dom&iacute;nio Texto.
     */
    void setObjetivo(const Texto &);

    /**
     * @brief Retorna o objetivo do plano de sprint.
     *
     * @return Objeto da classe de dom&iacute;nio Texto.
     */
    Texto getObjetivo() const;

    /**
     * @brief Define a capacidade do plano de sprint.
     *
     * @param capacidade Objeto da classe de dom&iacute;nio Tempo.
     */
    void setCapacidade(const Tempo &);

    /**
     * @brief Retorna a capacidade do plano de sprint.
     *
     * @return Objeto da classe de dom&iacute;nio Tempo.
     */
    Tempo getCapacidade() const;
};

#endif
