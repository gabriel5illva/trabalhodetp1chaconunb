#ifndef SERVICO_USUARIOS_HPP_INCLUDED
#define SERVICO_USUARIOS_HPP_INCLUDED

#include "../INTERFACES/IServicoUsuarios.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class ServicoUsuarios
 * @brief Implementa os servi&ccedil;os relacionados a usu&aacute;rios.
 *
 * Esta classe realiza a interface IServicoUsuarios e utiliza
 * ContainerPessoa para armazenar e manipular pessoas cadastradas.
 */
class ServicoUsuarios : public IServicoUsuarios {
private:
    ContainerPessoa *containerPessoa;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoUsuarios();

    /**
     * @brief Define o cont&ecirc;iner de pessoas utilizado pelo servi&ccedil;o.
     *
     * @param containerPessoa Ponteiro para ContainerPessoa.
     */
    void setContainerPessoa(ContainerPessoa *containerPessoa);

    /**
     * @brief Cria uma nova pessoa no sistema.
     *
     * @param pessoa Entidade Pessoa a ser cadastrada.
     * @return true se a pessoa for cadastrada com sucesso.
     */
    bool criar(const Pessoa &pessoa) override;

    /**
     * @brief Consulta uma pessoa cadastrada pelo email.
     *
     * @param email Email da pessoa a ser consultada.
     * @return Entidade Pessoa encontrada.
     */
    Pessoa ler(const Email &email) override;

    /**
     * @brief Atualiza os dados de uma pessoa cadastrada.
     *
     * @param pessoa Entidade Pessoa com os dados atualizados.
     * @return true se a pessoa for atualizada com sucesso.
     */
    bool atualizar(const Pessoa &pessoa) override;

    /**
     * @brief Exclui uma pessoa cadastrada.
     *
     * @param email Email da pessoa a ser exclu&iacute;da.
     * @return true se a pessoa for exclu&iacute;da com sucesso.
     */
    bool excluir(const Email &email) override;
};

#endif
