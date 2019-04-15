#include <stdio.h>
#include <stdlib.h>

int **transp(int **mat,int l, int c){
	int i,j;
	int **resp;
	resp = (int**)malloc(sizeof(int*)*c);
	for(i=0;i<l;i++){
		resp[i]=(int*)malloc(sizeof(int*)*l);
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			resp[j][i] = mat[i][j];
		}
	}
	return resp;
}
int main(void){
	int l,c;
	scanf("%d",&l);
	scanf("%d",&c);
	int **mat;
	int **resp;
	mat = (int**)malloc(sizeof(int*)*l);
	int i,j,num;
	for(i=0;i<l;i++){
		mat[i]=(int*)malloc(sizeof(int*)*c);
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			scanf("%d",&num);
			mat[i][j]=num;
		}
	}
	resp = transp(mat, l,c);
	return 0;
}