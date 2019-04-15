#include <stdio.h>
#include <stdlib.h>

typedef struct ABB{
    int info;
    struct ABB *dir, *esq;
}TAB;


TAB* inicializa();
TAB* cria();
void imp_sim(TAB* a);
void imp_pos(TAB* a);
void imp_pre(TAB* a);
void imp_larg(TAB* a);
void libera(TAB* a);
TAB* busca_abb(TAB* a, int elem);
TAB* busca(TAB* a, int elem);
void retira(TAB* a, int elem);
TAB* maior(TAB* a);