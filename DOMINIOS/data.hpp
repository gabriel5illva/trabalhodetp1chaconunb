#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Data
 * @brief Representa uma data no sistema.
 *
 * Esta classe armazena e valida uma data de acordo
 * com as regras de formato e consistencia definidas
 * para o dominio.
 *
 * DIA/MÊS/ANO
 * DIA é número de 1 a 31.
 * MÊS é número 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11 ou 12.
 * ANO é número de 2000 a 2999.
 * Data é válida considerando anos bissextos.
 *
 */
class Data {
private:
    string data;

    /**
     * @brief Valida a data informada.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Data.
     *
     * @param data String contendo a data a ser validada.
     *
     * @return true caso a data seja valida.
     * @return false caso a data seja invalida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da data.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param data String contendo a data a ser armazenada.
     *
     * @return true caso a data seja valida e armazenada.
     * @return false caso a data seja invalida.
     */
    bool setData(string);

    /**
     * @brief Retorna o valor da data.
     *
     * @return String contendo a data armazenada.
     */
    string getData();
};

/**
 * @brief Implementacao inline do metodo getData.
 *
 * @return String contendo a data armazenada.
 */
inline string Data::getData() {
    return data;
}

#endif // DATA_HPP_INCLUDED
