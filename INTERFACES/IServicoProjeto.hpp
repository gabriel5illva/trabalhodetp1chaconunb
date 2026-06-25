#ifndef ISERVICOPROJETO_HPP_INCLUDED
#define ISERVICOPROJETO_HPP_INCLUDED

#include <vector>
#include "../ENTIDADES/Projeto.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class IServicoProjeto
 * @brief Interface para os serviços de gerenciamento de projetos (CRUD e Listagem).
 */
class IServicoProjeto {
public:
    virtual bool criar(const Projeto &projeto) = 0;
    virtual Projeto ler(const Codigo &codigo) = 0;
    virtual bool atualizar(const Projeto &projeto) = 0;
    virtual bool excluir(const Codigo &codigo) = 0;
    
    virtual std::vector<Projeto> listarPorPessoa(const Email &email) = 0;
    
    virtual ~IServicoProjeto() = default;
};

#endif // ISERVICOPROJETO_HPP_INCLUDED