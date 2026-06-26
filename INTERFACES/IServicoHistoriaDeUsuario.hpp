#ifndef ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED
#define ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED


#include <vector>
#include "../ENTIDADES/HistoriaDeUsuario.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class IServicoHistoriaDeUsuario
 * @brief Interface para os serviços de gerenciamento de Histórias de Usuário (CRUD e Listagens).
 */
class IServicoHistoriaDeUsuario {
public:
    virtual bool criar(const HistoriaDeUsuario &historia) = 0;
    virtual HistoriaDeUsuario ler(const Codigo &codigo) = 0;
    virtual bool atualizar(const HistoriaDeUsuario &historia) = 0;
    virtual bool excluir(const Codigo &codigo) = 0;
    
    // Métodos específicos mapeados da sua classe de serviço
    virtual std::vector<HistoriaDeUsuario> listarPorProjeto(const Codigo &codigoProjeto) = 0;
    virtual std::vector<HistoriaDeUsuario> listarPorPlanoDeSprint(const Codigo &codigoPlano) = 0;
    virtual std::vector<HistoriaDeUsuario> listarPorPessoa(const Email &email) = 0;
    
    virtual ~IServicoHistoriaDeUsuario() = default;
};

#endif // ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED