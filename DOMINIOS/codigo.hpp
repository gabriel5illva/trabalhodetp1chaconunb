#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Codigo
 * @brief Representa o codigo identificador de uma entidade do sistema.
 *
 * Esta classe armazena e valida um codigo no formato definido
 * pelas regras de negocio do dominio:
 *
 * 5 caracteres
 * Sendo letras maiúsculas (A-Z) os dois primeiros caracteres.
 * Sendo dígitos (0-9) os três últimos caracteres
 *
 */
class Codigo {
private:
    string codigo;

    /**
     * @brief Valida o codigo informado.
     *
     * Verifica se o valor recebido atende as regras de formato
     * estabelecidas para o dominio Codigo.
     *
     * @param codigo String contendo o codigo a ser validado.
     *
     * @return true caso o codigo seja valido.
     * @return false caso o codigo seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do codigo.
     *
     * O valor informado sera atribuido ao atributo somente
     * se passar pela validacao.
     *
     * @param codigo String contendo o codigo a ser armazenado.
     *
     * @return true caso o codigo seja valido e armazenado.
     * @return false caso o codigo seja invalido.
     */
    bool setCodigo(string);

    /**
     * @brief Retorna o valor do codigo.
     *
     * @return String contendo o codigo armazenado.
     */
    string getCodigo();
};

/**
 * @brief Implementacao inline do metodo getCodigo.
 *
 * @return String contendo o codigo armazenado.
 */
inline string Codigo::getCodigo() {
    return codigo;
}

#endif // CODIGO_HPP_INCLUDED
