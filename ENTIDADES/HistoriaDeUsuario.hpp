#ifndef HISTORIA_DE_USUARIO_HPP_INCLUDED
#define HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Estado.hpp"

/**
 * @class HistoriaDeUsuario
 * @brief Representa uma historia de usuario do sistema.
 *
 * Esta classe armazena os dados de uma historia de usuario,
 * incluindo codigo, titulo, papel, acao, valor, estimativa,
 * prioridade e estado.
 *
 * Cada atributo da entidade HistoriaDeUsuario e representado por uma
 * classe de dominio.
 */
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
    /**
     * @brief Define o codigo da historia de usuario.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o codigo da historia de usuario.
     *
     * @return Objeto da classe de dominio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o titulo da historia de usuario.
     *
     * @param titulo Objeto da classe de dominio Texto.
     */
    void setTitulo(const Texto &);

    /**
     * @brief Retorna o titulo da historia de usuario.
     *
     * @return Objeto da classe de dominio Texto.
     */
    Texto getTitulo() const;

    /**
     * @brief Define o papel informado na historia de usuario.
     *
     * @param papel Objeto da classe de dominio Texto.
     */
    void setPapel(const Texto &);

    /**
     * @brief Retorna o papel informado na historia de usuario.
     *
     * @return Objeto da classe de dominio Texto.
     */
    Texto getPapel() const;

    /**
     * @brief Define a acao da historia de usuario.
     *
     * @param acao Objeto da classe de dominio Texto.
     */
    void setAcao(const Texto &);

    /**
     * @brief Retorna a acao da historia de usuario.
     *
     * @return Objeto da classe de dominio Texto.
     */
    Texto getAcao() const;

    /**
     * @brief Define o valor da historia de usuario.
     *
     * @param valor Objeto da classe de dominio Texto.
     */
    void setValor(const Texto &);

    /**
     * @brief Retorna o valor da historia de usuario.
     *
     * @return Objeto da classe de dominio Texto.
     */
    Texto getValor() const;

    /**
     * @brief Define a estimativa da historia de usuario.
     *
     * @param estimativa Objeto da classe de dominio Tempo.
     */
    void setEstimativa(const Tempo &);

    /**
     * @brief Retorna a estimativa da historia de usuario.
     *
     * @return Objeto da classe de dominio Tempo.
     */
    Tempo getEstimativa() const;

    /**
     * @brief Define a prioridade da historia de usuario.
     *
     * @param prioridade Objeto da classe de dominio Prioridade.
     */
    void setPrioridade(const Prioridade &);

    /**
     * @brief Retorna a prioridade da historia de usuario.
     *
     * @return Objeto da classe de dominio Prioridade.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado da historia de usuario.
     *
     * @param estado Objeto da classe de dominio Estado.
     */
    void setEstado(const Estado &);

    /**
     * @brief Retorna o estado da historia de usuario.
     *
     * @return Objeto da classe de dominio Estado.
     */
    Estado getEstado() const;
};

#endif
