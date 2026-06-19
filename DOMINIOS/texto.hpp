#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Texto
 * @brief Representa um texto no sistema.
 *
 * Esta classe armazena e valida um texto de acordo
 * com as regras estabelecidas para o dom&iacute;nio.
 *
 * Texto com at&eacute; 40 caracteres.
 * Caracter pode ser letra (a-z ou A-Z), d&iacute;gito (0-9), v&iacute;rgula, ponto ou espa&ccedil;o em branco;
 * V&iacute;rgula n&atilde;o pode ser seguida por v&iacute;rgula ou ponto;
 * Ponto n&atilde;o pode ser seguido por v&iacute;rgula ou ponto;
 * Espa&ccedil;o em branco &eacute; seguido por letra ou d&iacute;gito;
 * Primeiro e &uacute;ltimo caracter n&atilde;o pode ser v&iacute;rgula, ponto ou espa&ccedil;o em branco.
 *
 */
class Texto {
private:
    string texto;

    /**
     * @brief Valida o texto informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Texto.
     *
     * @param texto String contendo o texto a ser validado.
     *
     * @return true caso o texto seja v&aacute;lido.
     * @return false caso o texto seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do texto.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param texto String contendo o texto a ser armazenado.
     *
     * @return true caso o texto seja v&aacute;lido e armazenado.
     * @return false caso o texto seja inv&aacute;lido.
     */
    bool setTexto(string);

    /**
     * @brief Retorna o valor do texto.
     *
     * @return String contendo o texto armazenado.
     */
    string getTexto() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getTexto.
 *
 * @return String contendo o texto armazenado.
 */
inline string Texto::getTexto() const{
    return texto;
}

#endif // TEXTO_HPP_INCLUDED
