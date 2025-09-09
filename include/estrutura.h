#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista.h"

/* Estrutura principal que contem as tabelas de hash */
typedef struct estrutura Estrutura;

typedef enum {
    BUSCA_NOME = 1,
    BUSCA_BAIRRO,
    BUSCA_PESSOAS,
    BUSCA_CRIANCAS,
    BUSCA_RENDA
} TipoBusca;

Estrutura *cria_estrutura();
void destroi_estrutura(Estrutura *e);

void insere_cliente(Estrutura *e, TipoBusca tipo, Cliente *cliente);
Lista *recupera_cliente(Estrutura *e, TipoBusca tipo, float valor, const char *str);

#endif /* ESTRUTURA_H */
