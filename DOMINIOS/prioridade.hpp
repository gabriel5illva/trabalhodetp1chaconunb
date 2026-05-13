#ifndef PRIORIDADE_HPP_INCLUDED
#define PRIORIDADE_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Prioridade
 * @brief Representa a prioridade de uma entidade do sistema.
 *
 * Esta classe armazena e valida uma prioridade de acordo
 * com as regras estabelecidas para o dominio.
 *
 * Prioridade pode ser:
 * ALTA, MEDIA, BAIXA
 *
 */
class Prioridade {
private:
    string prioridade;

    /**
     * @brief Valida a prioridade informada.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Prioridade.
     *
     * @param prioridade String contendo a prioridade a ser validada.
     *
     * @return true caso a prioridade seja valida.
     * @return false caso a prioridade seja invalida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da prioridade.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param prioridade String contendo a prioridade a ser armazenada.
     *
     * @return true caso a prioridade seja valida e armazenada.
     * @return false caso a prioridade seja invalida.
     */
    bool setPrioridade(string);

    /**
     * @brief Retorna o valor da prioridade.
     *
     * @return String contendo a prioridade armazenada.
     */
    string getPrioridade();
};

/**
 * @brief Implementacao inline do metodo getPrioridade.
 *
 * @return String contendo a prioridade armazenada.
 */
inline string Prioridade::getPrioridade() {
    return prioridade;
}

#endif // PRIORIDADE_HPP_INCLUDED
