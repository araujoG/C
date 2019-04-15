#include <stdio.h>

int compara1(int a, int b){
	int i = 1;
	int cont = 0;
	while(i<a && i<b){
		i = i*10;
		cont += 1;
	}
	if (b>i || a>i) return 0;
	else return cont;
}

int comparavet(int a, int b, int tamanho){
	int i,j,n=10;
	int veta[tamanho], vetb[tamanho];
	for (i=0;i<tamanho;i++){
		veta[i] = a%n;
		a = a/n;
		vetb[i] = b%n;
		b = b/n;
	}
	int resp;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			if (veta[i]==vetb[j]){
				resp = 1;
				printf("%d e %d são %d\n",veta[i],vetb[j],resp);
				vetb[j] = 0;
				break;
			}else resp = 0;
			
		}
		if (!resp) return resp;
	}
	return resp;
}

int main(void){
	do{
		int a,b,tamanho;
		int resp;
		scanf("%d%d",&a,&b);
		if (!a || !b) break;
		if (compara1(a,b)) {
			if (comparavet(a,b,compara1(a,b))) printf("Os números são permutações\n");
			else printf("Os números não são permutações...\n");
		}
		else printf("Os números não são permutações...\n");
	}while(1);
}