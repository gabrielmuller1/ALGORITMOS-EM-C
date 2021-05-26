#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

// Prototipo de Função
void geraNumero(int *vet, int op);
void imprimirVetor(int *vet);
void quickSort(int *vet, int inicio, int fim);
int partition(int *vet, int inicio, int fim);

// Variáveis Globais
int qtd_comparacoes, qtd_trocas;

int main(void) {
	// Variáveis
	int vet1[TAMANHO];
	float tempo_inicial, tempo_final;
		
	printf("Ordenado:\n");
	geraNumero(vet1,1);
	qtd_comparacoes = 0, qtd_trocas = 0;
	tempo_inicial = clock();
	quickSort(vet1, 0, TAMANHO-1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    
	
	printf("\nInvertido:\n");
	geraNumero(vet1,2);
	qtd_comparacoes = 0, qtd_trocas = 0;
	tempo_inicial = clock();
	quickSort(vet1, 0, TAMANHO-1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
	
	printf("\nAleatorio:\n");
	geraNumero(vet1,3);
	qtd_comparacoes = 0, qtd_trocas = 0;
	tempo_inicial = clock();
	quickSort(vet1, 0, TAMANHO-1);
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

// Função Quick Sort
void quickSort(int *vet, int inicio, int fim) {
    int meio;
    
    if (inicio < fim) {
        meio = partition(vet, inicio, fim);
        quickSort(vet, inicio, meio);
        quickSort(vet, meio + 1, fim);
    }
}

int partition(int *vet, int inicio, int fim) {
    int pivo, i, j;
    pivo = vet[(inicio+fim)/2]; //vet[inicio];
    i=inicio-1;
    j=fim+1;
    while(i<j){
    	do{
    		qtd_comparacoes++;
    		j--;
		}while(vet[j]>pivo);
		
		do{
			qtd_comparacoes++;
			i++;
		}while(vet[i]<pivo);
		
		if(i<j){
			qtd_trocas++;
			int aux;
			aux=vet[i];
			vet[i]=vet[j];
			vet[j]=aux;
		}
	}
	return j;
}
