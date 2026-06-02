#ifndef ISERVICO_PROJETOS_HPP_INCLUDED
#define ISERVICO_PROJETOS_HPP_INCLUDED

#include "../ENTIDADES/Projeto.hpp"
#include "../ENTIDADES/PlanoDeSprint.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class IServicoProjetos
 * @brief Interface de servi&ccedil;o para as opera&ccedil;&otilde;es relacionadas a projetos e planos de sprint.
 *
 * Esta interface define o contrato que deve ser provido pelo M&oacute;dulo Servi&ccedil;o Projetos.
 * Ela concentra as opera&ccedil;&otilde;es relacionadas a Projeto e PlanoDeSprint, permitindo que
 * a camada de apresenta&ccedil;&atilde;o solicite servi&ccedil;os sem depender diretamente da implementa&ccedil;&atilde;o concreta.
 */
class IServicoProjetos {
public:
    /**
     * @brief Cria um projeto.
     *
     * @param projeto Entidade Projeto a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criarProjeto(const Projeto &projeto) = 0;

    /**
     * @brief L&ecirc; um projeto a partir do c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o projeto.
     * @return Entidade Projeto encontrada.
     */
    virtual Projeto lerProjeto(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Entidade Projeto com os dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizarProjeto(const Projeto &projeto) = 0;

    /**
     * @brief Exclui um projeto.
     *
     * @param codigo C&oacute;digo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluirProjeto(const Codigo &codigo) = 0;

    /**
     * @brief Lista os projetos associados a uma pessoa.
     *
     * @param email Email que identifica a pessoa.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarProjetosPorPessoa(const Email &email) = 0;

    /**
     * @brief Cria um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criarPlanoDeSprint(const PlanoDeSprint &plano) = 0;

    /**
     * @brief L&ecirc; um plano de sprint a partir do c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o plano de sprint.
     * @return Entidade PlanoDeSprint encontrada.
     */
    virtual PlanoDeSprint lerPlanoDeSprint(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint com os dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizarPlanoDeSprint(const PlanoDeSprint &plano) = 0;

    /**
     * @brief Exclui um plano de sprint.
     *
     * @param codigo C&oacute;digo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluirPlanoDeSprint(const Codigo &codigo) = 0;

    /**
     * @brief Lista os planos de sprint associados a um projeto.
     *
     * @param codigoProjeto C&oacute;digo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPlanosPorProjeto(const Codigo &codigoProjeto) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicoProjetos() {}
};

#endif
