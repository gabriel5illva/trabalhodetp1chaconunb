#ifndef IAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED
#define IAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "IServicoHistoriaDeUsuario.hpp"

/**
 * @class IApresentacaoHistoriaDeUsuario
 * @brief Interface para a apresentação das telas de gestão de Histórias de Usuário.
 */
class IApresentacaoHistoriaDeUsuario {
public:
    /**
     * @brief Executa o menu de gestão de histórias de usuário.
     * @param email Email do usuário atualmente logado na sessão.
     */
    virtual void executar(const Email &email) = 0;

    /**
     * @brief Estabelece a ligação com a camada de serviço correspondente.
     * @param servico Ponteiro para a implementação de IServicoHistoriaDeUsuario.
     */
    virtual void setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico) = 0;
    
    virtual ~IApresentacaoHistoriaDeUsuario() = default;
};

#endif // IAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED