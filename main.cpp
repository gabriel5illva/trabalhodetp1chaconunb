#include <iostream>

// Contêineres de Dados (Persistência em memória)
#include "SERVICOS/ContainerPessoa.hpp"
#include "SERVICOS/ContainerProjeto.hpp"
#include "SERVICOS/ContainerPlanoDeSprint.hpp" // INCLUÍDO

// Classes da Camada de Serviço
#include "SERVICOS/ServicoAutenticacao.hpp"
#include "SERVICOS/ServicoPessoa.hpp"
#include "SERVICOS/ServicoProjeto.hpp"
#include "SERVICOS/ServicoPlanoDeSprint.hpp" // INCLUÍDO

// Classes da Camada de Apresentação (Controladoras)
#include "INTERFACES/CntrApresentacaoControle.hpp"
#include "INTERFACES/CntrApresentacaoAutenticacao.hpp"
#include "INTERFACES/CntrApresentacaoPessoa.hpp"
#include "INTERFACES/CntrApresentacaoProjeto.hpp"
#include "INTERFACES/CntrApresentacaoPlanoDeSprint.hpp" // INCLUÍDO

int main() {
    // -----------------------------------------------------------------
    // 1. INSTANCIAÇÃO DOS CONTÊINERES DE DADOS
    // -----------------------------------------------------------------
    ContainerPessoa containerPessoa;
    ContainerProjeto containerProjeto;
    ContainerPlanoDeSprint containerPlanoDeSprint;

    // -----------------------------------------------------------------
    // 2. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE SERVIÇO
    // -----------------------------------------------------------------
    ServicoAutenticacao servicoAutenticacao;
    servicoAutenticacao.setContainerPessoa(&containerPessoa);

    ServicoPessoa servicoPessoa;
    servicoPessoa.setContainerPessoa(&containerPessoa);

    ServicoProjeto servicoProjeto;
    servicoProjeto.setContainerProjeto(&containerProjeto);

    ServicoPlanoDeSprint servicoPlanoDeSprint;
    servicoPlanoDeSprint.setContainerPlanoDeSprint(&containerPlanoDeSprint);

    // -----------------------------------------------------------------
    // 3. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE APRESENTAÇÃO
    // -----------------------------------------------------------------
    CntrApresentacaoAutenticacao aprAutenticacao;
    aprAutenticacao.setServicoAutenticacao(&servicoAutenticacao);

    CntrApresentacaoPessoa aprPessoa;
    aprPessoa.setServicoPessoa(&servicoPessoa);

    CntrApresentacaoProjeto aprProjeto;
    aprProjeto.setServicoProjeto(&servicoProjeto);
    aprProjeto.setServicoPessoa(&servicoPessoa); // Para checar Permissões (Proprietário de Produto)

    CntrApresentacaoPlanoDeSprint aprSprint;
    aprSprint.setServicoPlanoDeSprint(&servicoPlanoDeSprint);
    aprSprint.setServicoPessoa(&servicoPessoa); // Para checar Permissões (Mestre Scrum)

    // -----------------------------------------------------------------
    // 4. INSTANCIAÇÃO E CONFIGURAÇÃO DA CONTROLADORA PRINCIPAL (MAESTRO)
    // -----------------------------------------------------------------
    CntrApresentacaoControle aprControle;
    aprControle.setApresentacaoAutenticacao(&aprAutenticacao);
    aprControle.setApresentacaoPessoa(&aprPessoa);
    aprControle.setApresentacaoProjeto(&aprProjeto);
    
    // AQUI ESTÁ A LINHA QUE FALTAVA PARA O ERRO SUMIR:
    aprControle.setApresentacaoPlanoDeSprint(&aprSprint); 

    // -----------------------------------------------------------------
    // 5. EXECUÇÃO DO SISTEMA
    // -----------------------------------------------------------------
    std::cout << "Inicializando o sistema de gestao Kanban...\n";
    aprControle.executar();

    return 0;
}