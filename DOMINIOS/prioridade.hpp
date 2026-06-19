#ifndef PRIORIDADE_HPP_INCLUDED
#define PRIORIDADE_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Prioridade
 * @brief Representa a prioridade de uma entidade do sistema.
 *
 * Esta classe armazena e valida uma prioridade de acordo
 * com as regras estabelecidas para o dom&iacute;nio.
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
     * estabelecidas para o dom&iacute;nio Prioridade.
     *
     * @param prioridade String contendo a prioridade a ser validada.
     *
     * @return true caso a prioridade seja v&aacute;lida.
     * @return false caso a prioridade seja inv&aacute;lida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da prioridade.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param prioridade String contendo a prioridade a ser armazenada.
     *
     * @return true caso a prioridade seja v&aacute;lida e armazenada.
     * @return false caso a prioridade seja inv&aacute;lida.
     */
    bool setPrioridade(string);

    /**
     * @brief Retorna o valor da prioridade.
     *
     * @return String contendo a prioridade armazenada.
     */
    string getPrioridade() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getPrioridade.
 *
 * @return String contendo a prioridade armazenada.
 */
inline string Prioridade::getPrioridade() const{
    return prioridade;
}

#endif // PRIORIDADE_HPP_INCLUDED
