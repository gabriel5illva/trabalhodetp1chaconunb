#include "../../Headers/SERVICOS/ServicoRequisitos.hpp"

ServicoRequisitos::ServicoRequisitos() {
    containerHistoriaDeUsuario = nullptr;
    containerProjeto = nullptr;
    containerPlanoDeSprint = nullptr;
    containerPessoa = nullptr;
}

void ServicoRequisitos::setContainerHistoriaDeUsuario(
    ContainerHistoriaDeUsuario *containerHistoriaDeUsuario
) {
    this->containerHistoriaDeUsuario = containerHistoriaDeUsuario;
}

void ServicoRequisitos::setContainerProjeto(ContainerProjeto *containerProjeto) {
    this->containerProjeto = containerProjeto;
}

void ServicoRequisitos::setContainerPlanoDeSprint(
    ContainerPlanoDeSprint *containerPlanoDeSprint
) {
    this->containerPlanoDeSprint = containerPlanoDeSprint;
}

void ServicoRequisitos::setContainerPessoa(ContainerPessoa *containerPessoa) {
    this->containerPessoa = containerPessoa;
}

bool ServicoRequisitos::criarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->inserir(historia);
}

HistoriaDeUsuario ServicoRequisitos::lerHistoriaDeUsuario(const Codigo &codigo) {
    HistoriaDeUsuario historia;

    if (containerHistoriaDeUsuario == nullptr) {
        return historia;
    }

    containerHistoriaDeUsuario->buscar(codigo, historia);
    return historia;
}

bool ServicoRequisitos::atualizarHistoriaDeUsuario(const HistoriaDeUsuario &historia) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->atualizar(historia);
}

bool ServicoRequisitos::excluirHistoriaDeUsuario(const Codigo &codigo) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    return containerHistoriaDeUsuario->remover(codigo);
}

bool ServicoRequisitos::associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    HistoriaDeUsuario historia;

    if (!containerHistoriaDeUsuario->buscar(codigoHistoria, historia)) {
        return false;
    }

    if (containerPessoa != nullptr) {
        Pessoa pessoa;

        if (!containerPessoa->buscar(emailPessoa, pessoa)) {
            return false;
        }
    }

    for (AssociacaoHistoriaPessoa associacao : associacoesPessoa) {
        if (associacao.codigoHistoria.getCodigo() == codigoHistoria.getCodigo() &&
            associacao.emailPessoa.getEmail() == emailPessoa.getEmail()) {
            return false;
        }
    }

    AssociacaoHistoriaPessoa novaAssociacao;
    novaAssociacao.codigoHistoria = codigoHistoria;
    novaAssociacao.emailPessoa = emailPessoa;

    associacoesPessoa.push_back(novaAssociacao);

    return true;
}

bool ServicoRequisitos::removerPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    for (int i = 0; i < (int) associacoesPessoa.size(); i++) {
        if (associacoesPessoa[i].codigoHistoria.getCodigo() == codigoHistoria.getCodigo() &&
            associacoesPessoa[i].emailPessoa.getEmail() == emailPessoa.getEmail()) {
            associacoesPessoa.erase(associacoesPessoa.begin() + i);
            return true;
        }
    }

    return false;
}

bool ServicoRequisitos::listarHistoriasPorProjeto(const Codigo &codigoProjeto) {
    for (AssociacaoHistoriaProjeto associacao : associacoesProjeto) {
        if (associacao.codigoProjeto.getCodigo() == codigoProjeto.getCodigo()) {
            return true;
        }
    }

    return false;
}

bool ServicoRequisitos::listarHistoriasPorPlanoDeSprint(const Codigo &codigoPlano) {
    for (AssociacaoHistoriaPlano associacao : associacoesPlano) {
        if (associacao.codigoPlano.getCodigo() == codigoPlano.getCodigo()) {
            return true;
        }
    }

    return false;
}

bool ServicoRequisitos::listarHistoriasPorPessoa(const Email &emailPessoa) {
    for (AssociacaoHistoriaPessoa associacao : associacoesPessoa) {
        if (associacao.emailPessoa.getEmail() == emailPessoa.getEmail()) {
            return true;
        }
    }

    return false;
}

bool ServicoRequisitos::moverParaPlanoDeSprint(const Codigo &codigoHistoria,
                                               const Codigo &codigoProjeto,
                                               const Codigo &codigoPlano) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    HistoriaDeUsuario historia;

    if (!containerHistoriaDeUsuario->buscar(codigoHistoria, historia)) {
        return false;
    }

    if (containerProjeto != nullptr) {
        Projeto projeto;

        if (!containerProjeto->buscar(codigoProjeto, projeto)) {
            return false;
        }
    }

    if (containerPlanoDeSprint != nullptr) {
        PlanoDeSprint plano;

        if (!containerPlanoDeSprint->buscar(codigoPlano, plano)) {
            return false;
        }
    }

    bool projetoJaAssociado = false;

    for (AssociacaoHistoriaProjeto associacao : associacoesProjeto) {
        if (associacao.codigoHistoria.getCodigo() == codigoHistoria.getCodigo() &&
            associacao.codigoProjeto.getCodigo() == codigoProjeto.getCodigo()) {
            projetoJaAssociado = true;
        }
    }

    if (!projetoJaAssociado) {
        AssociacaoHistoriaProjeto novaAssociacaoProjeto;
        novaAssociacaoProjeto.codigoHistoria = codigoHistoria;
        novaAssociacaoProjeto.codigoProjeto = codigoProjeto;

        associacoesProjeto.push_back(novaAssociacaoProjeto);
    }

    for (int i = 0; i < (int) associacoesPlano.size(); i++) {
        if (associacoesPlano[i].codigoHistoria.getCodigo() == codigoHistoria.getCodigo()) {
            associacoesPlano.erase(associacoesPlano.begin() + i);
            break;
        }
    }

    AssociacaoHistoriaPlano novaAssociacaoPlano;
    novaAssociacaoPlano.codigoHistoria = codigoHistoria;
    novaAssociacaoPlano.codigoPlano = codigoPlano;

    associacoesPlano.push_back(novaAssociacaoPlano);

    return true;
}

bool ServicoRequisitos::alterarEstado(const Codigo &codigoHistoria, const Estado &estado) {
    if (containerHistoriaDeUsuario == nullptr) {
        return false;
    }

    HistoriaDeUsuario historia;

    if (!containerHistoriaDeUsuario->buscar(codigoHistoria, historia)) {
        return false;
    }

    historia.setEstado(estado);

    return containerHistoriaDeUsuario->atualizar(historia);
}
