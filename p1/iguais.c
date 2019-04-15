#include <stdio.h>
#include <stdlib.h>

int ig(int **mat1,int l1,int c1,int **mat2,int l2,int c2){
	if ((l1!=l2)||(c1!=c2)) return 0;
	int i,j;
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			if (mat1[i][j] != mat2[i][j]) return 0;
		}
	}
	return 1;
}
int main(void){
	int l1,l2,c1,c2,i,j,num,resp;
	int **mat1,**mat2;
	printf("Matriz 1:\n");
	scanf("%d",&l1);
	scanf("%d",&c1);
	mat1 = (int**)malloc(sizeof(int*)*l1);
	for(i=0;i<l1;i++){
		mat1[i]=(int*)malloc(sizeof(int*)*c1);
	}
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&num);
			mat1[i][j]=num;
		}
	}
	printf("Matriz 2:\n");
	scanf("%d",&l2);
	scanf("%d",&c2);
	mat2 = (int**)malloc(sizeof(int*)*l2);
	for(i=0;i<l2;i++){
		mat2[i]=(int*)malloc(sizeof(int*)*c2);
	}
	for(i=0;i<l2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&num);
			mat2[i][j]=num;
		}
	}
	resp = ig(mat1, l1,c1,mat2,l2,c2);
	if (resp) printf("As matrizes 1 e 2 são iguais!!!\n");
	else printf("As matrizes são diferentes...\n");
}