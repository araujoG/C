#include <stdio.h>
#include <stdlib.h>

typedef struct lsec{
  int info;
  struct lsec *prox;
} TLSEC;

TLSEC* ins_ordem1(TLSEC *l, int info);
TLSEC* ins_fim(TLSEC *l, int info);
TLSEC* retira(TLSEC *l, int info);
void imprime(TLSEC *l);
void libera(TLSEC *l);
