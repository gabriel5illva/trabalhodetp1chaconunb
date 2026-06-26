#ifndef CNTRAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED
#define CNTRAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED

#include "../INTERFACES/IApresentacaoHistoriaDeUsuario.hpp"
#include "../INTERFACES/IServicoHistoriaDeUsuario.hpp"
#include "../INTERFACES/IServicoPessoa.hpp" 
#include "../INTERFACES/IServicoProjeto.hpp"
#include "../INTERFACES/IServicoPlanoDeSprint.hpp"

#include "../DOMINIOS/Email.hpp"
#include "../DOMINIOS/Codigo.hpp"
#include "../DOMINIOS/texto.hpp"
#include "../DOMINIOS/tempo.hpp"
#include "../DOMINIOS/prioridade.hpp"
#include "../DOMINIOS/estado.hpp"
#include "../ENTIDADES/HistoriaDeUsuario.hpp"
#include "../ENTIDADES/Pessoa.hpp"

/**
 * @class CntrApresentacaoHistoriaDeUsuario
 * @brief Controladora de apresentação responsável pelas telas de Histórias de Usuário.
 */
class CntrApresentacaoHistoriaDeUsuario : public IApresentacaoHistoriaDeUsuario {
private:
    IServicoHistoriaDeUsuario *servicoHistoriaDeUsuario;
    IServicoPessoa *servicoPessoa;
    IServicoProjeto *servicoProjeto;
    IServicoPlanoDeSprint *servicoPlanoDeSprint;

public:
    void executar(const Email &email) override;
    
    void setServicoHistoriaDeUsuario(IServicoHistoriaDeUsuario *servico) override;
    void setServicoPessoa(IServicoPessoa *servico);
    void setServicoProjeto(IServicoProjeto *servico);
    void setServicoPlanoDeSprint(IServicoPlanoDeSprint *servico);
};

#endif // CNTRAPRESENTACAOHISTORIADEUSUARIO_HPP_INCLUDED