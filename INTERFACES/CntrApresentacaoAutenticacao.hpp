#ifndef CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
#define CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoAutenticacao.hpp"
#include "../INTERFACES/IServicoAutenticacao.hpp"
#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Senha.hpp"

class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao *servicoAutenticacao;

public:
    bool autenticar(Email &email) override;
    void setServicoAutenticacao(IServicoAutenticacao *servico) override;
};

#endif // CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
