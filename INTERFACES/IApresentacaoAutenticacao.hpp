#ifndef IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
#define IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "IServicoAutenticacao.hpp"

/**
 * @class IApresentacaoAutenticacao
 * @brief Interface para a apresentação da tela de login.
 */
class IApresentacaoAutenticacao {
public:
    /**
     * @brief Executa a tela de login.
     * @param email Referência para capturar o email do usuário caso a autenticação tenha sucesso.
     * @return true se o usuário foi autenticado com sucesso.
     */
    virtual bool autenticar(Email &email) = 0;

    /**
     * @brief Estabelece a ligação com a camada de serviço.
     */
    virtual void setServicoAutenticacao(IServicoAutenticacao *servico) = 0;

    virtual ~IApresentacaoAutenticacao() = default;
};

#endif // IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
