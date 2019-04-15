#include "TFILA.h"

TFILA *criaf(void){
    TFILA *f = (TFILA *) malloc(sizeof(TFILA));
    f->ini = f->fim = NULL;
    return f;
}

int vaziaf(TFILA *f){
    return (f->ini == NULL);
}

void inseref(TFILA* f, int elem){
    TNO* novo = (TNO*) malloc(sizeof(TNO));
    novo->info = elem;
    novo->prox = NULL;
    if(vaziaf(f))
        f->ini = novo;
    else{
        f->fim->prox = novo;    
    }
    f->fim = novo;   
}

int retiraf(TFILA *f){
    if(vaziaf(f))
        return INT_MIN;
    TNO* t = f->ini;
    int resp = t->info;
    f->ini = t->prox;
    if(f->ini == NULL)
        f->fim = NULL;
    free(t);
    return resp;
}

void liberaf(TFILA* f){
    while(!vaziaf(f)){
        retiraf(f);
    }
    free(f);
}

void imprimef(TFILA *f){
    impnof(f->ini);
}

void impnof(TNO *l){
    if(l){
        printf("%d\n",l->info);
        impnof(l->prox);
    }
}