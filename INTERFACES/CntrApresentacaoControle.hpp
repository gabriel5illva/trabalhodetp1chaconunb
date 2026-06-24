#ifndef CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED
#define CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoAutenticacao.hpp"
#include "../INTERFACES/IApresentacaoUsuario.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class CntrApresentacaoControle
 * @brief Controladora principal responsável pelo fluxo geral de navegação do sistema.
 */
class CntrApresentacaoControle {
private:
    IApresentacaoAutenticacao *apresentacaoAutenticacao;
    IApresentacaoUsuario *apresentacaoUsuario;

public:
    void setApresentacaoAutenticacao(IApresentacaoAutenticacao *apresentacao);
    void setApresentacaoUsuario(IApresentacaoUsuario *apresentacao);

    /**
     * @brief Inicia o loop do menu inicial (Autenticar/Cadastrar/Sair).
     */
    void executar();
};

#endif // CNTRAPRESENTACAOCONTROLE_HPP_INCLUDED
