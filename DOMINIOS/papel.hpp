#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Papel
 * @brief Representa o papel desempenhado por um usuario no sistema.
 *
 * Esta classe armazena e valida um papel de acordo
 * com as regras estabelecidas para o dominio.
 *
 * Papel pode ser:
 * DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO
 *
 */
class Papel {
private:
    string papel;

    /**
     * @brief Valida o papel informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Papel.
     *
     * @param papel String contendo o papel a ser validado.
     *
     * @return true caso o papel seja valido.
     * @return false caso o papel seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do papel.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param papel String contendo o papel a ser armazenado.
     *
     * @return true caso o papel seja valido e armazenado.
     * @return false caso o papel seja invalido.
     */
    bool setPapel(string);

    /**
     * @brief Retorna o valor do papel.
     *
     * @return String contendo o papel armazenado.
     */
    string getPapel();
};

/**
 * @brief Implementacao inline do metodo getPapel.
 *
 * @return String contendo o papel armazenado.
 */
inline string Papel::getPapel() {
    return papel;
}

#endif // PAPEL_HPP_INCLUDED
