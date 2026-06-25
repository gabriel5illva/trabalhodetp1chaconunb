#ifndef CNTRAPRESENTACAOPROJETO_HPP_INCLUDED
#define CNTRAPRESENTACAOPROJETO_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoProjeto.hpp"
#include "../INTERFACES/IServicoProjeto.hpp"
#include "../INTERFACES/IServicoPessoa.hpp" // Necessário para verificar o Papel do usuário
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

public:
    void executar(const Email &email) override;
    
    void setServicoProjeto(IServicoProjeto *servico) override;

    void setServicoPessoa(IServicoPessoa *servico); 
};

#endif // CNTRAPRESENTACAOPROJETO_HPP_INCLUDED