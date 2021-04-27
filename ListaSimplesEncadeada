/* 1 Elabore um algoritmo que leia uma sequÃªncia de nÃºmeros, armazenando-os numa lista simplesmente encadeada e que, 
em seguida, verifique se a lista linear encadeada estÃ¡ ordenada. Suponha que a lista nÃ£o contenha nÃºmeros repetidos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
}LISTA;

LISTA* inserir(LISTA *l, int num);
int ordenada(LISTA *l);

int main (void){
	LISTA *inicio = NULL;
	int numero=0;
	
	while(numero!=-1){
		printf("Digite um numero (para sair -1): ");
		scanf("%i",&numero);
		fflush(stdin);
		if(numero!=-1){
			inicio=inserir(inicio, numero);
		}
	}
	
	if (ordenada(inicio)==1){
		printf("Esta ordernada\n");
	}else{
		printf("Nao esta ordernada\n");
	};
	return 0;
}

LISTA* inserir(LISTA *l, int num){
	LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
	novo->num=num;
	if(l==NULL){
		novo->prox=NULL;
		l=novo;
	}else{
		novo->prox=l;
		l=novo;
	}
	return l;
}

int ordenada(LISTA *l){
	int flag = 1;
	LISTA *L1, *L2;
	L1 = l;
	L2 = l->prox;
	while(L1!=NULL && L2!=NULL){
		if (L1->num < L2->num){
			flag = 0;
		}
		L1=L2;
		L2=L2->prox;
	}
	if( flag == 0){
		flag = 1;
		L1 = l;
		L2 = l->prox;
		while(L1!=NULL && L2!=NULL){
			if (L1->num > L2->num){
				flag = 0;
			}
			L1=L2;
			L2=L2->prox;
		}
	}
	return flag;
}
