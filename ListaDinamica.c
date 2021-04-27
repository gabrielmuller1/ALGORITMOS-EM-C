/*
5. Construa programa em C ANSI que use uma lista dinâmica de palavras, deve ter um controle para usuário parar de
digitar as palavras e também uma opção para que o usuário solicite uma letra, o programa deve mostre as palavras
que começam com a letra digitada pelo usuário.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 etapa
typedef struct lista{
char palavra[25];
struct lista *proximo;
}LISTA;

int main (void){
// 2 etapa
LISTA *inicio = NULL;
do{
// 3 etapa
LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
printf("Digite uma palavra: (para parar digite: stop) ");
gets(novo->palavra);
fflush(stdin);
if(inicio == NULL){
novo->proximo=NULL;
inicio=novo;
}else{
novo->proximo=inicio;
inicio=novo;
}
}while(strcmp(inicio->palavra,"stop") != 0);
return 0;
}
