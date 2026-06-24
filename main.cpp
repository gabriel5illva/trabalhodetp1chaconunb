#include <iostream>

// Contêineres de Dados (Persistência em memória)
#include "SERVICOS/ContainerPessoa.hpp"
#include "SERVICOS/ContainerProjeto.hpp"

// Classes da Camada de Serviço
#include "SERVICOS/ServicoAutenticacao.hpp"
#include "SERVICOS/ServicoPessoa.hpp"
#include "SERVICOS/ServicoProjeto.hpp"

// Classes da Camada de Apresentação (Controladoras)
#include "INTERFACES/CntrApresentacaoControle.hpp"
#include "INTERFACES/CntrApresentacaoAutenticacao.hpp"
#include "INTERFACES/CntrApresentacaoPessoa.hpp"
#include "INTERFACES/CntrApresentacaoProjeto.hpp"

int main() {
    // -----------------------------------------------------------------
    // 1. INSTANCIAÇÃO DOS CONTÊINERES DE DADOS
    // -----------------------------------------------------------------
    ContainerPessoa containerPessoa;
    ContainerProjeto containerProjeto;

    // -----------------------------------------------------------------
    // 2. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE SERVIÇO
    // -----------------------------------------------------------------
    ServicoAutenticacao servicoAutenticacao;
    servicoAutenticacao.setContainerPessoa(&containerPessoa);

    ServicoPessoa servicoPessoa;
    servicoPessoa.setContainerPessoa(&containerPessoa);

    ServicoProjeto servicoProjeto;
    servicoProjeto.setContainerProjeto(&containerProjeto);

    // -----------------------------------------------------------------
    // 3. INSTANCIAÇÃO E CONFIGURAÇÃO DA CAMADA DE APRESENTAÇÃO
    // -----------------------------------------------------------------
    CntrApresentacaoAutenticacao aprAutenticacao;
    aprAutenticacao.setServicoAutenticacao(&servicoAutenticacao);

    CntrApresentacaoPessoa aprPessoa;
    aprPessoa.setServicoPessoa(&servicoPessoa);

    CntrApresentacaoProjeto aprProjeto;
    aprProjeto.setServicoProjeto(&servicoProjeto);
    aprProjeto.setServicoPessoa(&servicoPessoa); // Injeção necessária para verificar o Papel do usuário logado

    // -----------------------------------------------------------------
    // 4. INSTANCIAÇÃO E CONFIGURAÇÃO DA CONTROLADORA PRINCIPAL (MAESTRO)
    // -----------------------------------------------------------------
    CntrApresentacaoControle aprControle;
    aprControle.setApresentacaoAutenticacao(&aprAutenticacao);
    aprControle.setApresentacaoPessoa(&aprPessoa);
    aprControle.setApresentacaoProjeto(&aprProjeto); // Liga definitivamente o módulo de projetos ao fluxo

    // -----------------------------------------------------------------
    // 5. EXECUÇÃO DO SISTEMA
    // -----------------------------------------------------------------
    std::cout << "Inicializando o sistema de gestao Kanban...\n";
    aprControle.executar();

    return 0;
}