#ifndef ISERVICOUSUARIOS_HPP_INCLUDED
#define ISERVICOUSUARIOS_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "../ENTIDADES/Pessoa.hpp"

/**
 * @class IServicoUsuarios
 * @brief Interface para os serviços de usuários (CRUD).
 */
class IServicoUsuarios {
public:
    virtual bool criar(const Pessoa &pessoa) = 0;
    virtual Pessoa ler(const Email &email) = 0;
    virtual bool atualizar(const Pessoa &pessoa) = 0;
    virtual bool excluir(const Email &email) = 0;

    virtual ~IServicoUsuarios() = default;
};

#endif // ISERVICOUSUARIOS_HPP_INCLUDED
