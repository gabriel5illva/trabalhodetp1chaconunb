#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Papel
 * @brief Representa o papel desempenhado por um usu&aacute;rio no sistema.
 *
 * Esta classe armazena e valida um papel de acordo
 * com as regras estabelecidas para o dom&iacute;nio.
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
     * estabelecidas para o dom&iacute;nio Papel.
     *
     * @param papel String contendo o papel a ser validado.
     *
     * @return true caso o papel seja v&aacute;lido.
     * @return false caso o papel seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do papel.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param papel String contendo o papel a ser armazenado.
     *
     * @return true caso o papel seja v&aacute;lido e armazenado.
     * @return false caso o papel seja inv&aacute;lido.
     */
    bool setPapel(string);

    /**
     * @brief Retorna o valor do papel.
     *
     * @return String contendo o papel armazenado.
     */
    string getPapel() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getPapel.
 *
 * @return String contendo o papel armazenado.
 */
inline string Papel::getPapel() const{
    return papel;
}

#endif // PAPEL_HPP_INCLUDED
