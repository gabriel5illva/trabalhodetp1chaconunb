#ifndef ISERVICOAUTENTICACAO_HPP_INCLUDED
#define ISERVICOAUTENTICACAO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Senha.hpp"

/**
 * @class IServicoAutenticacao
 * @brief Interface para o serviço de autenticação.
 */
class IServicoAutenticacao {
public:
    virtual bool autenticar(const Email &email, const Senha &senha) = 0;

    virtual ~IServicoAutenticacao() = default;
};

#endif // ISERVICOAUTENTICACAO_HPP_INCLUDED
