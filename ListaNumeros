#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int numero;
    struct list* next;
}LIST;

LIST* inverted(LIST* list);
LIST* insert(LIST* list, int numero);
void printList(LIST* list);

LIST* inverted(LIST* list){
    LIST* newList = NULL;

    while(list != NULL){
        newList = insert(newList, list->numero);
        list = list->next;
    }

    return newList;
}

LIST* insert(LIST* list, int numero){
	LIST* newList = (LIST*) malloc(sizeof(LIST));
	newList->numero = numero;

	if(list == NULL){
		newList->next = NULL;
		list = newList;
	}else{
		newList->next = list;
		list = newList;
	}
	return list;
}

void printList(LIST* list){
    while(list != NULL){
        printf("%i ", list->numero);
        list = list->next;
    }
}


int main(void){
    LIST* numerolista = NULL;
    int numero;

    do{
        printf("Digite um numero (digite -1 para sair): ");
        scanf("%i", &numero);
        fflush(stdin);

        if(numero != -1){
            numerolista = insert(numerolista, numero);  
        }
        
    }while(numero != -1);

    printf("Lista normal: ");
    printList(numerolista);
    printf("\n");
    printf("Lista invertida: ");
    printList(inverted(numerolista));
    printf("\n");
    printf("Lista normal: ");
    printList(numerolista);
    

    return 0;
}
