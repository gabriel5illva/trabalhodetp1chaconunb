#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Nome
 * @brief Representa um nome no sistema.
 *
 * Esta classe armazena e valida um nome de acordo
 * com as regras estabelecidas para o dom&iacute;nio nome.
 *
 * Texto com at&eacute; 10 caracteres.
 * Caracter pode ser letra mai&uacute;scula (A-Z), letra min&uacute;scula (a-z) ou espa&ccedil;o em branco;
 * Espa&ccedil;o em branco &eacute; seguido por letra;
 * Primeiro caracter n&atilde;o pode ser espa&ccedil;o em branco;
 * &Uacute;ltimo caracter n&atilde;o pode ser espa&ccedil;o em branco.
 *
 */
class Nome {
private:
    string nome;

    /**
     * @brief Valida o nome informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Nome.
     *
     * @param nome String contendo o nome a ser validado.
     *
     * @return true caso o nome seja v&aacute;lido.
     * @return false caso o nome seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do nome.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param nome String contendo o nome a ser armazenado.
     *
     * @return true caso o nome seja v&aacute;lido e armazenado.
     * @return false caso o nome seja inv&aacute;lido.
     */
    bool setNome(string);

    /**
     * @brief Retorna o valor do nome.
     *
     * @return String contendo o nome armazenado.
     */
    string getNome() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getNome.
 *
 * @return String contendo o nome armazenado.
 */
inline string Nome::getNome() const{
    return nome;
}

#endif // NOME_HPP_INCLUDED
