#include <stdio.h>
int palindrome(int, int);

int main(){
	do{
		int a, i, tam=1;
		scanf("%d",&a);
		if (a<0) break;
		for(i=1; i<a; i*=10){
			tam +=1;
		}
		if (palindrome(a, tam)) printf("VERDADEIRO\n");
		else printf("FALSO\n");	
	}while(1);
}

int palindrome(int a, int tam){
	char string[tam];
	sprintf(string, "%d", a);
	for (int i = 0; i < (tam-1)/2; ++i){
		//printf("%c e %c\n",stringA[i],stringB[tam-2-i]);
		if (string[i]!=string[tam-2-i]) return 0;
	}
	return 1;
}