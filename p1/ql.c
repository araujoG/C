#include <stdio.h>
#include <stdlib.h>
int buscaL(int *vet,int N,int elem){
	int i;
	for (i=0;i<N;i++){
		if (vet[i]==elem) return 0;
	}
	return 1;
}
int ql(int **mat,int N){
	int i,j,pad,soma;
	pad=0;
	for(i=0;i<N;i++){
		for(j=1;j<=N;j++){
			if(buscaL(mat[i],N,j)) return 0;
		}
	}
	for (i=1;i<=N;i++){
		pad += i;
	}
	for (i=0;i<N;i++){
		soma = 0;
		for (j=0;j<N;j++){
			soma += mat[j][i];
		}
		if(soma!=pad){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int N,resp;
	scanf("%d",&N);
	int **mat;
	mat = (int**)malloc(sizeof(int*)*N);
	int i,j,num;
	for(i=0;i<N;i++){
		mat[i]=(int*)malloc(sizeof(int*)*N);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&num);
			mat[i][j]=num;
		}
	}
	if (ql(mat,N)) {
		printf("A matriz é um quadrado latim!!!\n");
	}
	else 
		printf("A matriz não é um quadrado latim...\n");
}