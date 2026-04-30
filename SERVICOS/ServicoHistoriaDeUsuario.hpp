#ifndef SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED
#define SERVICO_HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "../interfaces/IServiceHistoriaDeUsuario.hpp"

class ServicoHistoriaDeUsuario : public IServiceHistoriaDeUsuario {
public:
    bool criar(const HistoriaDeUsuario &) override;
    HistoriaDeUsuario ler(const Codigo &) override;
    bool atualizar(const HistoriaDeUsuario &) override;
    bool excluir(const Codigo &) override;

    bool associarPessoa(const Codigo &, const Email &) override;
    bool removerPessoa(const Codigo &, const Email &) override;
    bool alterarEstado(const Codigo &, const Estado &) override;
};

#endif
