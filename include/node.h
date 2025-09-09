#ifndef NODE_H
#define NODE_H

#include "cliente.h"

/* Estrutura de um nodo da lista encadeada */
typedef struct node Node;

Node *cria_node(Cliente *cliente);
void destroi_node(Node *node);

Cliente *get_data(Node *node);
Node *get_next(Node *node);
void set_next(Node *node, Node *next);

#endif /* NODE_H */
