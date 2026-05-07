#ifndef SERVICO_PROJETO_HPP_INCLUDED
#define SERVICO_PROJETO_HPP_INCLUDED

#include "../interfaces/IServiceProjeto.hpp"

/**
 * @class ServicoProjeto
 * @brief Implementa os servicos relacionados a Projeto.
 *
 * Esta classe realiza a interface IServiceProjeto e concentra
 * operacoes da camada de servico relacionadas a entidade Projeto.
 */
class ServicoProjeto : public IServiceProjeto {
public:
    /**
     * @brief Cria um novo projeto.
     *
     * @param projeto Objeto da entidade Projeto.
     * @return true se a operacao for realizada com sucesso.
     */
    bool criar(const Projeto &projeto) override;

    /**
     * @brief Le um projeto a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return Objeto da entidade Projeto.
     */
    Projeto ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Objeto da entidade Projeto.
     * @return true se a operacao for realizada com sucesso.
     */
    bool atualizar(const Projeto &projeto) override;

    /**
     * @brief Exclui um projeto a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return true se a operacao for realizada com sucesso.
     */
    bool excluir(const Codigo &codigo) override;
};

#endif
