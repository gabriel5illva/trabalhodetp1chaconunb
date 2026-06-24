#ifndef IAPRESENTACAOPROJETO_HPP_INCLUDED
#define IAPRESENTACAOPROJETO_HPP_INCLUDED

#include "../DOMINIOS/email.hpp"
#include "IServicoProjeto.hpp"

/**
 * @class IApresentacaoProjeto
 * @brief Interface para a apresentação das telas de gestão de projetos.
 */
class IApresentacaoProjeto {
public:
    /**
     * @brief Executa o menu de gestão de projetos (Criar, Ler, Atualizar, Excluir, Listar).
     * @param email Email do usuário atualmente logado operando o menu.
     */
    virtual void executar(const Email &email) = 0;

    /**
     * @brief Estabelece a ligação com a camada de serviço de projetos.
     * @param servico Ponteiro para a instância de IServicoProjeto.
     */
    virtual void setServicoProjeto(IServicoProjeto *servico) = 0;
    
    virtual ~IApresentacaoProjeto() = default;
};

#endif // IAPRESENTACAOPROJETO_HPP_INCLUDED