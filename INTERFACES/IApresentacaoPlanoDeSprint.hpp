#ifndef IAPRESENTACAO_PESSOA_HPP_INCLUDED
#define IAPRESENTACAO_PESSOA_HPP_INCLUDED

/**
 * @class IApresentacaoPessoa
 * @brief Interface da camada de apresentação para operações com Pessoa.
 *
 * Esta interface é responsável pela interação com o usuário,
 * coleta e validação dos dados de entrada e exibição dos resultados.
 */
class IApresentacaoPessoa {
public:

    /**
     * @brief Executa o fluxo de cadastro de pessoa.
     *
     * Solicita os dados ao usuário, valida as entradas e
     * encaminha a solicitação para a camada de serviço.
     */
    virtual void cadastrarPessoa() = 0;

    /**
     * @brief Executa o fluxo de consulta de pessoa.
     *
     * Solicita o email ao usuário e exibe os dados encontrados.
     */
    virtual void consultarPessoa() = 0;

    /**
     * @brief Executa o fluxo de atualização de pessoa.
     *
     * Solicita os novos dados ao usuário e encaminha
     * a atualização para a camada de serviço.
     */
    virtual void atualizarPessoa() = 0;

    /**
     * @brief Executa o fluxo de exclusão de pessoa.
     *
     * Solicita o email da pessoa e confirma a exclusão.
     */
    virtual void excluirPessoa() = 0;

    /**
     * @brief Exibe o menu principal relacionado a pessoas.
     */
    virtual void executar() = 0;

    /**
     * @brief Destrutor virtual.
     */
    virtual ~IApresentacaoPessoa() {}
};

#endif
