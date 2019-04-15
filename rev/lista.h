#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int info;
  struct lista *prox;
} TLSE;


TLSE* inserel(TLSE *l, int elem);
void imprimel(TLSE *l);
void liberal(TLSE *l);
TLSE* retiral(TLSE *l, int elem);
TLSE* buscal(TLSE *l, int elem);

