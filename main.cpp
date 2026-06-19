#include <iostream>
#include "INTERFACES/IApresentacaoAutenticacao.hpp"
#include "INTERFACES/CntrApresentacaoAutenticacao.hpp"
#include "SERVICOS/ServicoPessoa.hpp"

int main() {
    // 1. Inicializa o serviço de negócio/persistência (Herda de IServicoAutenticacao)
    // O construtor do ServicoPessoa chamará automaticamente o inicializarBanco()
    std::cout << "[MAIN] Inicializando ServicoPessoa (Banco de Dados)..." << std::endl;
    ServicoPessoa* servicoAutenticacao = new ServicoPessoa();

    // 2. Inicializa a controladora da Camada de Apresentação
    std::cout << "[MAIN] Inicializando Camada de Apresentacao..." << std::endl;
    IApresentacaoAutenticacao* apresentacao = new CntrApresentacaoAutenticacao();

    // 3. Executa o fluxo passando o serviço via Injeção de Dependência
    std::cout << "[MAIN] Iniciando o loop de execucao do sistema...\n" << std::endl;
    apresentacao->executar(servicoAutenticacao);

    // 4. Limpeza de memória ao sair do loop (quando a opção 0 for digitada)
    delete apresentacao;
    delete servicoAutenticacao;

    std::cout << "\n[MAIN] Recursos liberados. Execucao encerrada com sucesso." << std::endl;
    return 0;
}
