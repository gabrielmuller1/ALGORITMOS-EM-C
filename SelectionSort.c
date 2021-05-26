#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

// Prototipo de Função
void geraNumero(int *vet, int op);
void selectionSort(int *vet);
void imprimirVetor(int *vet);

// Variáveis Globais
int qtd_comparacoes, qtd_trocas;

int main(void) {
	// Variáveis
	int vet1[TAMANHO];
	float tempo_inicial, tempo_final;
		
	printf("Ordenado:\n");
	geraNumero(vet1,1);
	tempo_inicial = clock();
	selectionSort(vet1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    
	
	printf("\nInvertido:\n");
	geraNumero(vet1,2);
	tempo_inicial = clock();
	selectionSort(vet1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
	
	printf("\nAleatorio:\n");
	geraNumero(vet1,3);
	tempo_inicial = clock();
	selectionSort(vet1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
	
	return 0;
}

// Função geração de números
void geraNumero(int *vet, int op) {
    int i, j;

    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            break;
        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++) {
               vet[i] = TAMANHO-i;
            }
            break;
        case 3: // Aleatórios
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = (int) (rand() % TAMANHO);
            }
            break;
    }

}

// Função ordenação Selection Sort
void selectionSort(int *vet){
	int i, j, eleito, menor, pos;
  
  	qtd_trocas = 0; qtd_comparacoes = 0;
  	
	for (i = 0; i < TAMANHO-1; i++) {
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;
        for (j = i + 2; j < TAMANHO; j++) {
        	qtd_comparacoes++;
            if (vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
            
        }
        qtd_comparacoes++;
    	qtd_trocas++;
        if (menor < eleito) {
        	qtd_trocas++;
            vet[i] = vet[pos];
            vet[pos] = eleito;
        }
    }
}

// Função impressão do vetor
void imprimirVetor(int *vet){
	int i;
	for(i=0;i<TAMANHO;i++){
		printf("%i, ",vet[i]);
		if ((i+1)%14 == 0){
			printf("\n");
		}
	}
}

