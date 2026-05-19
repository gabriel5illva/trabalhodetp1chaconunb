#ifndef ISERVICE_PLANO_DE_SPRINT_HPP_INCLUDED
#define ISERVICE_PLANO_DE_SPRINT_HPP_INCLUDED

#include "../entidades/PlanoDeSprint.hpp"
#include "../dominios/Codigo.hpp"

/**
 * @class IServicePlanoDeSprint
 * @brief Interface abstrata para os servi&ccedil;os relacionados a PlanoDeSprint.
 *
 * Esta interface declara as opera&ccedil;&otilde;es de cria&ccedil;&atilde;o, leitura,
 * atualiza&ccedil;&atilde;o, exclus&atilde;o e listagem de planos de sprint.
 */
class IServicePlanoDeSprint {
public:
    /**
     * @brief Cria um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint a ser criada.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool criar(const PlanoDeSprint &plano) = 0;

    /**
     * @brief L&ecirc; um plano de sprint a partir do c&oacute;digo.
     *
     * @param codigo Codigo que identifica o plano de sprint.
     * @return Entidade PlanoDeSprint encontrada.
     */
    virtual PlanoDeSprint ler(const Codigo &codigo) = 0;

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint com dados atualizados.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool atualizar(const PlanoDeSprint &plano) = 0;

    /**
     * @brief Exclui um plano de sprint.
     *
     * @param codigo Codigo que identifica o plano de sprint.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool excluir(const Codigo &codigo) = 0;

    /**
     * @brief Lista planos de sprint associados a um projeto.
     *
     * @param codigoProjeto Codigo que identifica o projeto.
     * @return true se a opera&ccedil;&atilde;o for realizada com sucesso.
     */
    virtual bool listarPorProjeto(const Codigo &codigoProjeto) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicePlanoDeSprint() {}
};

#endif
