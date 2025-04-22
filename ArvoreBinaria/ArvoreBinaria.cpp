#include <iostream>
#include <cstdlib>    // para malloc, system
using namespace std;

struct NO {
    int valor;
    NO* esq;
    NO* dir;
};

NO* raiz = NULL;

// protótipos de função
void menu();
void inicializar();
void inserir();
void exibirQuantidade();
void exibir();
NO* criaNO(int valor);
NO* insereArvore(NO* no, int valor);
int elementosArvore(NO* no);
void exibirElementosArvore(NO* no);
int fat(int n);

int main() {
    menu();
    return 0;
}

void menu() {
    int op = 0;
    while (op != 5) {
        system("cls");  // somente no Windows
        cout << "===== Menu Arvore =====\n\n";
        cout << "1 - Inicializar Arvore\n";
        cout << "2 - Exibir quantidade de elementos\n";
        cout << "3 - Inserir elemento\n";
        cout << "4 - Exibir elementos (com fatorial)\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> op;
        switch (op) {
        case 1:
            inicializar();
            break;
        case 2:
            exibirQuantidade();
            break;
        case 3:
            inserir();
            break;
        case 4:
            exibir();
            break;
        case 5:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
        }
        system("pause");  // somente no Windows
    }
}

void inicializar() {
    // reinicia a árvore (não faz liberações de memória)
    raiz = NULL;
    cout << "Arvore inicializada!\n";
}

void inserir() {
    int valor;
    cout << "Digite o elemento: ";
    cin >> valor;
    if (raiz == NULL) {
        raiz = criaNO(valor);
    }
    else {
        insereArvore(raiz, valor);
    }
}

void exibirQuantidade() {
    cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;
}

void exibir() {
    if (raiz == NULL) {
        cout << "Arvore vazia!\n";
    }
    else {
        cout << "Elementos da arvore em ordem (in-order):\n";
        exibirElementosArvore(raiz);
        cout << endl;
    }
}

NO* criaNO(int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        cerr << "Erro de alocacao!\n";
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

NO* insereArvore(NO* no, int valor) {
    if (no == NULL) {
        return criaNO(valor);
    }
    if (valor < no->valor) {
        no->esq = insereArvore(no->esq, valor);
    }
    else if (valor > no->valor) {
        no->dir = insereArvore(no->dir, valor);
    }
    // se valor == no->valor, não insere duplicatas
    return no;
}

int elementosArvore(NO* no) {
    if (no == NULL)
        return 0;
    return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO* no) {
    if (no == NULL) {
        return;

    }
    else {
        exibirElementosArvore(no->esq);
        cout << no->valor << " ";
        exibirElementosArvore(no->dir);
    }
        
  
}