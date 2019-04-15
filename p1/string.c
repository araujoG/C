#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void shift_troca_strig(char* str){
// 	char letra;
// 	int i;
// 	for(i = 0; str[i] != '\0'; i++){
// 		letra = str [i];
// 		switch (letra){
// 			case 'A':
// 				letra += 25 + 32;
// 				break;
// 			case 'a':
// 				letra += 25 - 32;
// 				break;
			
// 			default:
// 				if (letra > 65 && letra<91) letra += 31;
// 				else{
// 					if (letra>97 && letra<123) letra -= 33;
// 					else letra = '!';
// 				}
// 				break;
// 		}
// 		str[i] = letra;
// 	}
// }
// char* codifica(char* str){
// 	int i,j;
// 	for(i = 0; str[i] != '\0'; i++){}
// 	char * resp= (char*)malloc((i+1)*sizeof(char));
// 	for(j = 0; str[j] != '\0'; j++){
// 		if (str[j] == 97 || str[j] == 101 || str[j] == 105 || str[j] == 111 || str[j] == 117){
// 			resp[j] = '?';
// 		}else resp[j] = str[j];
// 	}
// 	resp[j] = str[j];
// 	printf("Espaço : %c\n",resp[j]);
// 	return resp;
// }

// void retira_inicio_n(char *str, int n){
// 	int i,j;
// 	for(i = 0; str[i] != '\0'; i++){}
// 	if (!(i<n)){
// 		for (j = n; j<i; j++){
// 			str[j-n] = str[j];
// 		}
// 		str[j-n] = '\0';
// 	}else str = 'erro';
// }

// void retira_fim_n(char *str, int n){
// 	int i;
// 	for(i = 0; str[i] != '\0'; i++){}
// 	str[i-n] = '\0';
// }

int main(void){
	char str[5];
	char * r;
	scanf("%s",str);
	//shift_troca_strig(str);
	//r = codifica(str);
	//printf("%s",r);
	//retira_inicio_n(str,5);
	//retira_fim_n(str,5);
	printf("%s",str);
}