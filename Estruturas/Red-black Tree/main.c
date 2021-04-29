#include <stdio.h>
#include "rbt.h"

int main(void){
    Tree *RBT = constructRedBlackTree();
    
    int v[] = {20, 9, 3, 42, 4, 36, 30, 6};
    for(int i = 0 ; i < 8 ; i++){
        insertRBT(RBT, v[i]);
    }
    Node *root = rootRBT(RBT);

    // Consultando a raiz.
    printf("Chave do no raiz: %d\n", getKey(root));
    printf("Cor do no raiz: "); // Confirmando que a raiz é BLACK.
    if(getColor(root) == RED)
        printf("Red\n");
    else
        printf("Black\n");
    printf("\n");

    // Operações de busca
    buscaRBT(RBT, root, 30);
    buscaRBT(RBT, root, 15);

    printf("\n");

    // Máximos e mínimos.
    Node *max = maximoRBT(RBT, root);
    int colorMax = getColor(max);
    printf("Cor do no de chave maxima: ");
    if(colorMax == RED)
        printf("Red\n");
    else
        printf("Black\n");
    

    Node *min = minimoRBT(RBT, root);
    int colorMin = getColor(min);
    printf("Cor do no de chave minima: ");
    if(colorMin == RED)
        printf("Red\n");
    else
        printf("Black\n");
    
    printf("\n");
    
    // Imprimindo a árvore completa.
    printRBT(RBT, root, 0);
    return 0;
}