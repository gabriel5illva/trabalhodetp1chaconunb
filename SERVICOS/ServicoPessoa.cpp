#include "../SERVICOS/ServicoPessoa.hpp"

ServicoPessoa::ServicoPessoa() {
    containerPessoa = nullptr;
}

void ServicoPessoa::setContainerPessoa(ContainerPessoa *containerPessoa) {
    this->containerPessoa = containerPessoa;
}

bool ServicoPessoa::criar(const Pessoa &pessoa) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->inserir(pessoa);
}

Pessoa ServicoPessoa::ler(const Email &email) {
    Pessoa pessoa;

    if (containerPessoa == nullptr) {
        return pessoa;
    }

    containerPessoa->buscar(email, pessoa);

    return pessoa;
}

bool ServicoPessoa::atualizar(const Pessoa &pessoa) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->atualizar(pessoa);
}

bool ServicoPessoa::excluir(const Email &email) {
    if (containerPessoa == nullptr) {
        return false;
    }

    return containerPessoa->remover(email);
}
