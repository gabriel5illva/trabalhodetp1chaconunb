#ifndef SERVICO_PESSOA_HPP_INCLUDED
#define SERVICO_PESSOA_HPP_INCLUDED

#include "../interfaces/IServicePessoa.hpp"

/**
 * @class ServicoPessoa
 * @brief Implementa os servicos relacionados a Pessoa.
 *
 * Esta classe realiza a interface IServicePessoa e concentra
 * operacoes da camada de servico relacionadas a entidade Pessoa.
 */
class ServicoPessoa : public IServicePessoa {
public:
    /**
     * @brief Cria uma nova pessoa.
     *
     * @param pessoa Objeto da entidade Pessoa.
     * @return true se a operacao for realizada com sucesso.
     */
    bool criar(const Pessoa &pessoa) override;

    /**
     * @brief Le uma pessoa a partir do email.
     *
     * @param email Objeto da classe de dominio Email.
     * @return Objeto da entidade Pessoa.
     */
    Pessoa ler(const Email &email) override;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param pessoa Objeto da entidade Pessoa.
     * @return true se a operacao for realizada com sucesso.
     */
    bool atualizar(const Pessoa &pessoa) override;

    /**
     * @brief Exclui uma pessoa a partir do email.
     *
     * @param email Objeto da classe de dominio Email.
     * @return true se a operacao for realizada com sucesso.
     */
    bool excluir(const Email &email) override;
};

#endif
