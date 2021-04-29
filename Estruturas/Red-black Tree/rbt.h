#define __RBT_H__
#ifdef __RBT_H__

#include <stdbool.h>

#define RED 1
#define BLACK 0

typedef struct No Node;

// Tree = implementação da Red-black Tree
typedef struct arvore Tree;

// Inicializa a Red-black Tree
// Retorna um ponteiro para a mesma.
Tree *constructRedBlackTree();

// Retorna o ponteiro para a raiz da árvore. (Útil ao trabalhar no arquivo main).
Node *rootRBT(Tree *RBT);

// Verifica se a árvore está vazia.
// Retorna true, caso a árvore esteja vazia ou false, caso contrário.
bool isEmptyRBT(Tree *RBT);

// Retorna a chave do nó x.
int getKey(Node *x);

// Retorna a cor do nó.
// RED = 1
// BLACK = 0
int getColor(Node *x);

// Inclui um nó x com chave k na árvore.
void insertRBT(Tree *RBT, int k);

// Conserta a inclusão conforme as propriedades rubro-negras.
static void fixInsertRBT(Tree *RBT, Node *z);

// Rotação à esquerda.
static void leftRotation(Tree *RBT, Node *x);

// Rotação à direita.
static void rightRotation(Tree *RBT, Node *x);


// Busca o nó com chave k na Red-black Tree. 
// Retorna o nó x com chave k, caso exista, ou -1 (com mensagem de erro) caso contrário.
Node *buscaRBT(Tree *RBT, Node *root, int k);

// Retorna o nó presente na árvore com chave de valor máximo.
Node *maximoRBT(Tree *RBT, Node *root);

// Retorna o nó presente na árvore com chave de valor mínimo.
Node *minimoRBT(Tree *RBT, Node *root);

// Imprime a árvore de acordo com os níveis.
void printRBT(Tree *RBT, Node *x, int nivel);
#endif