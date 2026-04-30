#ifndef SERVICO_PROJETO_HPP_INCLUDED
#define SERVICO_PROJETO_HPP_INCLUDED

#include "../interfaces/IServiceProjeto.hpp"

class ServicoProjeto : public IServiceProjeto {
public:
    bool criar(const Projeto &) override;
    Projeto ler(const Codigo &) override;
    bool atualizar(const Projeto &) override;
    bool excluir(const Codigo &) override;
};

#endif
