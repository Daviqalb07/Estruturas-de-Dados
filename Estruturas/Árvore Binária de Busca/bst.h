#define __BST_H__
#ifdef __BST_H__

#include <stdlib.h>

#define max(a, b) a > b ? a : b

/* Constrói e aloca a árvore binária de busca. */
void* constructBST();

/* Inclui os nós na árvore. */
void incluirBST(void* arvore, int k);

/* Retorna um ponteiro para a raiz da árvore. */
void* raizBST(void* arvore);

/* Percurso em Em-Ordem. */
static void emOrdem(void* raiz);

/* Imprimir os nós da árvore em um percurso em Em-Ordem. */
void imprimirBST(void* T);


/* Buscar numa árvore binária de busca. */
void* buscaBST(void* root, int k);

/* Algoritmo de busca recursiva */
void* buscaRecursivaBST(void* root, int k);

/* Encontrar valor mínimo. */
void* minimoBST(void* root);

/* Encontrar valor máximo. */
void* maximoBST(void* root);

/* Sucessor, no percurso em Em-Ordem de um nó. */
void* sucessorBST(void* no);

/* Predecessor, no percurso em Em-Ordem de um nó. */
void* predecessorBST(void* no);


/*  Função para transmutar árvores enraizadas em nós distintos. (um pode ser NULL)
    Auxiliará na hora de remover nós.*/
static void transplant(void* arvore, void* n1, void* n2);

/* Remove um nó da árvore. */
void removerBST(void* arvore, void* no);


static void visitarContarNos(void* no);

/* Contar os nós em uma subárvore. */
static void contarNos(void* no);

/* Retorna os nós da subárvore enraizada em "no"*/
int quantidadeNos(void *no);

static void visitarAltura(void* no);

/* Calcula a altura de todos os nós da subárvore enraizada em "no".*/
static void setAltura(void* no);

/* Retorna a altura de "no". */
int altura(void* no);

#endif
