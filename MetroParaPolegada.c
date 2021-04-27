#include <stdio.h>

#define pol 0.3937


void calcpolegadas(float *valor);
int main () {
    float metro, polegadas, pes;
    
    printf ("Insira o valor em metros:\n");
    scanf ("%f", &metro);
    calcpolegadas(&metro);
           
    return 0;
} 

void calcpolegadas(float *valor){ 

printf("valor em polegadas: %f", *valor *39.37);
}
