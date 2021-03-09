#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

struct No{
    int chave;
    int nodes; // Número de nós da subárvore que tem o nó atual como raiz.
    int altura; // Altura da subárvore que tem o nó atual como raiz.
    struct No *pai; // Pai do nó
    struct No *esq; // Filho esquerdo
    struct No *dir; // Filho direito
};

typedef struct No Node;

struct Arvore{
    Node *raiz;
};

typedef struct Arvore Tree;

/* Constrói e aloca a árvore binária de busca. */
void* constructBST(){
    Tree *T = (Tree*)malloc(sizeof(Tree));

    return (void*)T;
}

/* Inclui os nós na árvore. */
void incluirBST(void* arvore, int k){
    Tree *T = (Tree*)arvore;

    Node *no = (Node*)malloc(sizeof(Node));
    no->chave = k;
    no->esq = no->dir = NULL;

    Node *y = NULL;
    Node *x = T->raiz;
    
    bool left, right; // Booleanos que armazenarão o último "movimento" do while
    left = right = false;
    while(x != NULL){
        y = x;

        if(no->chave < x->chave){
            x = x->esq;
            left = true;
            right = false;
        }
        else{
            x = x->dir;
            left = false;
            right = true;
        }
    }

    no->pai = y;

    if(y == NULL){
        T->raiz = no;
    }

    else if(left){
        y->esq = no;
    }
    else{
        y->dir = no;
    }
}

/* Retorna um ponteiro para a raiz da árvore. */
void* raizBST(void* arvore){
    Tree *T = (Tree*)arvore;

    return (void*)T->raiz;
}

/* Percurso em Em-Ordem. */
static void emOrdem(void *no){ 
    // Parâmetro no: raiz de uma subárvore.
    Node *x = (Node*)no;
    if(no != NULL){
        emOrdem(x->esq);
        printf("%d ", x->chave); //Visitar nesse caso é imprimir a chave.
        emOrdem(x->dir);
    }
}

/* Imprimir os nós da árvore em um percurso em Em-Ordem. */
void imprimirBST(void* T){
    emOrdem(raizBST(T));
    printf("\n");
}

/* Buscar numa árvore binária de busca. */
void* buscaBST(void* root, int k){
    Node *x = (Node*)root;

    while(x != NULL && x->chave != k){
        if(x->chave > k){
            x = x->esq;
        }
        else{
            x = x->dir;
        }

    }

    if(x == NULL){
        printf("No com chave %d nao encontrado na árvore.\n", k);
    }
    else{
        printf("No com chave %d encontrado!\n", k);
    }
    return (void*)x;
}

/* Algoritmo de busca recursiva */
void* buscaRecursivaBST(void* root, int k){
    Node *x = (Node*)root;
    if(x == NULL || x->chave == k) return x;

    if(k < x->chave) return buscaRecursivaBST((void*)x->esq, k);

    return buscaRecursivaBST((void*)x->dir, k);
}

/* Encontrar valor mínimo. */
void* minimoBST(void* root){
    Node *x = (Node*)root;

    while(x->esq != NULL){
        x = x->esq;
    }

    printf("Valor minimo da arvore: %d\n", x->chave);
    return (void*)x;
}

/* Encontrar valor máximo. */
void* maximoBST(void* root){
    Node *x = (Node*)root;

    while(x->dir != NULL){
        x = x->dir;
    }

    printf("Valor maximo da arvore: %d\n", x->chave);
    return (void*)x;
}

/* Sucessor, no percurso em Em-Ordem de um nó X.*/
void* sucessorBST(void* no){
    Node *x = (Node*)no;
    int y = x->chave;

    if(x->dir != NULL){
        x = (Node*)minimoBST((void*)x->dir);
        //Imprimindo as chaves do atual e do nó sucessor.
        printf("Sucessor de %d no percurso em Em-Ordem: %d\n", y, x->chave);
        return (void*)x;
    }

    Node *z = x->pai;

    while(z != NULL && x == z->dir){
        x = z;
        z = x->pai;
    }

    if(z != NULL){
        printf("Sucessor de %d no percurso em Em-Ordem: %d\n", y, z->chave);
    }
    else{
        printf("O no atual não tem sucessor pois eh o valor maximo.\n");
    }
    return (void*)z;
}


/* Predecessor, no percurso em Em-Ordem de um nó. */
void* predecessorBST(void* no){
    Node *x = (Node*)no;
    int y = x->chave;

    if(x->esq != NULL){
        x = (Node*)maximoBST((void*)x->esq);

        printf("Predecessor de %d no percurso em Em-Ordem: %d\n", y, x->chave);

        return (void*)x;
    }

    Node *z = x->pai;
    while(z != NULL && x == z->esq){
        x = z;
        z = x->pai;
    }

    if(z != NULL){
        printf("Predecessor de %d no percurso em Em-Ordem: %d\n", y, z->chave);
    }
    else{
        printf("O no atual não tem predecessor pois eh o valor minimo.\n");
    }
    return (void*)z;
}

/*  Função para transmutar árvores enraizadas em nós distintos. (um pode ser NULL)
    Auxiliará na hora de remover nós.*/
static void transplant(void* arvore, void* n1, void* n2){
    Tree *T = (Tree*)arvore;
    Node *u = (Node*)n1;
    Node *v = (Node*)n2; //Pode ser nulo.

    if(u->pai == NULL){
        T->raiz = v;
    }
    else if(u == u->pai->esq){
        u->pai->esq = v;
    }
    else{
        u->pai->dir = v;
    }

    if(v != NULL){
        v->pai = u->pai;
    }
}

/* Remove um nó da árvore. */
void removerBST(void* arvore, void* no){
    Tree *T = (Tree*)arvore;
    Node *x = (Node*)no;

    if(x->esq == NULL){
        transplant(arvore, no, (void*)x->dir);
    }
    else if(x->dir == NULL){
        transplant(arvore, no, (void*)x->esq);
    }
    else{
        Node* y = (Node*)sucessorBST(no);
        transplant(arvore, (void*)y, (void*)y->dir);

        y->esq = x->esq;
        y->esq->pai = y;
        
        y->dir = x->dir;
        if(y->dir != NULL){
            y->dir->pai = y;
        }

        transplant(arvore, no, (void*)y);

        free(no);
    }
}


static void visitarContarNos(void* no){
    Node* x = (Node*)no;

    x->nodes = 1;
    if(x->dir != NULL){
        x->nodes = x->nodes + x->dir->nodes;
    }
    if(x->esq != NULL){
        x->nodes = x->nodes + x->esq->nodes;
    }
}

/* Contar os nós em uma subárvore. */
static void contarNos(void* no){
    if(no != NULL){
        Node *x = (Node*)no;

        contarNos((void*)x->esq);
        contarNos((void*)x->dir);
        visitarContarNos(no);
    }
}

/* Retorna os nós da subárvore enraizada em "no"*/
int quantidadeNos(void *no){
    if(no != NULL){
        contarNos(no);
        Node *x = (Node*)no;
        return x->nodes;
    }

    printf("Argumento NULL!!!\n");
    return (-1);
}

static void visitarAltura(void* no){
    Node *x = (Node*)no;
    
    x->altura = 0;
    if(x->esq != NULL){
        x->altura = 1 + x->esq->altura;
    }
    if(x->dir != NULL){
        x->altura = max(x->altura, (1 + x->dir->altura));
    }
}

/* Calcula a altura de todos os nós da subárvore enraizada em "no".*/
static void setAltura(void* no){
    if(no != NULL){
        Node *x = (Node*)no;

        setAltura((void*)x->esq);
        setAltura((void*)x->dir);
        visitarAltura(no);
    }
}

/* Retorna a altura de "no". */
int altura(void* no){
    if(no != NULL){
        setAltura(no);
        Node *x = (Node*)no;
        return x->altura;
    }

    printf("Argumento NULL!!!\n");
    return (-1);
}