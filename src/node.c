#include <stdlib.h>
#include "node.h"

struct node {
    Cliente *data;
    struct node *next;
};

Node *cria_node(Cliente *cliente) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) return NULL;
    n->data = cliente;
    n->next = NULL;
    return n;
}

void destroi_node(Node *node) {
    if (node) free(node);
}

Cliente *get_data(Node *node) {
    return node ? node->data : NULL;
}

Node *get_next(Node *node) {
    return node ? node->next : NULL;
}

void set_next(Node *node, Node *next) {
    if (node) node->next = next;
}

