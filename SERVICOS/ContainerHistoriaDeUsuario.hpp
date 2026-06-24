#ifndef CONTAINER_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define CONTAINER_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include <vector>
#include "../ENTIDADES/HistoriaDeUsuario.hpp"
#include "../DOMINIOS/Codigo.hpp"

/**
 * @class ContainerHistoriaDeUsuario
 * @brief Armazena objetos da entidade HistoriaDeUsuario em mem&oacute;ria.
 *
 * Esta classe pertence &agrave; camada de servi&ccedil;o e funciona como estrutura
 * de armazenamento tempor&aacute;rio para hist&oacute;rias de usu&aacute;rio cadastradas no sistema.
 */
class ContainerHistoriaDeUsuario {
private:
    std::vector<HistoriaDeUsuario> historias;

public:
    /**
     * @brief Insere uma hist&oacute;ria de usu&aacute;rio no cont&ecirc;iner.
     *
     * @param historia Entidade HistoriaDeUsuario a ser inserida.
     * @return true se a hist&oacute;ria for inserida com sucesso.
     */
    bool inserir(const HistoriaDeUsuario &historia);

    /**
     * @brief Busca uma hist&oacute;ria de usu&aacute;rio pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @param historia Refer&ecirc;ncia que recebe a hist&oacute;ria encontrada.
     * @return true se a hist&oacute;ria for encontrada.
     */
    bool buscar(const Codigo &codigo, HistoriaDeUsuario &historia);

    /**
     * @brief Atualiza os dados de uma hist&oacute;ria de usu&aacute;rio.
     *
     * @param historia Entidade HistoriaDeUsuario com os dados atualizados.
     * @return true se a hist&oacute;ria for atualizada com sucesso.
     */
    bool atualizar(const HistoriaDeUsuario &historia);

    /**
     * @brief Remove uma hist&oacute;ria de usu&aacute;rio pelo c&oacute;digo.
     *
     * @param codigo C&oacute;digo que identifica a hist&oacute;ria de usu&aacute;rio.
     * @return true se a hist&oacute;ria for removida com sucesso.
     */
    bool remover(const Codigo &codigo);

    /**
     * @brief Retorna todas as hist&oacute;rias de usu&aacute;rio armazenadas.
     *
     * @return Vetor com as hist&oacute;rias de usu&aacute;rio cadastradas.
     */
    std::vector<HistoriaDeUsuario> listarTodos();
};

#endif
