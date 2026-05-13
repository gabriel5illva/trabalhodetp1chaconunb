#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

/**
 * @class Tempo
 * @brief Representa um valor de tempo no sistema.
 *
 * Esta classe armazena e valida um valor inteiro
 * correspondente a tempo, de acordo com as regras
 * estabelecidas para o dominio.
 *
 * Número de 1 a 365
 *
 */
class Tempo {
private:
    int tempo;

    /**
     * @brief Valida o valor de tempo informado.
     *
     * Verifica se o valor recebido atende as regras
     * estabelecidas para o dominio Tempo.
     *
     * @param tempo Valor inteiro correspondente ao tempo.
     *
     * @return true caso o tempo seja valido.
     * @return false caso o tempo seja invalido.
     */
    bool validar(int);

public:
    /**
     * @brief Define o valor do tempo.
     *
     * O valor informado sera atribuido ao atributo
     * somente se passar pela validacao.
     *
     * @param tempo Valor inteiro correspondente ao tempo.
     *
     * @return true caso o tempo seja valido e armazenado.
     * @return false caso o tempo seja invalido.
     */
    bool setTempo(int);

    /**
     * @brief Retorna o valor do tempo.
     *
     * @return Valor inteiro correspondente ao tempo armazenado.
     */
    int getTempo();
};

/**
 * @brief Implementacao inline do metodo getTempo.
 *
 * @return Valor inteiro correspondente ao tempo armazenado.
 */
inline int Tempo::getTempo() {
    return tempo;
}

#endif // TEMPO_HPP_INCLUDED
