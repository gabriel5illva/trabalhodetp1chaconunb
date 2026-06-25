#ifndef HISTORIA_DE_USUARIO_HPP_INCLUDED
#define HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../dominios/Codigo.hpp"
#include "../dominios/Texto.hpp"
#include "../dominios/Tempo.hpp"
#include "../dominios/Prioridade.hpp"
#include "../dominios/Estado.hpp"
#include "../dominios/email.hpp"

/**
 * @class HistoriaDeUsuario
 * @brief Representa uma hist&oacute;ria de usu&aacute;rio do sistema.
 *
 * Esta classe armazena os dados de uma hist&oacute;ria de usu&aacute;rio,
 * incluindo c&oacute;digo, t&iacute;tulo, papel, a&ccedil;&atilde;o, valor, estimativa,
 * prioridade e estado.
 *
 * Cada atributo da entidade HistoriaDeUsuario &eacute; representado por uma
 * classe de dom&iacute;nio.
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
    Email emailAssociado;

public:
    /**
     * @brief Define o c&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     *
     * @param codigo Objeto da classe de dom&iacute;nio Codigo.
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Retorna o c&oacute;digo da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o t&iacute;tulo da hist&oacute;ria de usu&aacute;rio.
     *
     * @param titulo Objeto da classe de dom&iacute;nio Texto.
     */
    void setTitulo(const Texto &);

    /**
     * @brief Retorna o t&iacute;tulo da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Texto.
     */
    Texto getTitulo() const;

    /**
     * @brief Define o papel informado na hist&oacute;ria de usu&aacute;rio.
     *
     * @param papel Objeto da classe de dom&iacute;nio Texto.
     */
    void setPapel(const Texto &);

    /**
     * @brief Retorna o papel informado na hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Texto.
     */
    Texto getPapel() const;

    /**
     * @brief Define a a&ccedil;&atilde;o da hist&oacute;ria de usu&aacute;rio.
     *
     * @param acao Objeto da classe de dom&iacute;nio Texto.
     */
    void setAcao(const Texto &);

    /**
     * @brief Retorna a a&ccedil;&atilde;o da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Texto.
     */
    Texto getAcao() const;

    /**
     * @brief Define o valor da hist&oacute;ria de usu&aacute;rio.
     *
     * @param valor Objeto da classe de dom&iacute;nio Texto.
     */
    void setValor(const Texto &);

    /**
     * @brief Retorna o valor da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Texto.
     */
    Texto getValor() const;

    /**
     * @brief Define a estimativa da hist&oacute;ria de usu&aacute;rio.
     *
     * @param estimativa Objeto da classe de dom&iacute;nio Tempo.
     */
    void setEstimativa(const Tempo &);

    /**
     * @brief Retorna a estimativa da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Tempo.
     */
    Tempo getEstimativa() const;

    /**
     * @brief Define a prioridade da hist&oacute;ria de usu&aacute;rio.
     *
     * @param prioridade Objeto da classe de dom&iacute;nio Prioridade.
     */
    void setPrioridade(const Prioridade &);

    /**
     * @brief Retorna a prioridade da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Prioridade.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado da hist&oacute;ria de usu&aacute;rio.
     *
     * @param estado Objeto da classe de dom&iacute;nio Estado.
     */
    void setEstado(const Estado &);

    /**
     * @brief Retorna o estado da hist&oacute;ria de usu&aacute;rio.
     *
     * @return Objeto da classe de dom&iacute;nio Estado.
     */
    Estado getEstado() const;

    /**
     * @brief Define email associado a historia de usuario.
     * 
     * @param email Objeto da classe de dominio Email.
     */
    void setEmailAssociado(const Email &email);

    /**
     * @brief Retorna o email associado a historia de usuario.
     * 
     * @return Objeto da classe de dominio email.
     */
    Email getEmailAssociado() const;
};

#endif
