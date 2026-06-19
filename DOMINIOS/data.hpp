#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Data
 * @brief Representa uma data no sistema.
 *
 * Esta classe armazena e valida uma data de acordo
 * com as regras de formato e consist&ecirc;ncia definidas
 * para o dom&iacute;nio.
 *
 * DIA/M&Ecirc;S/ANO
 * DIA &eacute; n&uacute;mero de 1 a 31.
 * M&Ecirc;S &eacute; n&uacute;mero 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11 ou 12.
 * ANO &eacute; n&uacute;mero de 2000 a 2999.
 * Data &eacute; v&aacute;lida considerando anos bissextos.
 *
 */
class Data {
private:
    string data;

    /**
     * @brief Valida a data informada.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Data.
     *
     * @param data String contendo a data a ser validada.
     *
     * @return true caso a data seja v&aacute;lida.
     * @return false caso a data seja inv&aacute;lida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da data.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param data String contendo a data a ser armazenada.
     *
     * @return true caso a data seja v&aacute;lida e armazenada.
     * @return false caso a data seja inv&aacute;lida.
     */
    bool setData(string);

    /**
     * @brief Retorna o valor da data.
     *
     * @return String contendo a data armazenada.
     */
    string getData() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getData.
 *
 * @return String contendo a data armazenada.
 */
inline string Data::getData() const{
    return data;
}

#endif // DATA_HPP_INCLUDED
