#ifndef CNTRAPRESENTACAOPESSOA_HPP_INCLUDED
#define CNTRAPRESENTACAOPESSOA_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoPessoa.hpp"
#include "../INTERFACES/IServicoPessoa.hpp"
#include "../INTERFACES/IServicoProjeto.hpp"
#include "../DOMINIOS/email.hpp"
#include "../DOMINIOS/senha.hpp"
#include "../DOMINIOS/nome.hpp"
#include "../DOMINIOS/papel.hpp"
#include "../ENTIDADES/pessoa.hpp"

class CntrApresentacaoPessoa : public IApresentacaoPessoa {
private:
    IServicoPessoa *servicoPessoas;
    IServicoProjeto *servicoProjeto;

public:
    void cadastrar() override;
    bool executar(const Email &email) override;
    void setServicoPessoa(IServicoPessoa *servico) override;
    void setServicoProjeto(IServicoProjeto *servico);
};

#endif // CNTRAPRESENTACAOPESSOA_HPP_INCLUDED