#ifndef CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
#define CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED

#include "IApresentacaoAutenticacao.hpp"

class CntrApresentacaoAutenticacao :
    public IApresentacaoAutenticacao {

public:
    void autenticar(
        IServicoAutenticacao* ponteiroServico
    ) override;

    void cadastrar(
        IServicoAutenticacao* ponteiroServico
    ) override;

    void executar(
        IServicoAutenticacao* ponteiroServico
    ) override;
};


#endif // CNTRAPRESENTACAOAUTENTICACAO_HPP_INCLUDED
