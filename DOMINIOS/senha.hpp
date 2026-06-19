#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Senha
 * @brief Representa uma senha de acesso do sistema.
 *
 * Esta classe armazena e valida uma senha de acordo
 * com as regras estabelecidas para o dom&iacute;nio.
 *
 * 6 caracteres
 * Caracter pode ser letra (a-z ou A-Z) ou d&iacute;gito (0-9);
 * Letra n&atilde;o pode ser seguida por letra, d&iacute;gito n&atilde;o pode ser seguido por d&iacute;gito;
 * Existe pelo menos uma letra min&uacute;scula (a-z), uma letra mai&uacute;scula (A-Z) e um d&iacute;gito (0-9).
 *
 */
class Senha {
private:
    string senha;

    /**
     * @brief Valida a senha informada.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Senha.
     *
     * @param senha String contendo a senha a ser validada.
     *
     * @return true caso a senha seja v&aacute;lida.
     * @return false caso a senha seja inv&aacute;lida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da senha.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param senha String contendo a senha a ser armazenada.
     *
     * @return true caso a senha seja v&aacute;lida e armazenada.
     * @return false caso a senha seja inv&aacute;lida.
     */
    bool setSenha(string);

    /**
     * @brief Retorna o valor da senha.
     *
     * @return String contendo a senha armazenada.
     */
    string getSenha() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getSenha.
 *
 * @return String contendo a senha armazenada.
 */
inline string Senha::getSenha() const{
    return senha;
}

#endif // SENHA_HPP_INCLUDED
