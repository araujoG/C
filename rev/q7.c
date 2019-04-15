#include "lista.h"

TLSE* rto(TLSE *l, int elem){
    TLSE* resp = (TLSE*) malloc(sizeof(TLSE));
    resp = NULL;
    while(l){
        if (l->info != elem) resp = inserel(resp,l->info);
        l = l->prox;
    }
    TLSE* p = resp;
    TLSE* fim = (TLSE*) malloc(sizeof(TLSE));
    fim = NULL;
    while(p){
        fim = inserel(fim,p->info);
        p = p->prox;
    }
    liberal(resp);
    return fim;
}

int main(){
    TLSE* lista = (TLSE*) malloc(sizeof(TLSE));
    lista = NULL;
    lista = inserel(lista,1);
    lista = inserel(lista,3);
    lista = inserel(lista,9);
    lista = inserel(lista,3);
    lista = inserel(lista,5);
    lista = inserel(lista,6);
    imprimel(lista);
    printf("\n");
    lista = rto(lista,3);
    imprimel(lista);
    printf("\n");
}