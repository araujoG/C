#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

TAB* cria_ab(int x, TAB* e, TAB* d);
void imprime_ab(TAB *t);
void libera_ab(TAB* t);
TAB* busca_ab(int e, TAB* t);
TAB* busca_abb(int e, TAB* t);
TAB* insere_abb(int e, TAB* t);
TAB* retira_abb(int e, TAB *t);
int zz_rec(TAB *a); // ok
int zz(TAB *a); // ok
int estbin(TAB *a); //alguns bugs
int mn(TAB *a1,TAB *a2); // ok
int mn_rec(TAB *a1,TAB *a2); // ok
TLSE* ancestrais_rec(TAB *a, int elem);
TLSE* ancestrais(TAB *a, int elem);


