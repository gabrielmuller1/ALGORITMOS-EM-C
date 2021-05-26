#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

// Prototipo de Função
void geraNumero(int *vet, int op);
void imprimirVetor(int *vet);
void mergeSort(int *vet, int inicio, int fim);
void intercala(int *vet, int inicio, int fim, int meio);

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
	mergeSort(vet1, 0, TAMANHO-1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    
	
	printf("\nInvertido:\n");
	
	geraNumero(vet1,2);
	qtd_comparacoes = 0, qtd_trocas = 0;
	tempo_inicial = clock();
	mergeSort(vet1, 0, TAMANHO-1);
	tempo_final = clock() - tempo_inicial;
	
	printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
	
	printf("\nAleatorio:\n");
	
	geraNumero(vet1,3);
	qtd_comparacoes = 0, qtd_trocas = 0;
	tempo_inicial = clock();
	mergeSort(vet1, 0, TAMANHO-1);
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

// Função Merge Sort
void mergeSort(int *vet, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        intercala(vet, inicio, fim, meio);
    }
}

void intercala(int *vet, int inicio, int fim, int meio) {
    int poslivre = inicio, iniciovetor1 = inicio, iniciovetor2 = meio + 1, i;
    int aux[TAMANHO];
    while (iniciovetor1 <= meio && iniciovetor2 <= fim) {
    	qtd_comparacoes++;
        if (vet[iniciovetor1] <= vet[iniciovetor2]) {
        	qtd_trocas++;
            aux[poslivre] = vet[iniciovetor1];
            iniciovetor1++;
        } else {
        	qtd_trocas++;
            aux[poslivre] = vet[iniciovetor2];
            iniciovetor2++;
        }
        poslivre++;
    }
    for (i = iniciovetor1; i <= meio; i++) {
        aux[poslivre] = vet[i];
        qtd_trocas++;
        poslivre++;
    }
    for (i = iniciovetor2; i <= fim; i++) {
        aux[poslivre] = vet[i];
        qtd_trocas++;
        poslivre++;
    }
    for (i = inicio; i <= fim; i++) {
    	
        vet[i] = aux[i];
    }
}

