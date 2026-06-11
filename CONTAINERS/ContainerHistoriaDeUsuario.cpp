#include "../../Headers/SERVICOS/ContainerHistoriaDeUsuario.hpp"

bool ContainerHistoriaDeUsuario::inserir(const HistoriaDeUsuario &historia) {
    HistoriaDeUsuario historiaEncontrada;

    if (buscar(historia.getCodigo(), historiaEncontrada)) {
        return false;
    }

    historias.push_back(historia);
    return true;
}

bool ContainerHistoriaDeUsuario::buscar(const Codigo &codigo, HistoriaDeUsuario &historia) {
    for (HistoriaDeUsuario h : historias) {
        if (h.getCodigo().getCodigo() == codigo.getCodigo()) {
            historia = h;
            return true;
        }
    }

    return false;
}

bool ContainerHistoriaDeUsuario::atualizar(const HistoriaDeUsuario &historia) {
    for (int i = 0; i < (int) historias.size(); i++) {
        if (historias[i].getCodigo().getCodigo() == historia.getCodigo().getCodigo()) {
            historias[i] = historia;
            return true;
        }
    }

    return false;
}

bool ContainerHistoriaDeUsuario::remover(const Codigo &codigo) {
    for (int i = 0; i < (int) historias.size(); i++) {
        if (historias[i].getCodigo().getCodigo() == codigo.getCodigo()) {
            historias.erase(historias.begin() + i);
            return true;
        }
    }

    return false;
}

std::vector<HistoriaDeUsuario> ContainerHistoriaDeUsuario::listarTodos() {
    return historias;
}
