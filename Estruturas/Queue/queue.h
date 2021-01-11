#define __QUEUE_H__
#ifdef __QUEUE_H__

#include <stdbool.h>

struct Node{
    int chave;
    struct Node *prox;
};

typedef struct Node No;

typedef struct{
    No *front;
    No *back;
}Queue;

Queue constructQueue();

bool emptyQueue(Queue fila);

void pushQueue(Queue *fila, int k);

int popQueue(Queue *fila);

int frontQueue(Queue *fila);

int backQueue(Queue *fila);

int sizeQueue(Queue *fila);
#endif
