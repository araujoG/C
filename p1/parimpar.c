#include <stdio.h>
#include <stdlib.h>

void ip_v(int n, int *vet){
	int aux, i = 0;
	int j = 0;
	int k = 0;
	int par[n];
	while(i<n){
		aux = vet[i++];
		if ((aux % 2)){
			vet[k++] = aux;
		}else{
			par[j++] = aux;
		}
	}
	for(i=0; i<j; i++){
		vet[k++] = par[i];
	}
}
int* ip_ad(int n, int *vet){
	int i,j=0;
	int *resp = (int*) malloc(n*sizeof(int));
	for( i = 0; i < n; i++){
		if (vet[i]%2) {
			resp[j++] = vet[i];
		}
	}
	for( i = 0; i < n; i++){
		if (!(vet[i]%2)){
			resp[j++] = vet[i];	
		}
	}
	return resp;
}

int main(){
	int n = 8;
	int vet[] = {2, 4, 7, 8, 9,1,6,11}; 
	int *saida = ip_ad(n, vet);
	ip_v(n, vet);
	for(int i = 0; i < n; i++){
		printf("Resp [%d]= %d e %d\n",i,saida[i],vet[i]);
	}
	
}

