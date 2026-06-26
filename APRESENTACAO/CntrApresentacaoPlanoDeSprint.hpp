#ifndef CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED
#define CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoPlanoDeSprint.hpp"
#include "../INTERFACES/IServicoPlanoDeSprint.hpp"
#include "../INTERFACES/IServicoPessoa.hpp" 
#include "../INTERFACES/IServicoHistoriaDeUsuario.hpp"
#include "../INTERFACES/IServicoProjeto.hpp"

#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/texto.hpp"
#include "../DOMINIOS/tempo.hpp"
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
    IServicoHistoriaDeUsuario *servicoHistoriaDeUsuario;
    IServicoProjeto *servicoProjeto;

public:
    void executar(const Email &email) override;
    
    void setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico) override;

    void setServicoPessoa(IServicoPessoa *servico);

    void setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico);

    void setServicoProjeto(IServicoProjeto *servico);
};

#endif // CNTRAPRESENTACAOPLANODESPRINT_HPP_INCLUDED