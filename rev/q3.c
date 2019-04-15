#include "lista.h"

TLSE* desloca(TLSE *l, int n){
    TLSE* resp = (TLSE*) malloc(sizeof(TLSE));
    resp = NULL;
    TLSE* fim = (TLSE*) malloc(sizeof(TLSE));
    fim = NULL;
    TLSE *p = l;
    int prim = 0;
    while(p){
        resp = inserel(resp,p->info);
        prim = p->info; //prim = ultimo elemento válido
        p = p->prox;
    }
    p = l;
    if (!(n%2)){ //Se for par insere o primeiro no final
        fim = inserel(fim,l->info); //l->info = primeiro elemento
        p = resp;
        while(p->prox){
            fim = inserel(fim,p->info);
            p = p->prox;
        }
    }else{ //Se for impar insere o ultimo elemento no inicio
        p = resp->prox;
        while(p){
            fim = inserel(fim,p->info);
            p = p->prox;
        }
        fim = inserel(fim,prim);
    }
    
    return fim;
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
    lista = desloca(lista,3);
    imprimel(lista);
    printf("\n");
}