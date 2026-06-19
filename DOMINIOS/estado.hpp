#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Estado
 * @brief Representa o estado de uma entidade do sistema.
 *
 * Esta classe armazena e valida um estado de acordo
 * com as regras estabelecidas para o dom&iacute;nio.
 *
 * Estado pode ser:
 * A FAZER, FAZENDO, FEITO
 *
 */
class Estado {
private:
    string estado;

    /**
     * @brief Valida o estado informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Estado.
     *
     * @param estado String contendo o estado a ser validado.
     *
     * @return true caso o estado seja v&aacute;lido.
     * @return false caso o estado seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do estado.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param estado String contendo o estado a ser armazenado.
     *
     * @return true caso o estado seja v&aacute;lido e armazenado.
     * @return false caso o estado seja inv&aacute;lido.
     */
    bool setEstado(string);

    /**
     * @brief Retorna o valor do estado.
     *
     * @return String contendo o estado armazenado.
     */
    string getEstado() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getEstado.
 *
 * @return String contendo o estado armazenado.
 */
inline string Estado::getEstado() const{
    return estado;
}

#endif // ESTADO_HPP_INCLUDED
