#ifndef SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../interfaces/IServiceHistoriaDeUsuario.hpp"

/**
 * @class ServicoHistoriaDeUsuario
 * @brief Implementa os servicos relacionados a HistoriaDeUsuario.
 *
 * Esta classe realiza a interface IServiceHistoriaDeUsuario e concentra
 * operacoes da camada de servico relacionadas a entidade HistoriaDeUsuario.
 */
class ServicoHistoriaDeUsuario : public IServiceHistoriaDeUsuario {
public:
    /**
     * @brief Cria uma nova historia de usuario.
     *
     * @param historia Objeto da entidade HistoriaDeUsuario.
     * @return true se a operacao for realizada com sucesso.
     */
    bool criar(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Le uma historia de usuario a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return Objeto da entidade HistoriaDeUsuario.
     */
    HistoriaDeUsuario ler(const Codigo &codigo) override;

    /**
     * @brief Atualiza os dados de uma historia de usuario.
     *
     * @param historia Objeto da entidade HistoriaDeUsuario.
     * @return true se a operacao for realizada com sucesso.
     */
    bool atualizar(const HistoriaDeUsuario &historia) override;

    /**
     * @brief Exclui uma historia de usuario a partir do codigo.
     *
     * @param codigo Objeto da classe de dominio Codigo.
     * @return true se a operacao for realizada com sucesso.
     */
    bool excluir(const Codigo &codigo) override;

    /**
     * @brief Associa uma pessoa a uma historia de usuario.
     *
     * @param codigo Codigo da historia de usuario.
     * @param email Email da pessoa associada.
     * @return true se a operacao for realizada com sucesso.
     */
    bool associarPessoa(const Codigo &codigo, const Email &email) override;

    /**
     * @brief Remove a associacao entre uma pessoa e uma historia de usuario.
     *
     * @param codigo Codigo da historia de usuario.
     * @param email Email da pessoa associada.
     * @return true se a operacao for realizada com sucesso.
     */
    bool removerPessoa(const Codigo &codigo, const Email &email) override;

    /**
     * @brief Altera o estado de uma historia de usuario.
     *
     * @param codigo Codigo da historia de usuario.
     * @param estado Novo estado da historia de usuario.
     * @return true se a operacao for realizada com sucesso.
     */
    bool alterarEstado(const Codigo &codigo, const Estado &estado) override;
};

#endif
