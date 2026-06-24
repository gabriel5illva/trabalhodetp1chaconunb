#ifndef SERVICO_PESSOA_HPP_INCLUDED
#define SERVICO_PESSOA_HPP_INCLUDED

#include "../INTERFACES/IServicoPessoa.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class ServicoPessoa
 * @brief Implementa os servi&ccedil;os relacionados a pessoas.
 *
 * Esta classe realiza a interface IServicoPessoa e utiliza
 * ContainerPessoa para armazenar e manipular pessoas cadastradas
 * no sistema.
 */
class ServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa *containerPessoa;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoPessoa();

    /**
     * @brief Define o cont&ecirc;iner de pessoas utilizado pelo servi&ccedil;o.
     *
     * @param containerPessoa Ponteiro para ContainerPessoa.
     */
    void setContainerPessoa(ContainerPessoa *containerPessoa);

    /**
     * @brief Cria uma nova pessoa.
     *
     * @param pessoa Entidade Pessoa a ser cadastrada.
     * @return true se a pessoa for cadastrada com sucesso.
     */
    bool criar(const Pessoa &pessoa) override;

    /**
     * @brief Consulta uma pessoa pelo email.
     *
     * @param email Email da pessoa.
     * @return Entidade Pessoa encontrada.
     */
    Pessoa ler(const Email &email) override;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param pessoa Entidade Pessoa com os dados atualizados.
     * @return true se a pessoa for atualizada com sucesso.
     */
    bool atualizar(const Pessoa &pessoa) override;

    /**
     * @brief Exclui uma pessoa.
     *
     * @param email Email da pessoa.
     * @return true se a pessoa for exclu&iacute;da com sucesso.
     */
    bool excluir(const Email &email) override;
};

#endif // SERVICO_PESSOA_HPP_INCLUDED
