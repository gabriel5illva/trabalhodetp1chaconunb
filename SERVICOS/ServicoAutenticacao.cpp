#include "../../Headers/SERVICOS/ServicoAutenticacao.hpp"

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

    if (pessoa.getSenha().getSenha() == senha.getSenha()) {
        return true;
    }

    return false;
}
