#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class Email
 * @brief Representa um endere&ccedil;o de email do sistema.
 *
 * Esta classe armazena e valida um endere&ccedil;o de email
 * de acordo com as regras estabelecidas para o dom&iacute;nio.
 *
 * parte-local@dom&iacute;nio
 * Parte local pode conter letra (a-z), d&iacute;gito (0-9) ou ponto(.) ou h&iacute;fen (-);
 * N&atilde;o pode iniciar ou terminar com ponto ou h&iacute;fen;
 * Ponto ou h&iacute;fen deve ser seguido por letra(s) ou d&iacute;gito(s);
 * Comprimento m&aacute;ximo &eacute; 64 caracteres.
 * Dom&iacute;nio &eacute; composto por uma ou mais partes separadas por ponto (.);
 * Cada parte pode conter letra (a-z), d&iacute;gito (0-9) ou h&iacute;fen (-);
 * N&atilde;o pode iniciar ou terminar com h&iacute;fen;
 * Comprimento m&aacute;ximo &eacute; 255 caracteres.
 *
 */
class Email {
private:
    string email;

    /**
     * @brief Tamanho m&aacute;ximo permitido para a parte local do email.
     */
    static const int tamanhoMaxParteLocal = 64;

    /**
     * @brief Tamanho m&aacute;ximo permitido para a parte de dom&iacute;nio do email.
     */
    static const int tamanhoMaxParteDominio = 255;

    /**
     * @brief Valida o endere&ccedil;o de email informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Email.
     *
     * @param email String contendo o endere&ccedil;o de email a ser validado.
     *
     * @return true caso o email seja v&aacute;lido.
     * @return false caso o email seja inv&aacute;lido.
     */
    bool validar(string);

public:
    /**
     * @brief Define o valor do email.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param email String contendo o endere&ccedil;o de email a ser armazenado.
     *
     * @return true caso o email seja v&aacute;lido e armazenado.
     * @return false caso o email seja inv&aacute;lido.
     */
    bool setEmail(string);

    /**
     * @brief Retorna o endere&ccedil;o de email armazenado.
     *
     * @return String contendo o endere&ccedil;o de email.
     */
    string getEmail() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getEmail.
 *
 * @return String contendo o endere&ccedil;o de email armazenado.
 */
inline string Email::getEmail()const{
    return email;
}

#endif // EMAIL_HPP_INCLUDED
