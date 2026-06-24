#ifndef CNTRAPRESENTACAOUSUARIO_HPP_INCLUDED
#define CNTRAPRESENTACAOUSUARIO_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoUsuario.hpp"
#include "../INTERFACES/IServicoUsuarios.hpp"
#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Senha.hpp"
#include "../ENTIDADES/Pessoa.hpp"

class CntrApresentacaoUsuario : public IApresentacaoUsuario {
private:
    IServicoUsuarios *servicoUsuarios;

public:
    void cadastrar() override;
    void executar(const Email &email) override; // Menu principal pós-login
    void setServicoUsuarios(IServicoUsuarios *servico) override;
};

#endif // CNTRAPRESENTACAOUSUARIO_HPP_INCLUDED
