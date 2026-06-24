#ifndef CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED
#define CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoAutenticacao.hpp"
#include "../INTERFACES/IApresentacaoPessoa.hpp"
#include "../DOMINIOS/Email.hpp"

class CntrApresentacaoControle {
private:
    IApresentacaoAutenticacao *apresentacaoAutenticacao;
    IApresentacaoPessoa *apresentacaoPessoa;

    // Método privado para gerenciar o menu pós-login
    void menuPrincipal(const Email &email);

public:
    void setApresentacaoAutenticacao(IApresentacaoAutenticacao *apresentacao);
    void setApresentacaoPessoa(IApresentacaoPessoa *apresentacao);

    void executar(); // Menu Inicial (Deslogado)
};

#endif // CNTR_APRESENTACAO_CONTROLE_HPP_INCLUDED