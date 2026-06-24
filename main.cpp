#include <iostream>

// Incluindo o contêiner de dados (banco em memória)
#include "SERVICOS/ContainerPessoa.hpp"

// Incluindo as implementações da camada de Serviço
#include "SERVICOS/ServicoAutenticacao.hpp"
#include "SERVICOS/ServicoUsuarios.hpp"

// Incluindo as implementações da camada de Apresentação
#include "INTERFACES/CntrApresentacaoControle.hpp"
#include "INTERFACES/CntrApresentacaoAutenticacao.hpp"
#include "INTERFACES/CntrApresentacaoUsuario.hpp"

int main() {
    // -------------------------------------------------------------
    // 1. INSTANCIANDO DADOS (Simulação de Banco de Dados)
    // -------------------------------------------------------------
    ContainerPessoa containerPessoa;

    // -------------------------------------------------------------
    // 2. INSTANCIANDO E CONFIGURANDO A CAMADA DE SERVIÇO
    // -------------------------------------------------------------
    ServicoAutenticacao servicoAutenticacao;
    servicoAutenticacao.setContainerPessoa(&containerPessoa);

    ServicoUsuarios servicoUsuarios;
    servicoUsuarios.setContainerPessoa(&containerPessoa);

    // -------------------------------------------------------------
    // 3. INSTANCIANDO E CONFIGURANDO A CAMADA DE APRESENTAÇÃO
    // -------------------------------------------------------------
    CntrApresentacaoAutenticacao aprAutenticacao;
    aprAutenticacao.setServicoAutenticacao(&servicoAutenticacao);

    CntrApresentacaoUsuario aprUsuario;
    aprUsuario.setServicoUsuarios(&servicoUsuarios);

    // -------------------------------------------------------------
    // 4. INSTANCIANDO E INICIANDO A CONTROLADORA PRINCIPAL (MAESTRO)
    // -------------------------------------------------------------
    CntrApresentacaoControle aprControle;
    aprControle.setApresentacaoAutenticacao(&aprAutenticacao);
    aprControle.setApresentacaoUsuario(&aprUsuario);

    // Inicia o fluxo geral do sistema
    aprControle.executar();

    return 0;
}
