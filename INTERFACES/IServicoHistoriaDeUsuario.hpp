#ifndef ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED
#define ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED

#include "../ENTIDADES/HistoriaDeUsuario.hpp"
#include "../DOMINIOS/Codigo.hpp"

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
    virtual bool listarPorProjeto(const Codigo &codigoProjeto) = 0;
    virtual bool listarPorPlanoDeSprint(const Codigo &codigoPlano) = 0;
    
    virtual ~IServicoHistoriaDeUsuario() = default;
};

#endif // ISERVICOHISTORIADEUSUARIO_HPP_INCLUDED