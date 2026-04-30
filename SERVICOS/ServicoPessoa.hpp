#ifndef SERVICO_PESSOA_HPP_INCLUDED
#define SERVICO_PESSOA_HPP_INCLUDED

#include "../interfaces/IServicePessoa.hpp"

class ServicoPessoa : public IServicePessoa {
public:
    bool criar(const Pessoa &) override;
    Pessoa ler(const Email &) override;
    bool atualizar(const Pessoa &) override;
    bool excluir(const Email &) override;
};

#endif
