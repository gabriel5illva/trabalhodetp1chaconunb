#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Codigo
 * @brief Representa o c&oacute;digo identificador de uma entidade do sistema.
 *
 * Esta classe armazena e valida um c&oacute;digo no formato definido
 * pelas regras de neg&oacute;cio do dom&iacute;nio:
 *
 * 5 caracteres
 * Sendo letras mai&uacute;sculas (A-Z) os dois primeiros caracteres.
 * Sendo d&iacute;gitos (0-9) os tr&ecirc;s &uacute;ltimos caracteres
 *
 */
class Codigo {
private:
    string codigo;

    /**
     * @brief Valida o c&oacute;digo informado.
     *
     * Verifica se o valor recebido atende as regras de formato
     * estabelecidas para o dom&iacute;nio Codigo.
     *
     * @param codigo String contendo o c&oacute;digo a ser validado.
     *
     * @return true caso o c&oacute;digo seja v&aacute;lido.
     * @return false caso o c&oacute;digo seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do c&oacute;digo.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo somente
     * se passar pela valida&ccedil;&atilde;o.
     *
     * @param codigo String contendo o c&oacute;digo a ser armazenado.
     *
     * @return true caso o c&oacute;digo seja v&aacute;lido e armazenado.
     * @return false caso o c&oacute;digo seja inv&aacute;lido.
     */
    bool setCodigo(string);

    /**
     * @brief Retorna o valor do c&oacute;digo.
     *
     * @return String contendo o c&oacute;digo armazenado.
     */
    string getCodigo() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getCodigo.
 *
 * @return String contendo o c&oacute;digo armazenado.
 */
inline string Codigo::getCodigo() const{
    return codigo;
}

#endif // CODIGO_HPP_INCLUDED
