/* Fazer uma lista duplamente encadeada de nÃºmeros */

#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int number;
    struct List* next;
    struct List* previous;
}LIST;

int main(void){
    LIST* listInit = NULL;
    LIST* listFinal = NULL;
    int number;

    do{
        printf("Digite um numero (-1 para sair): ");
        scanf("%i", &number);
        fflush(stdin);

        if(number != -1){
            LIST* list = (LIST*) malloc(sizeof(LIST));
            list->number = number;

            if(listInit == NULL){
                list->previous = NULL;
                list->next = NULL;
                listInit = list;
                listFinal = list;
            }else{
                list->next = listInit;
                listInit->previous = list;
                list->previous = NULL;
                listInit = list;
            }
            
        }

    }while(number != -1);

    printf("\nPelo inicio:\n");
    LIST* provisionalInit;
    provisionalInit = listInit;

    while(provisionalInit != NULL){
        printf("%i ", provisionalInit->number);
        provisionalInit = provisionalInit->next;
    }

    printf("\n\nPelo final:\n");
    LIST* provisionalFinal;
    provisionalFinal = listFinal;

    while(provisionalFinal != NULL){
        printf("%i ", provisionalFinal->number);
        provisionalFinal = provisionalFinal->previous;
    }

    return 0;
}
