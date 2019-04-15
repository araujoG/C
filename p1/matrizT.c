#include <stdio.h>
#include <stdlib.h>

int ** eS(int** mat, int nl, int nc){
    if (nl != nc) return NULL;
    int i, j;
    for (i = 1; i<nl; i++){
        for (j = 0; j<i; j++){
            if (mat[i][j] != mat[j][i]) return NULL;
        }
    }
    int** resp = (int**)malloc(sizeof(int*)*nl);
    for (int i= 0; i<nl; i++){
        resp[i] = (int*)malloc((i+1)*sizeof(int));//matriz Triangular colunas = i+1 a cada linha i
    }
    for (int i= 0; i<nl; i++){
        for (int j= 0; j<=i; j++){
            resp[i][j] = mat[i][j];
        }
    }
    return resp;
}

int main(){
    int nl,nc;
    int** mat = (int**)malloc(nl*sizeof(int*));//vetor de vetores
    for( int i = 0; i<nl; i++){
        mat[i] = (int *)malloc(sizeof(int)*nc);//vetor comum
    }
    for( int i = 0; i<nl; i++){
        free(mat[i]);//Liberar os vetores que compõem esses vetores
    }
    free(mat);
}