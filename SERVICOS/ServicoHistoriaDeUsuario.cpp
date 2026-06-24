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

bool ServicoHistoriaDeUsuario::listarPorProjeto(const Codigo &codigoProjeto) {
    (void) codigoProjeto;

    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return !containerHistoriaDeUsuario->listarTodos().empty();
}

bool ServicoHistoriaDeUsuario::listarPorPlanoDeSprint(const Codigo &codigoPlano) {
    (void) codigoPlano;

    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return !containerHistoriaDeUsuario->listarTodos().empty();
}
