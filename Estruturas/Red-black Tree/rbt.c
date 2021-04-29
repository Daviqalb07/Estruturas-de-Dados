#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rbt.h"

typedef struct No{
    int key;
    struct No *pai;
    struct No *esq;
    struct No *dir;
    int color; // RED (1) ou BLACK (0)
}Node;


typedef struct arvore{
    Node *root;
    Node *nulo; // Ponteiro único que representará todos os nós externos.
} Tree;

// Inicializa a Red-black Tree
// Retorna um ponteiro para a mesma.
Tree* constructRedBlackTree(){
    Tree *rbt = (Tree*)malloc(sizeof(Tree));
    Node *nulo = (Node*)malloc(sizeof(Node));

    nulo->color = BLACK;
    rbt->root = rbt->nulo = nulo;
    return rbt;
}

// Retorna o ponteiro para a raiz da árvore. (Útil ao trabalhar no arquivo main).
Node* rootRBT(Tree *RBT){
    return RBT->root;
}

// Verifica se a árvore está vazia.
// Retorna true, caso a árvore esteja vazia ou false, caso contrário.
bool isEmptyRBT(Tree *RBT){
    if(RBT->root == RBT->nulo) return true;

    return false;
}

// Retorna a chave do nó x.
int getKey(Node *x){
    return x->key;
}

// Retorna a cor do nó.
// RED = 1
// BLACK = 0
int getColor(Node *x){
    return x->color;
}

// Inclui um nó x com chave k na árvore.
void insertRBT(Tree *RBT, int k){
    Node *x = RBT->root;
    Node *y = RBT->nulo;
    
    bool left, right;
    left = right = false;
    while(x != RBT->nulo){
        y = x;
        if(k < x->key){
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

    Node *z = (Node*)malloc(sizeof(Node));
    z->key = k;
    z->esq = z->dir = RBT->nulo;
    z->pai = y;
    z->color = RED;

    if(y == RBT->nulo) RBT->root = z;

    else if(left) y->esq = z;

    else y->dir = z;

    fixInsertRBT(RBT, z);
}

// Conserta a inclusão conforme as propriedades rubro-negras.
static void fixInsertRBT(Tree *RBT, Node *z){
    while(z->pai->color == RED){
        if(z->pai == z->pai->pai->esq){
            Node *y = z->pai->pai->dir;
            if(y->color == RED){
                z->pai->color = y->color = BLACK;
                z->pai->pai->color = RED;

                z = y->pai;
            }
            else{
                if(y->color == BLACK && z == z->pai->dir){
                    z = z->pai;
                    leftRotation(RBT, z);
                }
                z->pai->color = BLACK;
                z->pai->pai->color = RED;
                rightRotation(RBT, z->pai->pai);
            }
        }
        else{
            Node *y = z->pai->pai->esq;
            if(y->color == RED){
                z->pai->color = y->color = BLACK;
                z->pai->pai->color = RED;

                z = y->pai;
            }
            else{
                if(y->color == BLACK && z == z->pai->esq){
                    z = z->pai;
                    rightRotation(RBT, z);
                }
                z->pai->color = BLACK;
                z->pai->pai->color = RED;
                leftRotation(RBT, z->pai->pai);
            }
        }
    }


    RBT->root->color = BLACK;
}

// Rotação à esquerda.
static void leftRotation(Tree *RBT, Node *x){
    Node *y = x->dir;
    
    x->dir = y->esq;
    if(y->esq != RBT->nulo)
        y->esq->pai = x;
    
    y->pai = x->pai;
    if(x->pai == RBT->nulo)
        RBT->root = y;
    else if(x == x->pai->dir)
        x->pai->dir = y;
    else
        x->pai->esq = y;

    y->esq = x;
    x->pai = y;
}

// Rotação à direita.
static void rightRotation(Tree *RBT, Node *x){
    Node *y = x->esq;
    
    x->esq = y->dir;
    if(y->dir != RBT->nulo)
        y->dir->pai = x;
    
    y->pai = x->pai;
    if(x->pai == RBT->nulo)
        RBT->root = y;
    else if(x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;

    y->dir = x;
    x->pai = y;
}

// Busca o nó com chave k na Red-black Tree. 
// Retorna o nó x com chave k, caso exista, ou -1 (com mensagem de erro) caso contrário.
Node* buscaRBT(Tree *RBT, Node *root, int k){
    Node *x = root;
    while(x != RBT->nulo && x->key != k){
        if(k < x->key)
            x = x->esq;
        else
            x = x->dir;
    }

    if(x != RBT->nulo)
        printf("No com chave %d encontrado!\n", x->key);
    else
        printf("ERRO: No com chave %d nao existe!\n", k);
    
    
    return x;
}

// Retorna o nó presente na subárvore enraizada em x com chave de valor máximo.
Node* maximoRBT(Tree *RBT, Node *root){
    Node *x = root;
    while(x->dir != RBT->nulo)
        x = x->dir;

    if(x == RBT->nulo)
        printf("ERRO: Arvore vazia!\n");
    else
        printf("Chave de valor maximo: %d\n", x->key);

    return x;
}

// Retorna o nó presente na árvore com chave de valor mínimo.
Node* minimoRBT(Tree *RBT, Node *root){
    Node *x = root;
    while(x->esq != RBT->nulo)
        x = x->esq;

    if(x == RBT->nulo)
        printf("ERRO: Arvore vazia!\n");
    else
        printf("Chave de valor minimo: %d\n", x->key);

    return x;
}

// Imprime a árvore de acordo com os níveis.
void printRBT(Tree *RBT, Node *x, int nivel){
    if(isEmptyRBT(RBT)){
        printf("Arvore vazia!\n");
        return;
    }

    if(x != RBT->nulo){
        printRBT(RBT, x->dir, nivel + 1);
        printf("\n");
    }

    for(int i = 0 ; i < nivel ; i++) 
        printf("\t");
    
    if(x == RBT->nulo)
        printf("NIL"); // NIL = representa os nós externos.
    else
        printf("%3d", x->key); // Imprime a chave dos nós internos.

    // RED = R
    // BLACK = B
    if(getColor(x) == RED) printf(" R");
    else printf(" B");

    printf("\n");

    if(x != RBT->nulo){
        printRBT(RBT, x->esq, nivel + 1);
        printf("\n");
    }
}