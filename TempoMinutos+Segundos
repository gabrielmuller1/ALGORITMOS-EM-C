#include <stdio.h>

typedef struct hor {
    int minuto;
    int segundo;
} Hor;

int horaSegundos(Hor tempo);

int main (void) {
    Hor hor;
    int res;
    
	printf("Informe os minutos: ");
	scanf("%i", &hor.minuto);
	fflush(stdin);
	
	printf("Informe os segundos: ");
	scanf("%i", &hor.segundo);
	fflush(stdin);

    res = horaSegundos(hor);

    printf("Total segundos: %d\n", res);

    return 0;
}

int horaSegundos(Hor tempo) {
    return (tempo.minuto * 60) + tempo.segundo;
}
