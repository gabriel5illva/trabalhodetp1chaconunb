#include "ServicoAutenticacao.hpp"

ServicoAutenticacao::ServicoAutenticacao() {
    containerPessoa = nullptr;
}

void ServicoAutenticacao::setContainerPessoa(ContainerPessoa *containerPessoa) {
    this->containerPessoa = containerPessoa;
}

bool ServicoAutenticacao::autenticar(const Email &email, const Senha &senha) {
    if (containerPessoa == nullptr) {
        return false;
    }

    Pessoa pessoa;

    if (!containerPessoa->buscar(email, pessoa)) {
        return false;
    }

    return pessoa.getSenha().getSenha() == senha.getSenha();
}