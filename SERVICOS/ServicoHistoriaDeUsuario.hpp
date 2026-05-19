#ifndef SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../interfaces/IServiceHistoriaDeUsuario.hpp"

/**
 * @class ServicoHistoriaDeUsuario
 * @brief Implementa os servi&ccedil;os relacionados a HistoriaDeUsuario.
 *
 * Esta classe realiza a interface IServiceHistoriaDeUsuario e concentra
 * opera&ccedil;&otilde;es da camada de servi&ccedil;o relacionadas &agrave; entidade HistoriaDeUsuario.
 */
class ServicoHistoriaDeUsuario : public IServiceHistoriaDeUsuario {
public:
    bool criar(const HistoriaDeUsuario &historia) override;
    HistoriaDeUsuario ler(const Codigo &codigo) override;
    bool atualizar(const HistoriaDeUsuario &historia) override;
    bool excluir(const Codigo &codigo) override;

    bool associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;
    bool removerPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;

    bool listarPorProjeto(const Codigo &codigoProjeto) override;
    bool listarPorPlanoDeSprint(const Codigo &codigoPlano) override;
    bool listarPorPessoa(const Email &emailPessoa) override;

    bool moverParaPlanoDeSprint(const Codigo &codigoHistoria,
                                const Codigo &codigoProjeto,
                                const Codigo &codigoPlano) override;

    bool alterarEstado(const Codigo &codigoHistoria, const Estado &estado) override;
};

#endif
