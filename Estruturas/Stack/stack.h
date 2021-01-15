#define __STACK_H__
#ifdef __STACK_H__

#include <stdbool.h>
struct Node{
    int chave;
    struct Node *prox;
};

typedef struct Node No;

typedef struct{
    No *top;
}Stack;

Stack constructStack();

bool emptyStack(Stack pilha);

void pushStack(Stack *pilha, int k);

int popStack(Stack *pilha);

int topStack(Stack *pilha);

int sizeStack(Stack *pilha);
#endif