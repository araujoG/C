#include <stdio.h>
#include <stdlib.h>
void selectionSort(int n, int* vet){
    int i;
    for(i =0; i < n; i++){
        int menor=i, j, aux;
        for(j = i + 1; j < n; j++){
            if (vet[menor]>vet[j]) menor = j;
        }

        if (menor!= j){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
        }
    }
}

void selectionSortRec( int n, int* vet){
    if (n<=1) return;
    int menor=0, j, aux;
    for(j = 1; j < n; j++){
        if (vet[menor]>vet[j]) menor = j;
    }

    if (menor!= j){
        aux = vet[0];
        vet[0] = vet[menor];
        vet[menor] = aux;
    }
    selectionSortRec(n-1, &vet[1]);
}
int* SS(int n, int *vet){
    int* resp = (int*)malloc(n*sizeof(int));
    if(resp==NULL) exit(1);
    for( int i = 0; i<n; i++){
        resp[i] = vet[i];
    }
    selectionSortRec(n,resp);
    return resp;
}
int main(){
    int n = 3;
    int vet[] = {8,5,4};
    int *resp = SS(n,vet);
}