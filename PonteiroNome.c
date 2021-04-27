#include<stdio.h>

void imprimir(int* lines, int* columns, char* text);

void imprimir(int* lines, int* columns, char* text){
    int* x;
    int* y; // Converter para ponteiro

    system("cls");

    for(x = 1; x < *lines; x++){
        printf("\n");
    }
    for(y = 1; y < *columns; y++){
        printf(" ");
    }
    printf("%s", text); // sem &, apenas a variÃ¡vel
}

int main(void){
    char text[] = {"Pedro da Silva"};
    int lines=2, columns = 2;
    imprimir(&lines, &columns, text);
    
    return 0;

}
