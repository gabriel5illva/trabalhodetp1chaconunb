#ifndef CNTRAPRESENTACAOPROJETO_HPP_INCLUDED
#define CNTRAPRESENTACAOPROJETO_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoProjeto.hpp"
#include "../INTERFACES/IServicoProjeto.hpp"
#include "../INTERFACES/IServicoPessoa.hpp"
#include "../INTERFACES/IServicoHistoriaDeUsuario.hpp"
#include "../INTERFACES/IServicoPlanoDeSprint.hpp"

#include "../DOMINIOS/email.hpp"
#include "../DOMINIOS/codigo.hpp"
#include "../DOMINIOS/nome.hpp"
#include "../DOMINIOS/data.hpp"
#include "../ENTIDADES/projeto.hpp"
#include "../ENTIDADES/pessoa.hpp"

class CntrApresentacaoProjeto : public IApresentacaoProjeto {
private:
    IServicoProjeto *servicoProjeto;
    IServicoPessoa *servicoPessoa;
    IServicoHistoriaDeUsuario *servicoHistoriaDeUsuario;
    IServicoPlanoDeSprint *servicoPlanoDeSprint;

public:
    void executar(const Email &email) override;
    
    void setServicoProjeto(IServicoProjeto *servico) override;

    void setServicoPessoa(IServicoPessoa *servico); 

    void setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico);

    void setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico);
};

#endif // CNTRAPRESENTACAOPROJETO_HPP_INCLUDED