#include "ServicoHistoriaDeUsuario.hpp"

ServicoHistoriaDeUsuario::ServicoHistoriaDeUsuario() {
    containerHistoriaDeUsuario = nullptr;
}

void ServicoHistoriaDeUsuario::setContainerHistoriaDeUsuario(
    ContainerHistoriaDeUsuario *containerHistoriaDeUsuario
) {
    this->containerHistoriaDeUsuario = containerHistoriaDeUsuario;
}

bool ServicoHistoriaDeUsuario::criar(const HistoriaDeUsuario &historia) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->inserir(historia);
}

HistoriaDeUsuario ServicoHistoriaDeUsuario::ler(const Codigo &codigo) {
    HistoriaDeUsuario historia;

    if (containerHistoriaDeUsuario == nullptr) {
        return historia;
    }

    containerHistoriaDeUsuario->buscar(codigo, historia);

    return historia;
}

bool ServicoHistoriaDeUsuario::atualizar(const HistoriaDeUsuario &historia) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->atualizar(historia);
}

bool ServicoHistoriaDeUsuario::excluir(const Codigo &codigo) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->remover(codigo);
}

std::vector<HistoriaDeUsuario> ServicoHistoriaDeUsuario::listarPorProjeto(const Codigo &codigoProjeto) {
    std::vector<HistoriaDeUsuario> filtradas;
    if (containerHistoriaDeUsuario == nullptr) return filtradas;

    for (const HistoriaDeUsuario &h : containerHistoriaDeUsuario->listarTodos()) {
        if (h.getProjetoAssociado().getCodigo() == codigoProjeto.getCodigo()) {
            filtradas.push_back(h);
        }
    }
    return filtradas;
}

std::vector<HistoriaDeUsuario> ServicoHistoriaDeUsuario::listarPorPlanoDeSprint(const Codigo &codigoPlano) {
    std::vector<HistoriaDeUsuario> filtradas;
    if (containerHistoriaDeUsuario == nullptr) return filtradas;

    for (const HistoriaDeUsuario &h : containerHistoriaDeUsuario->listarTodos()) {
        if (h.getSprintAssociada().getCodigo() == codigoPlano.getCodigo()) {
            filtradas.push_back(h);
        }
    }
    return filtradas;
}
