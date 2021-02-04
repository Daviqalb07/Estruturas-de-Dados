#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

typedef struct Node{
    int chave;
    struct Node *prox;
    struct Node *ant;
} No;

typedef struct{
    No *nulo;
} Lista;

void *criarLista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->nulo = (No*)malloc(sizeof(No));

    l->nulo->prox = l->nulo;
    l->nulo->ant = l->nulo;

    return (void*)l;
}

void apagarLista(void *L){
    Lista *list = (Lista*)L;

    while(list->nulo->prox != list->nulo){
        removerLista(L, (void*)list->nulo->prox);        
    }

    free(list->nulo);
    free(list);
}

void imprimirLista(void *L){
    Lista *list = (Lista*)L;
    No *x = list->nulo->prox;

    while(x != list->nulo){
        printf("%d ", chave((void*)x));
        x = x->prox;
    }
    printf("\n");
}

void incluirLista(void *L, int k){
    Lista *list = (Lista*)L;
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = k;
    novo->prox = list->nulo;
    novo->ant = list->nulo->ant;
    list->nulo->ant->prox = novo;
    list->nulo->ant = novo;
}

void *buscar(void *L, int k){
    Lista *list = (Lista*)L;
    No *x = list->nulo->prox;
    list->nulo->chave = k;

    while(x->chave != k){
        x = x->prox;
    }

    if(x == list->nulo){
        printf("Nao foi encontrada um elemento com chave %d\n", k);
        return NULL;
    }
    printf("Elemento encontrado!\n");
    return (void*)x;
}

int chave(void *x){
    No *r = (No*)x;
    return r->chave;
}

void removerLista(void *L, void *x){
    Lista *list = (Lista*)L;
    No *r = (No*)x;

    r->ant->prox = r->prox;
    r->prox->ant = r->ant;

    free(r);
}
