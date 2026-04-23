#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include "../dominios/Email.hpp"
#include "../dominios/Nome.hpp"
#include "../dominios/Senha.hpp"
#include "../dominios/Papel.hpp"

class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:
    void setEmail(const Email &);
    Email getEmail() const;

    void setNome(const Nome &);
    Nome getNome() const;

    void setSenha(const Senha &);
    Senha getSenha() const;

    void setPapel(const Papel &);
    Papel getPapel() const;
};

#endif
