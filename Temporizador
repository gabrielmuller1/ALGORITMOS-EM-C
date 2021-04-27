#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
int main (void) {
int minutos, i, j;
printf("Digite um tempo: ");
scanf("%i",&minutos);
for(i=minutos-1;i>=0;i--){
for(j=59;j>=0;j--){
system("cls");
printf("Falta para terminar o tempo: %2i:%2i",i,j);
sleep(1);
}
}
while(true){
system("cls");
system("color 20");
printf("Tempo terminou!\n\a");
sleep(1);
system("cls");
system("color 40");
printf("Tempo terminou!\n\a");
}
}

