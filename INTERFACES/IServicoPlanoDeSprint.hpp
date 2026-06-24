#ifndef ISERVICOPLANODESPRINT_HPP_INCLUDED
#define ISERVICOPLANODESPRINT_HPP_INCLUDED

#include "../ENTIDADES/PlanoDeSprint.hpp"
#include "../DOMINIOS/Codigo.hpp"

/**
 * @class IServicoPlanoDeSprint
 * @brief Interface para os serviços de gerenciamento de Planos de Sprint (CRUD e Listagem).
 */
class IServicoPlanoDeSprint {
public:
    virtual bool criar(const PlanoDeSprint &plano) = 0;
    virtual PlanoDeSprint ler(const Codigo &codigo) = 0;
    virtual bool atualizar(const PlanoDeSprint &plano) = 0;
    virtual bool excluir(const Codigo &codigo) = 0;
    
    // Método específico mapeado da sua classe de serviço
    virtual bool listarPorProjeto(const Codigo &codigoProjeto) = 0;
    
    virtual ~IServicoPlanoDeSprint() = default;
};

#endif // ISERVICOPLANODESPRINTHPP_INCLUDED