#ifndef ISERVICOAUTENTICACAO_HPP_INCLUDED
#define ISERVICOAUTENTICACAO_HPP_INCLUDED

#include "../DOMINIOS/email.hpp"
#include "../DOMINIOS/senha.hpp"
#include "../DOMINIOS/papel.hpp"
#include "../DOMINIOS/nome.hpp"

/**
 * @class IServicoAutenticacao
 * @brief Interface para o servi�o de autentica��o.
 */
class IServicoAutenticacao {
public:
    virtual bool autenticar(const Email &email, const Senha &senha) = 0;

    virtual ~IServicoAutenticacao() = default;
};

#endif // ISERVICOAUTENTICACAO_HPP_INCLUDED
