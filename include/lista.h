#ifndef LISTA_H
#define LISTA_H

#include "node.h"

/* Lista encadeada simples de clientes */
typedef struct lista Lista;

Lista *cria_lista();
void destroi_lista(Lista *lista, int free_clientes);
void insere_lista(Lista *lista, Cliente *cliente);

Node *get_inicio(Lista *lista);
int get_quantidade(Lista *lista);

#endif /* LISTA_H */
