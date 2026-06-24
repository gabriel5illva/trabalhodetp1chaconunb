#include "ContainerProjeto.hpp"

bool ContainerProjeto::inserir(const Projeto &projeto) {
    Projeto projetoEncontrado;

    if (buscar(projeto.getCodigo(), projetoEncontrado)) {
        return false;
    }

    projetos.push_back(projeto);
    return true;
}

bool ContainerProjeto::buscar(const Codigo &codigo, Projeto &projeto) {
    for (Projeto p : projetos) {
        if (p.getCodigo().getCodigo() == codigo.getCodigo()) {
            projeto = p;
            return true;
        }
    }

    return false;
}

bool ContainerProjeto::atualizar(const Projeto &projeto) {
    for (int i = 0; i < (int) projetos.size(); i++) {
        if (projetos[i].getCodigo().getCodigo() == projeto.getCodigo().getCodigo()) {
            projetos[i] = projeto;
            return true;
        }
    }

    return false;
}

bool ContainerProjeto::remover(const Codigo &codigo) {
    for (int i = 0; i < (int) projetos.size(); i++) {
        if (projetos[i].getCodigo().getCodigo() == codigo.getCodigo()) {
            projetos.erase(projetos.begin() + i);
            return true;
        }
    }

    return false;
}

std::vector<Projeto> ContainerProjeto::listarTodos() {
    return projetos;
}
