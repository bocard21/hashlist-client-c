#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "estrutura.h"

#define TAM_TABELA 17

struct estrutura {
    Lista *nome[TAM_TABELA];
    Lista *bairro[TAM_TABELA];
    Lista *pessoas[TAM_TABELA];
    Lista *criancas[TAM_TABELA];
    Lista *renda[TAM_TABELA];
};

static unsigned int hash_string(const char *s) {
    unsigned int h = 0;
    while (s && *s) {
        h = h * 31 + (unsigned char)(*s++);
    }
    return h;
}

static unsigned int hash_int(int v) {
    return (unsigned int)v;
}

static unsigned int hash_float(float f) {
    return (unsigned int)f;
}

Estrutura *cria_estrutura() {
    Estrutura *e = (Estrutura *)malloc(sizeof(Estrutura));
    if (!e) return NULL;
    for (int i = 0; i < TAM_TABELA; i++) {
        e->nome[i] = NULL;
        e->bairro[i] = NULL;
        e->pessoas[i] = NULL;
        e->criancas[i] = NULL;
        e->renda[i] = NULL;
    }
    return e;
}

void destroi_estrutura(Estrutura *e) {
    if (!e) return;
    for (int i = 0; i < TAM_TABELA; i++) {
        if (e->nome[i]) destroi_lista(e->nome[i], 0);
        if (e->bairro[i]) destroi_lista(e->bairro[i], 0);
        if (e->pessoas[i]) destroi_lista(e->pessoas[i], 0);
        if (e->criancas[i]) destroi_lista(e->criancas[i], 0);
        if (e->renda[i]) destroi_lista(e->renda[i], 0);
    }
    free(e);
}

void insere_cliente(Estrutura *e, TipoBusca tipo, Cliente *cliente) {
    if (!e || !cliente) return;
    unsigned int idx;
    Lista **tabela = NULL;

    switch (tipo) {
        case BUSCA_NOME:
            idx = hash_string(get_nome(cliente)) % TAM_TABELA;
            tabela = e->nome;
            break;
        case BUSCA_BAIRRO:
            idx = hash_string(get_bairro(cliente)) % TAM_TABELA;
            tabela = e->bairro;
            break;
        case BUSCA_PESSOAS:
            idx = hash_int(get_pessoas(cliente)) % TAM_TABELA;
            tabela = e->pessoas;
            break;
        case BUSCA_CRIANCAS:
            idx = hash_int(get_criancas(cliente)) % TAM_TABELA;
            tabela = e->criancas;
            break;
        case BUSCA_RENDA:
            idx = hash_float(get_renda(cliente)) % TAM_TABELA;
            tabela = e->renda;
            break;
        default:
            return;
    }

    if (tabela[idx] == NULL)
        tabela[idx] = cria_lista();
    insere_lista(tabela[idx], cliente);
}

Lista *recupera_cliente(Estrutura *e, TipoBusca tipo, float valor, const char *str) {
    if (!e) return NULL;
    Lista *res = cria_lista();
    if (!res) return NULL;
    Lista *bucket = NULL;
    unsigned int idx;
    Node *cursor;

    switch (tipo) {
        case BUSCA_NOME: // nome
            idx = hash_string(str) % TAM_TABELA;
            bucket = e->nome[idx];
            cursor = bucket ? get_inicio(bucket) : NULL;
            while (cursor) {
                Cliente *c = get_data(cursor);
                if (strcmp(get_nome(c), str) == 0)
                    insere_lista(res, c);
                cursor = get_next(cursor);
            }
            break;
        case BUSCA_BAIRRO: // bairro
            idx = hash_string(str) % TAM_TABELA;
            bucket = e->bairro[idx];
            cursor = bucket ? get_inicio(bucket) : NULL;
            while (cursor) {
                Cliente *c = get_data(cursor);
                if (strcmp(get_bairro(c), str) == 0)
                    insere_lista(res, c);
                cursor = get_next(cursor);
            }
            break;
        case BUSCA_PESSOAS: // pessoas
            idx = hash_int((int)valor) % TAM_TABELA;
            bucket = e->pessoas[idx];
            cursor = bucket ? get_inicio(bucket) : NULL;
            while (cursor) {
                Cliente *c = get_data(cursor);
                if (get_pessoas(c) == (int)valor)
                    insere_lista(res, c);
                cursor = get_next(cursor);
            }
            break;
        case BUSCA_CRIANCAS: // criancas
            idx = hash_int((int)valor) % TAM_TABELA;
            bucket = e->criancas[idx];
            cursor = bucket ? get_inicio(bucket) : NULL;
            while (cursor) {
                Cliente *c = get_data(cursor);
                if (get_criancas(c) == (int)valor)
                    insere_lista(res, c);
                cursor = get_next(cursor);
            }
            break;
        case BUSCA_RENDA: // renda
            idx = hash_float(valor) % TAM_TABELA;
            bucket = e->renda[idx];
            cursor = bucket ? get_inicio(bucket) : NULL;
            while (cursor) {
                Cliente *c = get_data(cursor);
                if (fabs(get_renda(c) - valor) < 0.0001f)
                    insere_lista(res, c);
                cursor = get_next(cursor);
            }
            break;
        default:
            break;
    }
    return res;
}

