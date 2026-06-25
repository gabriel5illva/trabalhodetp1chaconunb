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

std::vector<Projeto> ServicoProjeto::listarPorPessoa(const Email &email) {
    std::vector<Projeto> projetosFiltrados; // Vetor que começará vazio

    if (containerProjeto == nullptr) {
        return projetosFiltrados;
    }

    // Obtém todos os projetos salvos na memória
    std::vector<Projeto> todosProjetos = containerProjeto->listarTodos();
    
    // Filtra adicionando ao vetor apenas os que possuem o e-mail do criador
    for (const Projeto &p : todosProjetos) {
        if (p.getEmailAssociado().getEmail() == email.getEmail()) {
            projetosFiltrados.push_back(p);
        }
    }

    return projetosFiltrados; // Retorna a lista pronta (pode ser vazia)
}
