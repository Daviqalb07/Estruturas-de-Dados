#define __LISTAENCADEADA_H__
#ifdef __LISTAENCADEADA_H__

void *criarLista();

void apagarLista(void *L);

void imprimirLista(void *L);

void incluirLista(void *L, int k);

void *buscar(void *L, int k);

int chave(void *x);

void removerLista(void *L, void *x);

#endif