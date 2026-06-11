#ifndef ISERVICO_AUTENTICACAO_HPP_INCLUDED
#define ISERVICO_AUTENTICACAO_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Senha.hpp"
#include "../DOMINIOS/Nome.hpp"
#include "../DOMINIOS/Papel.hpp"

/**
 * @class IServicoAutenticacao
 * @brief Interface de servi&ccedil;o para as opera&ccedil;&otilde;es relacionadas &agrave; autentica&ccedil;&atilde;o.
 *
 * Esta interface define o contrato que deve ser provido pelo M&oacute;dulo Servi&ccedil;o Autentica&ccedil;&atilde;o.
 * Ela permite que a camada de apresenta&ccedil;&atilde;o solicite a autentica&ccedil;&atilde;o de um usu&aacute;rio
 * sem depender diretamente da implementa&ccedil;&atilde;o concreta do servi&ccedil;o.
 */
class IServicoAutenticacao {
public:
    /**
     * @brief Autentica um usu&aacute;rio no sistema.
     *
     * @param email Email informado pelo usu&aacute;rio.
     * @param senha Senha informada pelo usu&aacute;rio.
     * @return true se a autentica&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool autenticar(const Email &email,
                            const Senha &senha) = 0;

    /**
     * @brief Castra um usu&aacute;rio no sistema.
     *
     * @param email Email informado pelo usu&aacute;rio.
     * @param senha Senha informada pelo usu&aacute;rio.
     * @param nome Nome informada pelo usu&aacute;rio.
     * @param Papel Papel informada pelo usu&aacute;rio.
     * @return true se a autentica&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool cadastrar(const Email &email,
                           const Senha &senha,
                           const Nome &nome,
                           const Papel &papel) = 0;
    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicoAutenticacao() {}
};

#endif
