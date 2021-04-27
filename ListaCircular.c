/* Fazer uma lista circular de nÃºmeros */
#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int number;
    struct List* next;
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
                listInit = list;
                listFinal = list;
                listFinal->next = listInit;
            }else{
                list->next = listInit;
                listInit = list;
                listFinal->next = listInit;
            }
            
        }

    }while(number != -1);

    printf("\nPelo inicio:\n");
    LIST* provisionalInit;
    provisionalInit = listInit;

    do{
        printf("%i ", provisionalInit->number);
        provisionalInit = provisionalInit->next;
    }while(provisionalInit != listInit);

    printf("\n\nPelo final:\n");
    LIST* provisionalFinal;
    provisionalFinal = listFinal;

    do{
        printf("%i ", provisionalFinal->number);
        provisionalFinal = provisionalFinal->next;
    }while(provisionalFinal != listFinal);

    return 0;
}
