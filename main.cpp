#include <iostream>

#include "SERVICOS/ContainerPessoa.hpp"
#include "SERVICOS/ServicoAutenticacao.hpp"
#include "SERVICOS/ServicoPessoa.hpp"

#include "INTERFACES/CntrApresentacaoControle.hpp"
#include "INTERFACES/CntrApresentacaoAutenticacao.hpp"
#include "INTERFACES/CntrApresentacaoPessoa.hpp"

int main() {
    // 1. Dados em Memória
    ContainerPessoa containerPessoa;

    // 2. Camada de Serviço
    ServicoAutenticacao servicoAutenticacao;
    servicoAutenticacao.setContainerPessoa(&containerPessoa);

    ServicoPessoa servicoPessoas;
    servicoPessoas.setContainerPessoa(&containerPessoa);

    // 3. Camada de Apresentação
    CntrApresentacaoAutenticacao aprAutenticacao;
    aprAutenticacao.setServicoAutenticacao(&servicoAutenticacao);

    CntrApresentacaoPessoa aprPessoa;
    aprPessoa.setServicoPessoa(&servicoPessoas);

    // 4. Inicialização do Controle Principal
    CntrApresentacaoControle aprControle;
    aprControle.setApresentacaoAutenticacao(&aprAutenticacao);
    aprControle.setApresentacaoPessoa(&aprPessoa);

    // Executa o sistema
    aprControle.executar();

    return 0;
}