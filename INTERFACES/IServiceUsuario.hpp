#ifndef ISERVICO_USUARIOS_HPP_INCLUDED
#define ISERVICO_USUARIOS_HPP_INCLUDED

#include "../ENTIDADES/Pessoa.hpp"
#include "../DOMINIOS/Email.hpp"

/**
 * @class IServicoUsuarios
 * @brief Interface de servico para as operacoes relacionadas a usuarios.
 *
 * Esta interface define o contrato que deve ser provido pelo modulo de
 * servico de usuarios. As classes da camada de apresentacao utilizam
 * esta interface para solicitar operacoes sem depender diretamente da
 * implementacao concreta do servico.
 */
class IServicoUsuarios {
public:
    /**
     * @brief Cria um usuario.
     *
     * @param pessoa Entidade Pessoa a ser cadastrada.
     * @return true se a operacao for realizada com sucesso.
     */
    virtual bool criar(const Pessoa &pessoa) = 0;

    /**
     * @brief Le um usuario a partir do email.
     *
     * @param email Email que identifica o usuario.
     * @return Entidade Pessoa encontrada.
     */
    virtual Pessoa ler(const Email &email) = 0;

    /**
     * @brief Atualiza os dados de um usuario.
     *
     * @param pessoa Entidade Pessoa com os dados atualizados.
     * @return true se a operacao for realizada com sucesso.
     */
    virtual bool atualizar(const Pessoa &pessoa) = 0;

    /**
     * @brief Exclui um usuario.
     *
     * @param email Email que identifica o usuario.
     * @return true se a operacao for realizada com sucesso.
     */
    virtual bool excluir(const Email &email) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IServicoUsuarios() {}
};

#endif
