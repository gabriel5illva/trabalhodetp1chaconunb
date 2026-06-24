#ifndef CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED
#define CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoPlanoDeSprint.hpp"
#include "../INTERFACES/IServicoPlanoDeSprint.hpp"
#include "../INTERFACES/IServicoPessoa.hpp" 
#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/texto.hpp" // INCLUÍDO
#include "../DOMINIOS/tempo.hpp" // INCLUÍDO
#include "../ENTIDADES/PlanoDeSprint.hpp"
#include "../ENTIDADES/Pessoa.hpp"

/**
 * @class CntrApresentacaoPlanoDeSprint
 * @brief Controladora de apresentação responsável pelas telas do Plano de Sprint.
 */
class CntrApresentacaoPlanoDeSprint : public IApresentacaoPlanoDeSprint {
private:
    IServicoPlanoDeSprint *servicoPlanoDeSprint;
    IServicoPessoa *servicoPessoa;

public:
    void executar(const Email &email) override;
    
    void setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) override;
    
    // Método para injetar o serviço de pessoas e validar o Mestre Scrum
    void setServicoPessoa(IServicoPessoa *servico);
};

#endif // CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED