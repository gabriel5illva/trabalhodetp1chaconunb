#ifndef IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
#define IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "IServicoAutenticacao.hpp"

/**
 * @class IApresentacaoAutenticacao
 * @brief Interface para a apresentacao da tela de login.
 */
class IApresentacaoAutenticacao {
public:
    /**
     * @brief Executa a tela de login.
     * @param email Referencia para capturar o email do usuario caso a autenticacao tenha sucesso.
     * @return true se o usuario foi autenticado com sucesso.
     */
    virtual bool autenticar(Email &email) = 0;

    /**
     * @brief Estabelece a ligacao com a camada de servico.
     */
    virtual void setServicoAutenticacao(IServicoAutenticacao *servico) = 0;

    virtual ~IApresentacaoAutenticacao() = default;
};

#endif // IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
