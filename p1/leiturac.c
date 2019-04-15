#include <stdio.h>
#include <stdlib.h>
void lc_v(int n, int *vet){
    int aux, i = 0;
    scanf("%d",&vet[i]);
    int ant = vet[i++];
    while (i<n){
        scanf("%d",&aux);
        if (aux>ant){
            vet[i++] = aux;
            ant = aux;
            printf("ok\n");
        } 
    }
}

int* lc_ad(int n){
    int *v = (int*) malloc(n*sizeof(int));
    int i = 0,aux,ant;
    scanf("%d",&v[i]);
    ant = v[i++];
    while (i<n){
        scanf("%d",&aux);
        if (aux>ant){
            v[i++] = aux;
            ant = aux;
            printf("ok\n");
        } 
    }
    
    return v;
}

int main(){
    int n;
    scanf("%d",&n);
    int vet[n];
    lc_v(n,vet);
    int *resp = lc_ad(n);
    for(int i = 0; i < n; i++){
        printf("Dinamico[%d] = %d \t Estatico[%d] = %d\n",i,resp[i],i,vet[i]);
    }
    free(resp);

}