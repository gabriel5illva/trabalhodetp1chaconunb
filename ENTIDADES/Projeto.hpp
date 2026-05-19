#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Data.hpp"

/**
 * @class Projeto
 * @brief Representa um projeto gerenciado pelo sistema.
 *
 * Esta classe armazena os dados b&aacute;sicos de um projeto,
 * incluindo c&oacute;digo, nome, data de in&iacute;cio e data de t&eacute;rmino.
 *
 * Cada atributo da entidade Projeto &eacute; representado por uma
 * classe de dom&iacute;nio.
 */
class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;

public:
    /**
     * @brief Define o c&oacute;digo do projeto.
     *
     * @param codigo Objeto da classe de dom&iacute;nio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o c&oacute;digo do projeto.
     *
     * @return Objeto da classe de dom&iacute;nio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do projeto.
     *
     * @param nome Objeto da classe de dom&iacute;nio Nome.
     */
    void setNome(const Nome &);

    /**
     * @brief Retorna o nome do projeto.
     *
     * @return Objeto da classe de dom&iacute;nio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de in&iacute;cio do projeto.
     *
     * @param inicio Objeto da classe de dom&iacute;nio Data.
     */
    void setInicio(const Data &);

    /**
     * @brief Retorna a data de in&iacute;cio do projeto.
     *
     * @return Objeto da classe de dom&iacute;nio Data.
     */
    Data getInicio() const;

    /**
     * @brief Define a data de t&eacute;rmino do projeto.
     *
     * @param termino Objeto da classe de dom&iacute;nio Data.
     */
    void setTermino(const Data &);

    /**
     * @brief Retorna a data de t&eacute;rmino do projeto.
     *
     * @return Objeto da classe de dom&iacute;nio Data.
     */
    Data getTermino() const;
};

#endif
