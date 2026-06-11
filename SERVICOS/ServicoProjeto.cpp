#include "../../Headers/servicos/ServicoProjeto.hpp"

bool ServicoProjeto::criar(const Projeto &) {
    return true;
}

Projeto ServicoProjeto::ler(const Codigo &) {
    Projeto projeto;
    return projeto;
}

bool ServicoProjeto::atualizar(const Projeto &) {
    return true;
}

bool ServicoProjeto::excluir(const Codigo &) {
    return true;
}

bool ServicoProjeto::listarPorPessoa(const Email &) {
    return true;
}
