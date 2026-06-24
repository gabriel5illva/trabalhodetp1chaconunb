#ifndef CNTRAPRESENTACAOPESSOA_HPP_INCLUDED
#define CNTRAPRESENTACAOPESSOA_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoPessoa.hpp"
#include "../INTERFACES/IServicoPessoa.hpp"
#include "../DOMINIOS/email.hpp"
#include "../DOMINIOS/senha.hpp"
#include "../DOMINIOS/nome.hpp"
#include "../DOMINIOS/papel.hpp"
#include "../ENTIDADES/pessoa.hpp"

class CntrApresentacaoPessoa : public IApresentacaoPessoa {
private:
    IServicoPessoa *servicoPessoas;

public:
    void cadastrar() override;
    bool executar(const Email &email) override; // Menu interno de Gestão de Perfil
    void setServicoPessoa(IServicoPessoa *servico) override;
};

#endif // CNTRAPRESENTACAOPESSOA_HPP_INCLUDED