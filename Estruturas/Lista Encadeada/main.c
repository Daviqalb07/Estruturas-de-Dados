#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main(void){
    void *Lista = criarLista();

    for(int i = 1 ; i <= 10 ; i++){
        incluirLista(Lista, i);
    }

    void *no = buscar(Lista, 4);
    buscar(Lista, 15); // Imprime a mensagem que não encontrou o nó
    imprimirLista(Lista);

    removerLista(Lista, no);
    imprimirLista(Lista); // Imprime a lista sem o 4 (nó excluído)

    apagarLista(Lista);
    return 0;
}