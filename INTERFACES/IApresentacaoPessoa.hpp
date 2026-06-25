#ifndef IAPRESENTACAOPESSOA_HPP_INCLUDED
#define IAPRESENTACAOPESSOA_HPP_INCLUDED

#include "../DOMINIOS/email.hpp"
#include "IServicoPessoa.hpp"

/**
 * @class IApresentacaoPessoa
 * @brief Interface para a apresentação das telas de gestão do perfil e cadastro de pessoas.
 */
class IApresentacaoPessoa {
public:
    virtual void cadastrar() = 0;
    
    /**
     * @brief Executa o menu de gestão de perfil (Visualizar, Editar, Excluir).
     * @return true se a conta continuar ativa, false se a conta tiver sido excluída.
     */
    virtual bool executar(const Email &email) = 0;

    virtual void setServicoPessoa(IServicoPessoa *servico) = 0; 
    
    virtual ~IApresentacaoPessoa() = default;
};

#endif // IAPRESENTACAOPESSOA_HPP_INCLUDED