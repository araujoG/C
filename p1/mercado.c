#include "mercado.h"

TPROD** aloca (int n){
    TPROD** resp = (TPROD **)malloc (sizeof(TPROD *) * n);
    if (resp == NULL) exit(1);
    int i;
    for(i=0; i < n; i++){
        resp[i] = (TPROD *) malloc(sizeof(TPROD));
        resp[i]->valid = (TD *) malloc(sizeof(TD));
        if((resp[i] == NULL) || (resp[i]->valid == NULL)){
            int j;
            for (j = 0; j < i; j++){
                free(resp[j]->valid);
                free(resp[j]);
            }
            free(resp);
            exit(1);
        }
    }
}

void libera (TPROD **vet, int n){
    int i;
    for(i=0; i < n; i++){ 
        free(vet[i]->valid);
        free(vet[i]);
    }
    free(vet);
}

void leitura (TPROD **vet, int n){
    int i;
    for(i=0; i < n; i++){ 
        scanf("%d%f%f%d%d",&vet[i]->cod,&vet[i]->peso,&vet[i]->preco,&vet[i]->valid->mes,&vet[i]->valid->ano);
    }
}

void escrita (TPROD **vet, int n){
    int i;
     for(i=0; i < n; i++){ 
        printf("Produto %d:\n\tCódigo:%d\n\tPeso:%f\n\tPreço:R$ %f\n\tValidade: %d/%d",i,vet[i]->cod,vet[i]->peso,vet[i]->preco,vet[i]->valid->mes,vet[i]->valid->ano);
    }
}

// (1) em ordem crescente de código;
// (2) se dois produtos possuem o mesmo código, o critério de desempate é a data de validade, isto é, o produto que possui a data de validade mais próxima aparecerá primeiro na prateleira; e 
// (3) se os empates persistirem, o critério de desempate é o preço, em ordem decrescente. 

int cmpf1 (TPROD *p1, TPROD *p2){
    if (p2->cod < p1->cod) return 1;
    if ((p2->cod == p1->cod) && (p2->valid->ano < p1->valid->ano)) return 1;
    if ((p2->cod == p1->cod) && (p2->valid->ano == p1->valid->ano) && (p2->valid->mes < p1->valid->mes)) return 1;
    if ((p2->cod == p1->cod) && (p2->valid->ano == p1->valid->ano) && (p2->valid->mes == p1->valid->mes) && (p2->preco > p1->preco)) return 1;
    return 0;
}

void ordena1 (TPROD **vet, int n){
    int i;
    for( i = 0; i < n; i++){
        int menor = i, j;
        for(j = i + 1; j < n; j++){
            if(cmpf1(vet[menor], vet[j])) menor = j;
        }
        if (menor != i){
            TPROD *aux = vet[menor];
            vet[menor] = vet[i];
            vet[i] = aux;
        }
    } 
}

int cmpf2 (TPROD *p1, TPROD *p2){
    if (p2->preco > p1->preco) return 1;
    if ((p2->preco == p1->preco) && (p2->valid->ano < p1->valid->ano)) return 1;
    if ((p2->preco == p1->preco) && (p2->valid->ano == p1->valid->ano) && (p2->valid->mes < p1->valid->mes)) return 1;
    if ((p2->preco == p1->preco) && (p2->valid->ano == p1->valid->ano) && (p2->valid->mes == p1->valid->mes) && (p2->cod < p1->cod)) return 1;
    return 0;
}

void ordena2 (TPROD **vet, int n){
    int i;
    for( i = 0; i < n; i++){
        int maior = i, j;
        for(j = i + 1; j < n; j++){
            if(cmpf2(vet[maior], vet[j])) maior = j;
        }
        if (maior != i){
            TPROD *aux = vet[maior];
            vet[maior] = vet[i];
            vet[i] = aux;
        }
    } 
}
