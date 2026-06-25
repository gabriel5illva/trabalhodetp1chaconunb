#include "CntrApresentacaoPessoa.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

void CntrApresentacaoPessoa::setServicoPessoa(IServicoPessoa *servico) {
    this->servicoPessoas = servico;
}

void CntrApresentacaoPessoa::setServicoProjeto(IServicoProjeto *servico) {
    this->servicoProjeto = servico;
}

void CntrApresentacaoPessoa::cadastrar() {
    // Mantemos o método cadastrar inicial intacto para o menu deslogado
    std::string entradaEmail, entradaSenha, entradaNome, entradaPapel;
    int opcaoPapel;

    std::cout << "\n-----------------------------------------\n";
    std::cout << "            TELA DE CADASTRO             \n";
    std::cout << "-----------------------------------------\n";
    
    std::cin.ignore(10000, '\n'); 

    std::cout << "Digite seu Nome: ";
    std::getline(std::cin, entradaNome);

    std::cout << "Digite um E-mail valido: ";
    std::cin >> entradaEmail;

    std::cout << "Digite uma Senha valida: ";
    std::cin >> entradaSenha;

    while (true) {
        std::cout << "\nSelecione seu Papel:\n";
        std::cout << "1 - DESENVOLVEDOR\n";
        std::cout << "2 - MESTRE SCRUM\n";
        std::cout << "3 - PROPRIETARIO DE PRODUTO\n";
        std::cout << "Escolha uma opcao: ";
        
        if (std::cin >> opcaoPapel) {
            if (opcaoPapel == 1) { entradaPapel = "DESENVOLVEDOR"; break; }
            else if (opcaoPapel == 2) { entradaPapel = "MESTRE SCRUM"; break; }
            else if (opcaoPapel == 3) { entradaPapel = "PROPRIETARIO DE PRODUTO"; break; }
        } else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "\n[Erro] Opcao invalida. Tente novamente.\n";
    }

    try {
        Nome objNome; objNome.setNome(entradaNome);
        Email objEmail; objEmail.setEmail(entradaEmail);
        Senha objSenha; objSenha.setSenha(entradaSenha);
        Papel objPapel; objPapel.setPapel(entradaPapel);

        Pessoa novaPessoa;
        novaPessoa.setNome(objNome);
        novaPessoa.setEmail(objEmail);
        novaPessoa.setSenha(objSenha);
        novaPessoa.setPapel(objPapel);

        if (servicoPessoas->criar(novaPessoa)) {
            std::cout << "\n[Sucesso] Cadastro realizado!\n";
        } else {
            std::cout << "\n[Erro] E-mail ja cadastrado.\n";
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "\n[Erro de Formato] " << e.what() << "\n";
    }
}

// MÉTODO REFEITO: Menu adaptativo com CRUD universal por e-mail
bool CntrApresentacaoPessoa::executar(const Email &emailLogado) {
    int opcao;

    while (true) {
        // 1. Identifica os dados e o papel do usuário atualmente logado
        Pessoa dadosLogado = servicoPessoas->ler(emailLogado);
        std::string papelLogado = dadosLogado.getPapel().getPapel();

        std::cout << "\n=========================================\n";
        std::cout << "             GESTAO DE PESSOAS           \n";
        std::cout << "  Usuario: " << dadosLogado.getNome().getNome() << "\n";
        std::cout << "  Papel:   " << papelLogado << "\n";
        std::cout << "=========================================\n";
        std::cout << "1 - Criar nova Pessoa (C)\n";
        std::cout << "2 - Ler dados de uma Pessoa por E-mail (R)\n";
        std::cout << "3 - Editar dados de uma Pessoa por E-mail (U)\n";
        std::cout << "4 - Excluir uma Pessoa por E-mail (D)\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "=========================================\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "\nEntrada invalida. Digite um numero.\n";

            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida

            continue;
        }   

        if (opcao == 0) {
            return true; // Retorna mantendo a sessão ativa
        }

        // --- OPÇÃO 1: CREATE (Qualquer papel pode criar alguém) ---
        if (opcao == 1) {
            std::string nome, mail, pass, papelStr;
            int opP;
            std::cin.ignore(10000, '\n');
            std::cout << "\n--- CRIAR PESSOA ---\nDigite o Nome: ";
            std::getline(std::cin, nome);
            std::cout << "Digite o E-mail: ";
            std::cin >> mail;
            std::cout << "Digite a Senha: ";
            std::cin >> pass;
            while (true) {
                std::cout << "Selecione o Papel:\n1 - DESENVOLVEDOR\n2 - MESTRE SCRUM\n3 - PROPRIETARIO DE PRODUTO\nOpcao: ";
                std::cin >> opP;
                if (opP == 1) { papelStr = "DESENVOLVEDOR"; break; }
                if (opP == 2) { papelStr = "MESTRE SCRUM"; break; }
                if (opP == 3) { papelStr = "PROPRIETARIO DE PRODUTO"; break; }
                std::cout << "Invalido.\n";
            }
            try {
                Nome n; n.setNome(nome);
                Email e; e.setEmail(mail);
                Senha s; s.setSenha(pass);
                Papel p; p.setPapel(papelStr);
                Pessoa nova; nova.setNome(n); nova.setEmail(e); nova.setSenha(s); nova.setPapel(p);

                if (servicoPessoas->criar(nova)) std::cout << "\n[Sucesso] Pessoa criada com sucesso!\n";
                else std::cout << "\n[Erro] Esse e-mail ja existe.\n";
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 2: READ (Busca qualquer e-mail informado) ---
        else if (opcao == 2) {
            std::string emailBusca;
            std::cout << "\nDigite o E-mail da pessoa que deseja buscar: ";
            std::cin >> emailBusca;
            try {
                Email eBusca; eBusca.setEmail(emailBusca);
                Pessoa encontrada = servicoPessoas->ler(eBusca);

                if (encontrada.getEmail().getEmail() == "") {
                    std::cout << "\n[Erro] Pessoa nao encontrada no sistema.\n";
                } else {
                    std::cout << "\n--- DADOS DA PESSOA ENCONTRADA ---\n";
                    std::cout << "Nome:   " << encontrada.getNome().getNome() << "\n";
                    std::cout << "E-mail: " << encontrada.getEmail().getEmail() << "\n";
                    std::cout << "Papel:  " << encontrada.getPapel().getPapel() << "\n";
                }
                char verProjetos;
                    std::cout << "\nDeseja listar os projetos associados a esta pessoa? (S/N): ";
                    std::cin >> verProjetos;
    
                if (verProjetos == 'S' || verProjetos == 's') {
                // Chama o método que alteramos para retornar o vetor filtrado pelo e-mail consultado
                std::vector<Projeto> projetosDaPessoa = servicoProjeto->listarPorPessoa(encontrada.getEmail());
            
                if (projetosDaPessoa.empty()) {
                    std::cout << "Nenhum projeto associado a esta pessoa.\n";
                } else {
                    std::cout << "\nProjetos associados:\n";
                for (size_t i = 0; i < projetosDaPessoa.size(); ++i) {
                    std::cout << (i + 1) << "- " 
                              << projetosDaPessoa[i].getCodigo().getCodigo() << " | " 
                              << projetosDaPessoa[i].getNome().getNome() << "\n";
                }
            }
        }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 3: UPDATE (Edita qualquer e-mail informado) ---
        else if (opcao == 3) {
            std::string emailAlvo;
            std::cout << "\nDigite o E-mail da pessoa que deseja EDITAR: ";
            std::cin >> emailAlvo;
            try {
                Email eAlvo; eAlvo.setEmail(emailAlvo);
                Pessoa p = servicoPessoas->ler(eAlvo);

                if (p.getEmail().getEmail() == "") {
                    std::cout << "\n[Erro] Pessoa nao encontrada.\n";
                } else {
                    std::string novoNome, novaSenha, novoPapel;
                    int opP;
                    std::cin.ignore(10000, '\n');
                    std::cout << "\nNovo Nome (Atual: " << p.getNome().getNome() << "): ";
                    std::getline(std::cin, novoNome);
                    std::cout << "Nova Senha: ";
                    std::cin >> novaSenha;
                    while (true) {
                        std::cout << "Selecione o Novo Papel:\n1 - DESENVOLVEDOR\n2 - MESTRE SCRUM\n3 - PROPRIETARIO DE PRODUTO\nOpcao: ";
                        std::cin >> opP;
                        if (opP == 1) { novoPapel = "DESENVOLVEDOR"; break; }
                        if (opP == 2) { novoPapel = "MESTRE SCRUM"; break; }
                        if (opP == 3) { novoPapel = "PROPRIETARIO DE PRODUTO"; break; }
                    }

                    Nome n; n.setNome(novoNome);
                    Senha s; s.setSenha(novaSenha);
                    Papel pap; pap.setPapel(novoPapel);

                    p.setNome(n);
                    p.setSenha(s);
                    p.setPapel(pap);

                    if (servicoPessoas->atualizar(p)) {
                        std::cout << "\n[Sucesso] Dados atualizados com sucesso!\n";
                    } else {
                        std::cout << "\n[Erro] Falha ao salvar atualizacoes.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
        // --- OPÇÃO 4: DELETE (Exclui qualquer e-mail informado) ---
        else if (opcao == 4) {
            std::string emailDeletar;
            std::cout << "\nDigite o E-mail da pessoa que deseja EXCLUIR: ";
            std::cin >> emailDeletar;
            try {
                Email eDeletar; eDeletar.setEmail(emailDeletar);
                char confirm;
                std::cout << "Tem certeza que deseja remover permanentemente essa pessoa? (S/N): ";
                std::cin >> confirm;
                if (confirm == 'S' || confirm == 's') {
                    if (servicoPessoas->excluir(eDeletar)) {
                        std::cout << "\n[Sucesso] Pessoa excluida do sistema.\n";
                        
                        // REGRA ADICIONAL: Se o usuário logado excluiu a si próprio, força o logout imediato!
                        if (emailDeletar == emailLogado.getEmail()) {
                            std::cout << "Voce acabou de excluir sua propria conta! Efetuando logout...\n";
                            return false; 
                        }
                    } else {
                        std::cout << "\n[Erro] Pessoa nao encontrada.\n";
                    }
                }
            } catch (const std::invalid_argument &e) {
                std::cout << "\n[Erro de Formato] " << e.what() << "\n";
            }
        }
         else {
            std::cout << "\nOpcao invalida. Tente novamente.\n";
        }
    }
}