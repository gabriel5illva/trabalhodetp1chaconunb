#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Texto
 * @brief Representa um texto no sistema.
 *
 * Esta classe armazena e valida um texto de acordo
 * com as regras estabelecidas para o dominio.
 *
 * Texto com até 40 caracteres.
 * Caracter pode ser letra (a-z ou A-Z), dígito (0-9), vírgula, ponto ou espaço em branco;
 * Vírgula não pode ser seguida por vírgula ou ponto;
 * Ponto não pode ser seguido por vírgula ou ponto;
 * Espaço em branco é seguido por letra ou dígito;
 * Primeiro e último caracter não pode ser vírgula, ponto ou espaço em branco.
 *
 */
class Texto {
private:
    string texto;

    /**
     * @brief Valida o texto informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Texto.
     *
     * @param texto String contendo o texto a ser validado.
     *
     * @return true caso o texto seja valido.
     * @return false caso o texto seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do texto.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param texto String contendo o texto a ser armazenado.
     *
     * @return true caso o texto seja valido e armazenado.
     * @return false caso o texto seja invalido.
     */
    bool setTexto(string);

    /**
     * @brief Retorna o valor do texto.
     *
     * @return String contendo o texto armazenado.
     */
    string getTexto();
};

/**
 * @brief Implementacao inline do metodo getTexto.
 *
 * @return String contendo o texto armazenado.
 */
inline string Texto::getTexto() {
    return texto;
}

#endif // TEXTO_HPP_INCLUDED
