#ifndef SERVICO_PROJETO_HPP_INCLUDED
#define SERVICO_PROJETO_HPP_INCLUDED

#include "../interfaces/IServiceProjeto.hpp"

/**
 * @class ServicoProjeto
 * @brief Implementa os servi&ccedil;os relacionados a Projeto.
 *
 * Esta classe realiza a interface IServiceProjeto e concentra
 * opera&ccedil;&otilde;es da camada de servi&ccedil;o relacionadas &agrave; entidade Projeto.
 */
class ServicoProjeto : public IServiceProjeto {
public:
    bool criar(const Projeto &projeto) override;
    Projeto ler(const Codigo &codigo) override;
    bool atualizar(const Projeto &projeto) override;
    bool excluir(const Codigo &codigo) override;
    bool listarPorPessoa(const Email &email) override;
};

#endif
