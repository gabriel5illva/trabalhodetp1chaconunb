#ifndef IAPRESENTACAOPLANODESPRINT_HPP_INCLUDED
#define IAPRESENTACAOPLANODESPRINT_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "IServicoPlanoDeSprint.hpp"

/**
 * @class IApresentacaoPlanoDeSprint
 * @brief Interface para a apresentação das telas de gestão de Planos de Sprint.
 */
class IApresentacaoPlanoDeSprint {
public:
    /**
     * @brief Executa o menu de gestão de planos de sprint.
     * @param email Email do usuário atualmente logado na sessão.
     */
    virtual void executar(const Email &email) = 0;

    /**
     * @brief Estabelece a ligação com a camada de serviço correspondente.
     * @param servico Ponteiro para a implementação de IServicoPlanoDeSprint.
     */
    virtual void setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) = 0;
    
    virtual ~IApresentacaoPlanoDeSprint() = default;
};

#endif // IAPRESENTACAO_PLANO_DE_SPRINT_HPP_INCLUDED