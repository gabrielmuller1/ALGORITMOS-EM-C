/* Fazer uma lista para encontrar os itens em comum entre as listas e retornar a lista desses itens */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list{
    char name[25];
    struct list* next;
}LIST;

LIST* insert(LIST* list, char* name);
void printList(LIST* list);
LIST* commomItens(LIST* listA, LIST* listB);

LIST* insert(LIST* list, char* name){
    LIST* newList = (LIST*) malloc(sizeof(LIST));
    strcpy(newList->name, name);

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
        printf("Nome: %s\n", list->name);
        list = list->next;
    }
}

LIST* commomItens(LIST* listA, LIST* listB){
    LIST* listC = NULL;
    LIST* provisional;

    while(listA != NULL){
        provisional = listB;

        while(provisional != NULL){
            if(strcmp(listA->name, provisional->name) == 0){
                listC = insert(listC, listA->name);
            }
            provisional = provisional->next;
        }
       listA = listA->next;     
    }

    return listC;
}

int main(void){
    LIST* listA = NULL;
    LIST* listB = NULL;
    char name[25];

    printf("Lista A: \n");
    do{
        printf("Digite um nome: (-1 para sair): ");
        gets(name);
        fflush(stdin);
        
        if(strcmp(name, "-1") != 0){
            listA = insert(listA, name);
        }

    }while(strcmp(name, "-1") != 0);
    printList(listA);

    printf("\nLista B: \n");
    do{
        printf("Digite um nome: (-1 para sair): ");
        gets(name);
        fflush(stdin);
        
        if(strcmp(name, "-1") != 0){
            listB = insert(listB, name);
        }

    }while(strcmp(name, "-1") != 0);
    printList(listB);

    printf("\nLista de itens em comum: \n");
    printList(commomItens(listA, listB));
    
    return 0;
}
