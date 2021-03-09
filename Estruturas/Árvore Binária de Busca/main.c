#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void){
    void* BST = constructBST(); // Árvore binária de busca.
    int v[] = {15, 26, 25, 5, 28, 13, 20, 8, 12, 6};

    for(int i = 0 ; i < 10 ; i++){
        incluirBST(BST, v[i]);
    }

    void* root = raizBST(BST);

    imprimirBST(BST);

    void* n1 = buscaBST(root, 25);
    void* minimo = minimoBST(root);
    void* maximo = maximoBST(root);

    sucessorBST(n1);
    predecessorBST(minimo);

    int nos = quantidadeNos(root);
    int h = altura(root);
    printf("Numero de nos da arvore = %d\n", nos);
    printf("Altura da arvore = %d\n", h);

    removerBST(BST, n1);

    printf("\nApos remover o no com chave 25:\n\n");

    imprimirBST(BST);
    nos = quantidadeNos(root);
    h = altura(root);

    printf("Numero de nos da arvore = %d\n", nos);
    printf("Altura da arvore = %d\n", h);

    /* 
    SAÍDA:

    5 6 8 12 13 15 20 25 26 28 
    No com chave 25 encontrado!
    Valor minimo da arvore: 5
    Valor maximo da arvore: 28
    Sucessor de 25 no percurso em Em-Ordem: 26
    O no atual não tem predecessor pois eh o valor minimo.
    Numero de nos da arvore = 10
    Altura da arvore = 4

    Apos remover o no com chave 25:

    5 6 8 12 13 15 20 26 28 
    Numero de nos da arvore = 9
    Altura da arvore = 4
    */
    free(root);
    free(BST);
    return 0;
}