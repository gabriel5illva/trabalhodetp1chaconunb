#ifndef IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
#define IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED

#include "IServicoAutenticacao.hpp"

class IApresentacaoAutenticacao {
public:
    // Método para guiar o fluxo de cadastro de uma nova conta
    virtual void autenticar(IServicoAutenticacao* ponteiroServico) = 0;
    virtual void cadastrar(IServicoAutenticacao* ponteiroServico) = 0;
    virtual void executar(IServicoAutenticacao* ponteiroServico) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

#endif // IAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
