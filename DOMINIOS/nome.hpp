#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Nome
 * @brief Representa um nome no sistema.
 *
 * Esta classe armazena e valida um nome de acordo
 * com as regras estabelecidas para o dominio nome.
 *
 * Texto com até 10 caracteres.
 * Caracter pode ser letra maiúscula (A-Z), letra minúscula (a-z) ou espaço em branco;
 * Espaço em branco é seguido por letra;
 * Primeiro caracter não pode ser espaço em branco;
 * Último caracter não pode ser espaço em branco.
 *
 */
class Nome {
private:
    string nome;

    /**
     * @brief Valida o nome informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Nome.
     *
     * @param nome String contendo o nome a ser validado.
     *
     * @return true caso o nome seja valido.
     * @return false caso o nome seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do nome.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param nome String contendo o nome a ser armazenado.
     *
     * @return true caso o nome seja valido e armazenado.
     * @return false caso o nome seja invalido.
     */
    bool setNome(string);

    /**
     * @brief Retorna o valor do nome.
     *
     * @return String contendo o nome armazenado.
     */
    string getNome();
};

/**
 * @brief Implementacao inline do metodo getNome.
 *
 * @return String contendo o nome armazenado.
 */
inline string Nome::getNome() {
    return nome;
}

#endif // NOME_HPP_INCLUDED
