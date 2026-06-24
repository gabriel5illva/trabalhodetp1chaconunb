#ifndef CONTAINER_PROJETO_HPP_INCLUDED
#define CONTAINER_PROJETO_HPP_INCLUDED

#include <vector>
#include "../ENTIDADES/Projeto.hpp"
#include "../DOMINIOS/Codigo.hpp"

/**
 * @class ContainerProjeto
 * @brief Armazena objetos da entidade Projeto em mem&oacute;ria.
 *
 * Esta classe pertence &agrave; camada de servi&ccedil;o e funciona como estrutura
 * de armazenamento tempor&aacute;rio para projetos cadastrados no sistema.
 */
class ContainerProjeto {
private:
    std::vector<Projeto> projetos;

public:
    /**
     * @brief Insere um projeto no cont&ecirc;iner.
     *
     * @param projeto Entidade Projeto a ser inserida.
     * @return true se o projeto for inserido com sucesso.
     */
    bool inserir(const Projeto &projeto);

    /**
     * @brief Busca um projeto pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o projeto.
     * @param projeto Refer&ecirc;ncia que recebe o projeto encontrado.
     * @return true se o projeto for encontrado.
     */
    bool buscar(const Codigo &codigo, Projeto &projeto);

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Entidade Projeto com os dados atualizados.
     * @return true se o projeto for atualizado com sucesso.
     */
    bool atualizar(const Projeto &projeto);

    /**
     * @brief Remove um projeto pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica o projeto.
     * @return true se o projeto for removido com sucesso.
     */
    bool remover(const Codigo &codigo);

    /**
     * @brief Retorna todos os projetos armazenados.
     *
     * @return Vetor com os projetos cadastrados.
     */
    std::vector<Projeto> listarTodos();
};

#endif
