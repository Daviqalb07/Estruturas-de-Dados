#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/*
cd Estruturas/Queue
gcc main.c queue.c -o main
./"main.exe"
*/
int main(void){
    Queue fila = constructQueue();
    int option = -1;
    while(option != 0){
        printf("\n");
        printf("1. Consulta se fila esta vazia.\n");
        printf("2. Enfileirar\n");
        printf("3. Remover.\n");
        printf("4. Tamanho da fila.\n");
        printf("5. Elemento na frente.\n");
        printf("6. Elemento no final.\n");
        printf("0. Encerra o programa.\n");
        printf("Selecione o que quer fazer: ");
        scanf("%d", &option);
        
        printf("\n");
        if(option == 1){
            if(emptyQueue(fila)){
                printf("A fila esta vazia, atualmente\n");
            }
        }
        else if(option == 2){
            int temp;
            printf("Adicionar elemento: ");
            scanf("%d", &temp);
            pushQueue(&fila, temp);

            printf("O elemento %d foi adicionado a fila.\n", temp);
        }

        else if(option == 3){
            int pop = popQueue(&fila);
            printf("Elemento eliminado: %d\n", pop);
        }

        else if(option == 4){
            printf("Tamanho = %d\n", sizeQueue(&fila));
        }

        else if(option == 5){
            int front = frontQueue(&fila);
            printf("Front: %d\n", front);
        }

        else if(option == 6){
            int back = backQueue(&fila);
            printf("Front: %d\n", back);
        }
    }
    return 0;
}