#ifndef CONTAINER_PESSOA_HPP_INCLUDED
#define CONTAINER_PESSOA_HPP_INCLUDED

#include <vector>
#include "../ENTIDADES/Pessoa.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class ContainerPessoa
 * @brief Armazena objetos da entidade Pessoa em mem&oacute;ria.
 *
 * Esta classe pertence &agrave; camada de servi&ccedil;o e funciona como estrutura
 * de armazenamento tempor&aacute;rio para pessoas cadastradas no sistema.
 */
class ContainerPessoa {
private:
    std::vector<Pessoa> pessoas;

public:
    /**
     * @brief Insere uma pessoa no cont&ecirc;iner.
     *
     * @param pessoa Entidade Pessoa a ser inserida.
     * @return true se a pessoa for inserida com sucesso.
     */
    bool inserir(const Pessoa &pessoa);

    /**
     * @brief Busca uma pessoa pelo email.
     *
     * @param email Email que identifica a pessoa.
     * @param pessoa Refer&ecirc;ncia que recebe a pessoa encontrada.
     * @return true se a pessoa for encontrada.
     */
    bool buscar(const Email &email, Pessoa &pessoa);

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param pessoa Entidade Pessoa com os dados atualizados.
     * @return true se a pessoa for atualizada com sucesso.
     */
    bool atualizar(const Pessoa &pessoa);

    /**
     * @brief Remove uma pessoa pelo email.
     *
     * @param email Email que identifica a pessoa.
     * @return true se a pessoa for removida com sucesso.
     */
    bool remover(const Email &email);
};

#endif
