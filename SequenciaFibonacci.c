#include<stdio.h>
#include<locale.h>

int fibonacci(int numero);

int main(void){
	setlocale(LC_ALL, "portuguese");
	int numeros;
	int i = 1;
	
	printf("Informe a quantidade de números da sequência de Fibonacci: ");
	scanf("%i", &numeros);
	
	while(i <= numeros){
		printf("%i ", fibonacci(i));
		i++;
	}
	
	return 0;
}

int fibonacci(int numero){
	
	if(numero == 0){
		return 0;
	}else if(numero == 1){
		return 1;
	}else{
		return fibonacci(numero - 1) + fibonacci(numero - 2);
	}
}
