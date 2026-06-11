#ifndef SERVICO_AUTENTICACAO_HPP_INCLUDED
#define SERVICO_AUTENTICACAO_HPP_INCLUDED

#include "../INTERFACES/IServicoAutenticacao.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class ServicoAutenticacao
 * @brief Implementa os servi&ccedil;os relacionados &agrave; autentica&ccedil;&atilde;o.
 *
 * Esta classe realiza a interface IServicoAutenticacao e utiliza
 * ContainerPessoa para verificar email e senha de pessoas cadastradas.
 */
class ServicoAutenticacao : public IServicoAutenticacao {
private:
    ContainerPessoa *containerPessoa;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoAutenticacao();

    /**
     * @brief Define o cont&ecirc;iner de pessoas utilizado pelo servi&ccedil;o.
     *
     * @param containerPessoa Ponteiro para ContainerPessoa.
     */
    void setContainerPessoa(ContainerPessoa *containerPessoa);

    /**
     * @brief Autentica uma pessoa cadastrada no sistema.
     *
     * @param email Email informado pela pessoa.
     * @param senha Senha informada pela pessoa.
     * @return true se email e senha corresponderem a uma pessoa cadastrada.
     */
    bool autenticar(const Email &email, const Senha &senha) override;
};

#endif
