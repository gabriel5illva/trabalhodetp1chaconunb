#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

/**
 * @class Tempo
 * @brief Representa um valor de tempo no sistema.
 *
 * Esta classe armazena e valida um valor inteiro
 * correspondente a tempo, de acordo com as regras
 * estabelecidas para o dom&iacute;nio.
 *
 * N&uacute;mero de 1 a 365
 *
 */
class Tempo {
private:
    int tempo;

    /**
     * @brief Valida o valor de tempo informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dom&iacute;nio Tempo.
     *
     * @param tempo Valor inteiro correspondente ao tempo.
     *
     * @return true caso o tempo seja v&aacute;lido.
     * @return false caso o tempo seja inv&aacute;lido.
     */
    bool validar(int);

public:
    /**
     * @brief Define o valor do tempo.
     *
     * O valor informado ser&aacute; atribu&iacute;do ao atributo
     * somente se passar pela valida&ccedil;&atilde;o.
     *
     * @param tempo Valor inteiro correspondente ao tempo.
     *
     * @return true caso o tempo seja v&aacute;lido e armazenado.
     * @return false caso o tempo seja inv&aacute;lido.
     */
    bool setTempo(int);

    /**
     * @brief Retorna o valor do tempo.
     *
     * @return Valor inteiro correspondente ao tempo armazenado.
     */
    int getTempo() const;
};

/**
 * @brief Implementa&ccedil;&atilde;o inline do m&eacute;todo getTempo.
 *
 * @return Valor inteiro correspondente ao tempo armazenado.
 */
inline int Tempo::getTempo() const{
    return tempo;
}

#endif // TEMPO_HPP_INCLUDED
