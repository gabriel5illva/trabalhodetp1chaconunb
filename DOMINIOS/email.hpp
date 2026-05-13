#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Email
 * @brief Representa um endereco de email do sistema.
 *
 * Esta classe armazena e valida um endereco de email
 * de acordo com as regras estabelecidas para o dominio.
 *
 * parte-local@domínio
 * Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-);
 * Não pode iniciar ou terminar com ponto ou hífen;
 * Ponto ou hífen deve ser seguido por letra(s) ou dígito(s);
 * Comprimento máximo é 64 caracteres.
 * Domínio é composto por uma ou mais partes separadas por ponto (.);
 * Cada parte pode conter letra (a-z), dígito (0-9) ou hífen (-);
 * Não pode iniciar ou terminar com hífen;
 * Comprimento máximo é 255 caracteres.
 *
 */
class Email {
private:
    string email;

    /**
     * @brief Tamanho maximo permitido para a parte local do email.
     */
    const int tamanhoMaxParteLocal = 64;

    /**
     * @brief Tamanho maximo permitido para a parte de dominio do email.
     */
    const int tamanhoMaxParteDominio = 255;

    /**
     * @brief Valida o endereco de email informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Email.
     *
     * @param email String contendo o endereco de email a ser validado.
     *
     * @return true caso o email seja valido.
     * @return false caso o email seja invalido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do email.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param email String contendo o endereco de email a ser armazenado.
     *
     * @return true caso o email seja valido e armazenado.
     * @return false caso o email seja invalido.
     */
    bool setEmail(string);

    /**
     * @brief Retorna o endereco de email armazenado.
     *
     * @return String contendo o endereco de email.
     */
    string getEmail();
};

/**
 * @brief Implementacao inline do metodo getEmail.
 *
 * @return String contendo o endereco de email armazenado.
 */
inline string Email::getEmail() {
    return email;
}

#endif // EMAIL_HPP_INCLUDED
