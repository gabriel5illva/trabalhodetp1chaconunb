#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Senha
 * @brief Representa uma senha de acesso do sistema.
 *
 * Esta classe armazena e valida uma senha de acordo
 * com as regras estabelecidas para o dominio.
 *
 * 6 caracteres
 * Caracter pode ser letra (a-z ou A-Z) ou dígito (0-9);
 * Letra não pode ser seguida por letra, dígito não pode ser seguido por dígito;
 * Existe pelo menos uma letra minúscula (a-z), uma letra maiúscula (AZ) e um dígito (0-9).
 *
 */
class Senha {
private:
    string senha;

    /**
     * @brief Valida a senha informada.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Senha.
     *
     * @param senha String contendo a senha a ser validada.
     *
     * @return true caso a senha seja valida.
     * @return false caso a senha seja invalida.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor da senha.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param senha String contendo a senha a ser armazenada.
     *
     * @return true caso a senha seja valida e armazenada.
     * @return false caso a senha seja invalida.
     */
    bool setSenha(string);

    /**
     * @brief Retorna o valor da senha.
     *
     * @return String contendo a senha armazenada.
     */
    string getSenha();
};

/**
 * @brief Implementacao inline do metodo getSenha.
 *
 * @return String contendo a senha armazenada.
 */
inline string Senha::getSenha() {
    return senha;
}

#endif // SENHA_HPP_INCLUDED
