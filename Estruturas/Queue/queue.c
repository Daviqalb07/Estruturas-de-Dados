#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue constructQueue(){
    Queue *fila = (Queue*)malloc(sizeof(Queue));
    
    fila->front = NULL;
    fila->back = NULL;

    return *fila;
}

bool emptyQueue(Queue fila){
    if(fila.front == NULL) return true;

    return false;
}

void pushQueue(Queue *fila, int k){
    No *f = (No*)malloc(sizeof(No));
    f->chave = k;
    f->prox = NULL;
    if(emptyQueue(*fila)){
        fila->front = f;
    }
    else{
        fila->back->prox = f;
    }
    fila->back = f;

}

int popQueue(Queue *fila){
    if(emptyQueue(*fila)){
        printf("FILA VAZIA!\n");
        return -1;
    }

    
    int chave = fila->front->chave;
    fila->front = fila->front->prox;
    return chave;
}

//Consulta o elemento da fila que foi incluído a mais tempo, sem eliminá-lo.
int frontQueue(Queue *fila){
    if(emptyQueue(*fila)){
        printf("A fila esta vazia nesse momento.\n");
        return -1;
    }

    return fila->front->chave;
}

// Consulta o elemento incluído a menos tempo.
int backQueue(Queue *fila){
    if(emptyQueue(*fila)){
        printf("A fila esta vazia nesse momento.\n");
        return -1;
    }

    return fila->back->chave;
}

// Consulta quantos elementos estão atualmente na fila.
int sizeQueue(Queue *fila){
    if(emptyQueue(*fila)) return 0;

    int size = 0;
    No *x = fila->front;
    while(x != NULL){
        size++;
        x = x->prox;
    }

    return size;
}