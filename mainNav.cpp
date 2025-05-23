#include <iostream>
#include <string>
using namespace std;

// Nó da Lista Encadeada (Histórico)
struct Pagina {
    string url;
    Pagina* proxima;
};

// Nó da Pilha
struct NoPilha {
    string url;
    NoPilha* proximo;
};

// Funções auxiliares para lista (histórico)
void adicionarHistorico(Pagina*& historico, string url) {
     Pagina* nova = new Pagina;
     nova->url = url;
     nova->proxima = NULL;
    if (!historico) {
        historico = nova;
    } else {
        Pagina* temp = historico;
        while (temp->proxima)
            temp = temp->proxima;
        temp->proxima = nova;
    }
}

void exibirHistorico(Pagina* historico) {
    cout << "\n Historico de navegacao:\n";
    while (historico) {
        cout << "- " << historico->url << endl;
        historico = historico->proxima;
    }
}

// Funções auxiliares para pilha
void empilhar(NoPilha*& topo, string url) {
     NoPilha* novo = new NoPilha;
     novo->url = url;
     novo->proximo = topo;  
    topo = novo;
}

string desempilhar(NoPilha*& topo) {
    if (!topo) return "";
    string url = topo->url;
    NoPilha* temp = topo;
    topo = topo->proximo;
    delete temp;
    return url;
}

void limparPilha(NoPilha*& topo) {
    while (topo) {
        NoPilha* temp = topo;
        topo = topo->proximo;
        delete temp;
    }
}

void limparHistorico(Pagina*& historico) {
    while (historico) {
        Pagina* temp = historico;
        historico = historico->proxima;
        delete temp;
    }
}

// Função principal
int main() {
    NoPilha* pilhaVoltar = NULL;
    NoPilha* pilhaAvancar = NULL;
    Pagina* historico = NULL;

    string paginaAtual = "pagina_inicial.com";
    adicionarHistorico(historico, paginaAtual);

    int opcao;
    string novaPagina;

    do {
        cout << "\n Pagina atual: " << paginaAtual << "\n";
        cout << "\n1. Acessar nova pagina\n2. Voltar\n3. Avancar\n4. Exibir historico\n5. Sair\n\nEscolha: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Digite a URL da nova pagina: ";
                getline(cin, novaPagina);
                empilhar(pilhaVoltar, paginaAtual);
                limparPilha(pilhaAvancar);
                paginaAtual = novaPagina;
                adicionarHistorico(historico, paginaAtual);
                break;
            case 2:
                if (pilhaVoltar) {
                    empilhar(pilhaAvancar, paginaAtual);
                    paginaAtual = desempilhar(pilhaVoltar);
                } else {
                    cout << " Nenhuma pagina para voltar.\n";
                }
                break;
            case 3:
                if (pilhaAvancar) {
                    empilhar(pilhaVoltar, paginaAtual);
                    paginaAtual = desempilhar(pilhaAvancar);
                } else {
                    cout << " Nenhuma pagina para avancar.\n";
                }
                break;
            case 4:
                exibirHistorico(historico);
                break;
            case 5:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 5);

    limparPilha(pilhaVoltar);
    limparPilha(pilhaAvancar);
    limparHistorico(historico);

    return 0;
}

