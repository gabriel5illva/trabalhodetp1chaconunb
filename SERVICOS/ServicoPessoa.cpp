#include "../../Headers/servicos/ServicoPessoa.hpp"

bool ServicoPessoa::criar(const Pessoa &) {
    return true;
}

Pessoa ServicoPessoa::ler(const Email &) {
    Pessoa pessoa;
    return pessoa;
}

bool ServicoPessoa::atualizar(const Pessoa &) {
    return true;
}

bool ServicoPessoa::excluir(const Email &) {
    return true;
}
