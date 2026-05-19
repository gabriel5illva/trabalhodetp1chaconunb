#ifndef SERVICO_PESSOA_HPP_INCLUDED
#define SERVICO_PESSOA_HPP_INCLUDED

#include "../interfaces/IServicePessoa.hpp"

/**
 * @class ServicoPessoa
 * @brief Implementa os servi&ccedil;os relacionados a Pessoa.
 *
 * Esta classe realiza a interface IServicePessoa e concentra
 * opera&ccedil;&otilde;es da camada de servi&ccedil;o relacionadas &agrave; entidade Pessoa.
 */
class ServicoPessoa : public IServicePessoa {
public:
    bool criar(const Pessoa &pessoa) override;
    Pessoa ler(const Email &email) override;
    bool atualizar(const Pessoa &pessoa) override;
    bool excluir(const Email &email) override;
};

#endif
