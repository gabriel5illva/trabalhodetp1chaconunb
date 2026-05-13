#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Estado
 * @brief Representa o estado de uma entidade do sistema.
 *
 * Esta classe armazena e valida um estado de acordo
 * com as regras estabelecidas para o dominio.
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
     * estabelecidas para o dominio Estado.
     *
     * @param estado String contendo o estado a ser validado.
     *
     * @return true caso o estado seja valido.
     * @return false caso o estado seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do estado.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param estado String contendo o estado a ser armazenado.
     *
     * @return true caso o estado seja valido e armazenado.
     * @return false caso o estado seja invalido.
     */
    bool setEstado(string);

    /**
     * @brief Retorna o valor do estado.
     *
     * @return String contendo o estado armazenado.
     */
    string getEstado();
};

/**
 * @brief Implementacao inline do metodo getEstado.
 *
 * @return String contendo o estado armazenado.
 */
inline string Estado::getEstado() {
    return estado;
}

#endif // ESTADO_HPP_INCLUDED
