#include "lista.h"

TLSE* i_p(TLSE *l){
    TLSE* p = l;
    TLSE* par = (TLSE*) malloc(sizeof(TLSE));
    par = NULL;
    TLSE* impar = (TLSE*) malloc(sizeof(TLSE));
    impar = NULL;
    while(p){
        if (p->info % 2){
            impar = inserel(impar,p->info);
        }else par = inserel(par,p->info);
        p = p->prox;
    }
    TLSE* resp = (TLSE*) malloc(sizeof(TLSE));
    resp = NULL;
    p = par;
    while(p){
        resp = inserel(resp,p->info);
        p = p->prox;
    }
    p = impar;
    while(p){
        resp = inserel(resp,p->info);
        p = p->prox;
    }
    liberal(impar);
    liberal(par);
    return resp;
}


int main(){
    TLSE* lista = (TLSE*) malloc(sizeof(TLSE));
    lista = NULL;
    lista = inserel(lista,1);
    lista = inserel(lista,3);
    lista = inserel(lista,9);
    lista = inserel(lista,8);
    lista = inserel(lista,5);
    lista = inserel(lista,6);
    imprimel(lista);
    printf("\n");
    lista = i_p(lista);
    imprimel(lista);
    printf("\n");
}