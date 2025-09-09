#include <stdlib.h>
#include <string.h> /* for strlen, memcpy */
#include "cliente.h"

struct cliente {
    char *nome;
    char *bairro;
    int pessoas;
    int criancas;
    float renda;
};

static char *dup_string(const char *s) {
    if (!s) return NULL;
    size_t len = strlen(s) + 1;
    char *copy = (char *)malloc(len);
    if (copy)
        memcpy(copy, s, len);
    return copy;
}

Cliente *cria_cliente(const char *nome, const char *bairro, int pessoas,
                      int criancas, float renda) {
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    if (!c) return NULL;
    c->nome = dup_string(nome);
    c->bairro = dup_string(bairro);
    if (!c->nome || !c->bairro) {
        free(c->nome);
        free(c->bairro);
        free(c);
        return NULL;
    }
    c->pessoas = pessoas;
    c->criancas = criancas;
    c->renda = renda;
    return c;
}

void destroi_cliente(Cliente *c) {
    if (!c) return;
    free(c->nome);
    free(c->bairro);
    free(c);
}

const char *get_nome(const Cliente *c) {
    return c ? c->nome : NULL;
}

const char *get_bairro(const Cliente *c) {
    return c ? c->bairro : NULL;
}

int get_pessoas(const Cliente *c) {
    return c ? c->pessoas : 0;
}

int get_criancas(const Cliente *c) {
    return c ? c->criancas : 0;
}

float get_renda(const Cliente *c) {
    return c ? c->renda : 0.0f;
}

