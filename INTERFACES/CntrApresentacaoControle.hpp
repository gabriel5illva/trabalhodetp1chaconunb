#ifndef CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED
#define CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoAutenticacao.hpp"
#include "../INTERFACES/IApresentacaoPessoa.hpp"
#include "../INTERFACES/IApresentacaoProjeto.hpp"
#include "../INTERFACES/IApresentacaoPlanoDeSprint.hpp" // INCLUÍDO
#include "../DOMINIOS/Email.hpp"

class CntrApresentacaoControle {
private:
    IApresentacaoAutenticacao *apresentacaoAutenticacao;
    IApresentacaoPessoa *apresentacaoPessoa;
    IApresentacaoProjeto *apresentacaoProjeto;
    IApresentacaoPlanoDeSprint *apresentacaoPlanoDeSprint; // INCLUÍDO

    // Método privado para gerenciar o menu pós-login
    void menuPrincipal(const Email &email);

public:
    CntrApresentacaoControle(); // Construtor para inicializar ponteiros
    
    void setApresentacaoAutenticacao(IApresentacaoAutenticacao *apresentacao);
    void setApresentacaoPessoa(IApresentacaoPessoa *apresentacao);
    void setApresentacaoProjeto(IApresentacaoProjeto *apresentacao);
    void setApresentacaoPlanoDeSprint(IApresentacaoPlanoDeSprint *apresentacao); // INCLUÍDO

    void executar(); // Menu Inicial (Deslogado)
};

#endif // CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED