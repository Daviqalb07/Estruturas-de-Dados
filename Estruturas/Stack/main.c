#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void){
    Stack pilha = constructStack();

    system("clear || cls");
    int option = -1;
    while(option != 0){
        printf("\n\n");
        printf("1. Consulta se pilha esta vazia.\n");
        printf("2. Empilhar.\n");
        printf("3. Desempilhar.\n");
        printf("4. Tamanho da pilha.\n");
        printf("5. Elemento no topo.\n");
        printf("0. Encerra o programa.\n");
        printf("Selecione o que quer fazer: ");
        scanf("%d", &option);

        if(option == 0) continue;

        if(option == 1){
            if(emptyStack(pilha)){
                printf("A pilha esta vazia.\n");
            }
            else{
                printf("Pilha nao vazia.\n");
            }
        }

        else if(option == 2){
            int push;
            printf("Digite o elemento a ser empilhado: ");
            scanf("%d", &push);

            pushStack(&pilha, push);
            printf("O elemento %d foi colocado no topo da pilha\n", push);
        }

        else if(option == 3){
            if(emptyStack(pilha)){
                printf("A PILHA JA ESTA VAZIA!\n");
            }
            else{
                int pop = popStack(&pilha);
                printf("Desempilhado. %d estava no topo da pilha.\n", pop);
            }
        }

        else if(option == 4){
            printf("Tamanho da pilha atualmente: %d\n", sizeStack(&pilha));
        }

        else if(option == 5){
            if(emptyStack(pilha)){
                printf("A pilha esta vazia.\n");
            }
            else{
                int topo = topStack(&pilha);
                printf("O topo da pilha eh o elemento %d.\n", topo);
            }
        }

        else{
            printf("Escolha invalida!\n");
        }
    }
    return 0;
}
