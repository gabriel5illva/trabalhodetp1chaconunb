#include "../../Headers/servicos/ServicoHistoriaDeUsuario.hpp"

bool ServicoHistoriaDeUsuario::criar(const HistoriaDeUsuario &) {
    return true;
}

HistoriaDeUsuario ServicoHistoriaDeUsuario::ler(const Codigo &) {
    HistoriaDeUsuario historia;
    return historia;
}

bool ServicoHistoriaDeUsuario::atualizar(const HistoriaDeUsuario &) {
    return true;
}

bool ServicoHistoriaDeUsuario::excluir(const Codigo &) {
    return true;
}

bool ServicoHistoriaDeUsuario::associarPessoa(const Codigo &, const Email &) {
    return true;
}

bool ServicoHistoriaDeUsuario::removerPessoa(const Codigo &, const Email &) {
    return true;
}

bool ServicoHistoriaDeUsuario::listarPorProjeto(const Codigo &) {
    return true;
}

bool ServicoHistoriaDeUsuario::listarPorPlanoDeSprint(const Codigo &) {
    return true;
}

bool ServicoHistoriaDeUsuario::listarPorPessoa(const Email &) {
    return true;
}

bool ServicoHistoriaDeUsuario::moverParaPlanoDeSprint(const Codigo &, const Codigo &, const Codigo &) {
    return true;
}

bool ServicoHistoriaDeUsuario::alterarEstado(const Codigo &, const Estado &) {
    return true;
}
