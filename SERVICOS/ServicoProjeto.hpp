#ifndef SERVICO_PROJETO_HPP_INCLUDED
#define SERVICO_PROJETO_HPP_INCLUDED

#include "../INTERFACES/IServicoProjeto.hpp"
#include "ContainerProjeto.hpp"

/**
 * @class ServicoProjeto
 * @brief Implementa os servi&ccedil;os relacionados a projetos.
 *
 * Esta classe realiza a interface IServicoProjeto e utiliza
 * ContainerProjeto para armazenar e manipular projetos cadastrados
 * no sistema.
 */
class ServicoProjeto : public IServicoProjeto {
private:
    ContainerProjeto *containerProjeto;

public:
    /**
     * @brief Inicializa o ponteiro do cont&ecirc;iner como nulo.
     */
    ServicoProjeto();

    /**
     * @brief Define o cont&ecirc;iner de projetos utilizado pelo servi&ccedil;o.
     *
     * @param containerProjeto Ponteiro para ContainerProjeto.
     */
    void setContainerProjeto(ContainerProjeto *containerProjeto);

    /**
     * @brief Cria um novo projeto.
     *
     * @param projeto Entidade Projeto a ser cadastrada.
     * @return true se o projeto for cadastrado com sucesso.
     */
    bool criar(const Projeto &projeto) override;

    /**
     * @brief Consulta um projeto pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo do projeto.
     * @return Entidade Projeto encontrada.
     */
    Projeto ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Entidade Projeto com os dados atualizados.
     * @return true se o projeto for atualizado com sucesso.
     */
    bool atualizar(const Projeto &projeto) override;

    /**
     * @brief Exclui um projeto.
     *
     * @param codigo C&oacute;digo do projeto.
     * @return true se o projeto for exclu&iacute;do com sucesso.
     */
    bool excluir(const Codigo &codigo) override;

    /**
     * @brief Lista projetos associados a uma pessoa.
     *
     * @param email Email da pessoa associada aos projetos.
     * @return true se houver projetos cadastrados.
     */
    bool listarPorPessoa(const Email &email) override;
};

#endif
