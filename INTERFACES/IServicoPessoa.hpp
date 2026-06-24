#ifndef ISERVICOPESSOA_HPP_INCLUDED
#define ISERVICOPESSOA_HPP_INCLUDED

#include "../DOMINIOS/Email.hpp"
#include "../ENTIDADES/Pessoa.hpp"

/**
 * @class IServicoPessoa
 * @brief Interface para os serviços de gerenciamento de pessoas (CRUD).
 */
class IServicoPessoa {
public:
    virtual bool criar(const Pessoa &pessoa) = 0;
    virtual Pessoa ler(const Email &email) = 0;
    virtual bool atualizar(const Pessoa &pessoa) = 0;
    virtual bool excluir(const Email &email) = 0;
    
    virtual ~IServicoPessoa() = default;
};

#endif // ISERVICO_PESSOA_HPP_INCLUDED