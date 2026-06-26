#include <iostream>

// 1. Contêineres de Dados (Persistência em memória)
#include "SERVICOS/ContainerPessoa.hpp"
#include "SERVICOS/ContainerProjeto.hpp"
#include "SERVICOS/ContainerPlanoDeSprint.hpp"
#include "SERVICOS/ContainerHistoriaDeUsuario.hpp" // INCLUÍDO

// 2. Classes da Camada de Serviço (Regras de Negócio)
#include "SERVICOS/ServicoAutenticacao.hpp"
#include "SERVICOS/ServicoPessoa.hpp"
#include "SERVICOS/ServicoProjeto.hpp"
#include "SERVICOS/ServicoPlanoDeSprint.hpp"
#include "SERVICOS/ServicoHistoriaDeUsuario.hpp" // INCLUÍDO

// 3. Classes da Camada de Apresentação (Controladoras/Menus)
#include "APRESENTACAO/CntrApresentacaoControle.hpp"
#include "APRESENTACAO/CntrApresentacaoAutenticacao.hpp"
#include "APRESENTACAO/CntrApresentacaoPessoa.hpp"
#include "APRESENTACAO/CntrApresentacaoProjeto.hpp"
#include "APRESENTACAO/CntrApresentacaoPlanoDeSprint.hpp"
#include "APRESENTACAO/CntrApresentacaoHistoriaDeUsuario.hpp"

int main() {
    // -----------------------------------------------------------------
    // A. INSTANCIAÇÃO DOS CONTÊINERES DE DADOS
    // -----------------------------------------------------------------
    ContainerPessoa containerPessoa;
    ContainerProjeto containerProjeto;
    ContainerPlanoDeSprint containerPlanoDeSprint;
    ContainerHistoriaDeUsuario containerHistoria; // Instanciado

    // -----------------------------------------------------------------
    // B. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE SERVIÇO
    // -----------------------------------------------------------------
    ServicoAutenticacao servicoAutenticacao;
    servicoAutenticacao.setContainerPessoa(&containerPessoa);

    ServicoPessoa servicoPessoa;
    servicoPessoa.setContainerPessoa(&containerPessoa);

    ServicoProjeto servicoProjeto;
    servicoProjeto.setContainerProjeto(&containerProjeto);

    ServicoPlanoDeSprint servicoPlanoDeSprint;
    servicoPlanoDeSprint.setContainerPlanoDeSprint(&containerPlanoDeSprint);

    // Configuração do serviço de Histórias de Usuário
    ServicoHistoriaDeUsuario servicoHistoria;
    servicoHistoria.setContainerHistoriaDeUsuario(&containerHistoria); // Conectado

    // -----------------------------------------------------------------
    // C. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE APRESENTAÇÃO
    // -----------------------------------------------------------------
    CntrApresentacaoAutenticacao aprAutenticacao;
    aprAutenticacao.setServicoAutenticacao(&servicoAutenticacao);

    CntrApresentacaoPessoa aprPessoa;
    aprPessoa.setServicoPessoa(&servicoPessoa);
    aprPessoa.setServicoProjeto(&servicoProjeto);

    // Módulo de Projetos (Injeta serviço de pessoas para validar Proprietário de Produto)
    CntrApresentacaoProjeto aprProjeto;
    aprProjeto.setServicoProjeto(&servicoProjeto);
    aprProjeto.setServicoPessoa(&servicoPessoa); 
    aprProjeto.setServicoHistoriaDeUsuario(&servicoHistoria);
    aprProjeto.setServicoPlanoDeSprint(&servicoPlanoDeSprint);

    // Módulo de Sprints (Injeta serviço de pessoas para validar Mestre Scrum)
    CntrApresentacaoPlanoDeSprint aprSprint;
    aprSprint.setServicoPlanoDeSprint(&servicoPlanoDeSprint);
    aprSprint.setServicoPessoa(&servicoPessoa); 
    aprSprint.setServicoHistoriaDeUsuario(&servicoHistoria);
    aprSprint.setServicoProjeto(&servicoProjeto);

    // Módulo de Histórias de Usuário (Injeta serviço de pessoas para validar PO na criação/exclusão)
    CntrApresentacaoHistoriaDeUsuario aprHistoria;
    aprHistoria.setServicoHistoriaDeUsuario(&servicoHistoria);
    aprHistoria.setServicoPessoa(&servicoPessoa);
    aprHistoria.setServicoProjeto(&servicoProjeto);
    aprHistoria.setServicoPlanoDeSprint(&servicoPlanoDeSprint);

    // -----------------------------------------------------------------
    // D. CONFIGURAÇÃO DA CONTROLADORA PRINCIPAL (MAESTRO DO SISTEMA)
    // -----------------------------------------------------------------
    CntrApresentacaoControle aprControle;
    aprControle.setApresentacaoAutenticacao(&aprAutenticacao);
    aprControle.setApresentacaoPessoa(&aprPessoa);
    aprControle.setApresentacaoProjeto(&aprProjeto);
    aprControle.setApresentacaoPlanoDeSprint(&aprSprint);
    aprControle.setApresentacaoHistoriaDeUsuario(&aprHistoria); // Conectado definitivamente

    // -----------------------------------------------------------------
    // E. EXECUÇÃO DO SISTEMA
    // -----------------------------------------------------------------
    std::cout << "Inicializando o sistema de gestao Kanban...\n";
    aprControle.executar();

    return 0;
}