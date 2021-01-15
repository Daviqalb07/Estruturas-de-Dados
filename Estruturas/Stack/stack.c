#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack constructStack(){
    Stack *pilha = (Stack*)malloc(sizeof(Stack));

    pilha->top = NULL;

    return *pilha;
}

bool emptyStack(Stack pilha){
    if(pilha.top == NULL) return true;

    return false;
}

void pushStack(Stack *pilha, int k){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = k;
    novo->prox = pilha->top;

    pilha->top = novo;
}

int popStack(Stack *pilha){
    if(emptyStack(*pilha)){
        printf("PILHA VAZIA!\n");
        return -1;
    }

    int pop = pilha->top->chave;
    pilha->top = pilha->top->prox;
    return pop;
}

// Vê qual elemento está no topo da pilha atualmente.
int topStack(Stack *pilha){
    if(emptyStack(*pilha)){
        printf("A pilha esta vazia nesse momento.\n");
        return -1;
    }

    return pilha->top->chave;
}

// Verifica quantos elementos existem na pilha.
int sizeStack(Stack *pilha){
    if(emptyStack(*pilha)) return 0;

    No *x = pilha->top;
    int size = 0;
    while(x != NULL){
        size++;
        x = x->prox;
    }

    return size;
}