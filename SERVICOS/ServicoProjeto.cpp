#include "ServicoProjeto.hpp"

ServicoProjeto::ServicoProjeto() {
    containerProjeto = nullptr;
}

void ServicoProjeto::setContainerProjeto(ContainerProjeto *containerProjeto) {
    this->containerProjeto = containerProjeto;
}

bool ServicoProjeto::criar(const Projeto &projeto) {
    if (containerProjeto == nullptr) {
        return false;
    }

    return containerProjeto->inserir(projeto);
}

Projeto ServicoProjeto::ler(const Codigo &codigo) {
    Projeto projeto;

    if (containerProjeto == nullptr) {
        return projeto;
    }

    containerProjeto->buscar(codigo, projeto);

    return projeto;
}

bool ServicoProjeto::atualizar(const Projeto &projeto) {
    if (containerProjeto == nullptr) {
        return false;
    }

    return containerProjeto->atualizar(projeto);
}

bool ServicoProjeto::excluir(const Codigo &codigo) {
    if (containerProjeto == nullptr) {
        return false;
    }

    return containerProjeto->remover(codigo);
}

bool ServicoProjeto::listarPorPessoa(const Email &email) {
    (void) email;

    if (containerProjeto == nullptr) {
        return false;
    }

    return !containerProjeto->listarTodos().empty();
}
