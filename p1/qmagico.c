#include <stdio.h>
#include <stdlib.h>

int qm(int **mat,int N){
	int diagp,diags,linha,coluna,i,j,nc=N;
	diagp=diags=0;
	for(i=0;i<N;i++){
		nc--;
		diags += mat[i][nc];
		diagp += mat[i][i];
	}
	if (diags!=diagp) return 0;
	for(i=0;i<N;i++){
		coluna=linha=0;
		for(j=0;j<N;j++){
			linha += mat[i][j];
			coluna += mat[j][i];
		}
		if ((diagp!=coluna) || (coluna!=linha)) return 0;
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
	resp = qm(mat,N);
	if (resp) {
		printf("A matriz é um quadrado perfeito!!!\n");
	}
	else 
		printf("A matriz não é um quadrado perfeito...\n");
}