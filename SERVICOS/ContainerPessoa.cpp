#include "ContainerPessoa.hpp"

bool ContainerPessoa::inserir(const Pessoa &pessoa) {
    Pessoa pessoaEncontrada;

    if (buscar(pessoa.getEmail(), pessoaEncontrada)) {
        return false;
    }

    pessoas.push_back(pessoa);
    return true;
}

bool ContainerPessoa::buscar(const Email &email, Pessoa &pessoa) {
    for (Pessoa p : pessoas) {
        if (p.getEmail().getEmail() == email.getEmail()) {
            pessoa = p;
            return true;
        }
    }

    return false;
}

bool ContainerPessoa::atualizar(const Pessoa &pessoa) {
    for (int i = 0; i < pessoas.size(); i++) {
        if (pessoas[i].getEmail().getEmail() == pessoa.getEmail().getEmail()) {
            pessoas[i] = pessoa;
            return true;
        }
    }

    return false;
}

bool ContainerPessoa::remover(const Email &email) {
    for (int i = 0; i < pessoas.size(); i++) {
        if (pessoas[i].getEmail().getEmail() == email.getEmail()) {
            pessoas.erase(pessoas.begin() + i);
            return true;
        }
    }

    return false;
}
