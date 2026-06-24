#ifndef IAPRESENTACAOUSUARIO_HPP_INCLUDED
#define IAPRESENTACAOUSUARIO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "IServicoUsuarios.hpp"

/**
 * @class IApresentacaoUsuario
 * @brief Interface para a apresentação das telas de gerenciamento de usuário.
 */
class IApresentacaoUsuario {
public:
    /**
     * @brief Fluxo para criar uma nova conta (Menu Inicial).
     */
    virtual void cadastrar() = 0;

    /**
     * @brief Fluxo do menu do usuário logado (Ler, Atualizar, Excluir).
     * @param email Email do usuário atualmente logado na sessão.
     */
    virtual void executar(const Email &email) = 0;

    /**
     * @brief Estabelece a ligação com a camada de serviço.
     */
    virtual void setServicoUsuarios(IServicoUsuarios *servico) = 0;

    virtual ~IApresentacaoUsuario() = default;
};

#endif // IAPRESENTACAOUSUARIO_HPP_INCLUDED
