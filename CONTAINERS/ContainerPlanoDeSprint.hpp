#ifndef CONTAINER_PLANO_DE_SPRINT_HPP_INCLUDED
#define CONTAINER_PLANO_DE_SPRINT_HPP_INCLUDED

#include <vector>
#include "../ENTIDADES/PlanoDeSprint.hpp"
#include "../DOMINIOS/Codigo.hpp"

/**
 * @class ContainerPlanoDeSprint
 * @brief Armazena objetos da entidade PlanoDeSprint em mem&oacute;ria.
 *
 * Esta classe pertence &agrave; camada de servi&ccedil;o e funciona como estrutura
 * de armazenamento tempor&aacute;rio para planos de sprint cadastrados no sistema.
 */
class ContainerPlanoDeSprint {
private:
    std::vector<PlanoDeSprint> planos;

public:
    /**
     * @brief Insere um plano de sprint no cont&ecirc;iner.
     *
     * @param plano Entidade PlanoDeSprint a ser inserida.
     * @return true se o plano for inserido com sucesso.
     */
    bool inserir(const PlanoDeSprint &plano);

    /**
     * @brief Busca um plano de sprint pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o plano de sprint.
     * @param plano Refer&ecirc;ncia que recebe o plano encontrado.
     * @return true se o plano for encontrado.
     */
    bool buscar(const Codigo &codigo, PlanoDeSprint &plano);

    /**
     * @brief Atualiza os dados de um plano de sprint.
     *
     * @param plano Entidade PlanoDeSprint com os dados atualizados.
     * @return true se o plano for atualizado com sucesso.
     */
    bool atualizar(const PlanoDeSprint &plano);

    /**
     * @brief Remove um plano de sprint pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o plano de sprint.
     * @return true se o plano for removido com sucesso.
     */
    bool remover(const Codigo &codigo);

    /**
     * @brief Retorna todos os planos de sprint armazenados.
     *
     * @return Vetor com os planos de sprint cadastrados.
     */
    std::vector<PlanoDeSprint> listarTodos();
};

#endif
