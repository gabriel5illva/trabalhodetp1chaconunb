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
    std::vector<HistoriaDeUsuario> historiasFiltradas;

    if (containerHistoriaDeUsuario == nullptr) {
        return historiasFiltradas;
    }

    // Obtém todas as histórias do container de memória
    std::vector<HistoriaDeUsuario> todasHistorias = containerHistoriaDeUsuario->listarTodos();

    // Filtra apenas as que pertencem ao código do projeto informado
    for (const HistoriaDeUsuario &h : todasHistorias) {
        if (h.getProjetoAssociado().getCodigo() == codigoProjeto.getCodigo()) {
            historiasFiltradas.push_back(h);
        }
    }

    return historiasFiltradas;
}

bool ServicoHistoriaDeUsuario::listarPorPlanoDeSprint(const Codigo &codigoPlano) {
    (void) codigoPlano;

    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return !containerHistoriaDeUsuario->listarTodos().empty();
}
