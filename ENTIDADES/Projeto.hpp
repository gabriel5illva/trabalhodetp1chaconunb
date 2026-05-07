#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Data.hpp"

/**
 * @class Projeto
 * @brief Representa um projeto gerenciado pelo sistema.
 *
 * Esta classe armazena os dados basicos de um projeto,
 * incluindo codigo, nome, data de inicio e data de termino.
 *
 * Cada atributo da entidade Projeto e representado por uma
 * classe de dominio.
 */
class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;

public:
    /**
     * @brief Define o codigo do projeto.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o codigo do projeto.
     *
     * @return Objeto da classe de dominio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do projeto.
     *
     * @param nome Objeto da classe de dominio Nome.
     */
    void setNome(const Nome &);

    /**
     * @brief Retorna o nome do projeto.
     *
     * @return Objeto da classe de dominio Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de inicio do projeto.
     *
     * @param inicio Objeto da classe de dominio Data.
     */
    void setInicio(const Data &);

    /**
     * @brief Retorna a data de inicio do projeto.
     *
     * @return Objeto da classe de dominio Data.
     */
    Data getInicio() const;

    /**
     * @brief Define a data de termino do projeto.
     *
     * @param termino Objeto da classe de dominio Data.
     */
    void setTermino(const Data &);

    /**
     * @brief Retorna a data de termino do projeto.
     *
     * @return Objeto da classe de dominio Data.
     */
    Data getTermino() const;
};

#endif
