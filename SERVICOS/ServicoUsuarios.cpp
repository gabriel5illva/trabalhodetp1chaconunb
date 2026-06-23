#include "../../Headers/SERVICOS/ServicoUsuarios.hpp"

ServicoUsuarios::ServicoUsuarios() {
    containerPessoa = nullptr;
}

void ServicoUsuarios::setContainerPessoa(ContainerPessoa *containerPessoa) {
    this->containerPessoa = containerPessoa;
}

bool ServicoUsuarios::criar(const Pessoa &pessoa) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->inserir(pessoa);
}

Pessoa ServicoUsuarios::ler(const Email &email) {
    Pessoa pessoa;

    if (containerPessoa == nullptr) {
        return pessoa;
    }

    containerPessoa->buscar(email, pessoa);
    return pessoa;
}

bool ServicoUsuarios::atualizar(const Pessoa &pessoa) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->atualizar(pessoa);
}

bool ServicoUsuarios::excluir(const Email &email) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->remover(email);
}
