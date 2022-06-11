#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "metodos.h"


void gerarVetor(Dado *V, int tamanho){
	srand(time(NULL));
	int i;
	for(i=0; i<tamanho; i++){
		V[i].valor = rand() % 100000;
		V[i].indice = 0;
		V[i].percorridos = 0;
	}
}

void bubbleSort(Dado *V, int ini, int tam, int tam_total){
    int i, cont; 
	Dado aux;
		
	do {
		cont = 0;
		//System.out.println(ini);
		for(i=ini; (i<ini+tam-1) && (i<tam_total-1) ; i++) {	//Percorre o vetor
			
			if(V[i].valor < V[i+1].valor) {		//Troca
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				cont = i;			//Verifica se o vetor foi percorrido
			}				
		}
		
	} while(cont != 0);
}

//---------------------------------------------------------------------------------//

void heapify(Dado *V, int tam_total, int i, int ini){
	int aux;
	Dado aux2;
	int l, r, maior;
	while(i < tam_total){
		l = 2*i+1+ini;
		r = 2*i+2+ini;
		maior = i+ini;

		if(l <tam_total+ini && V[l].valor>V[i+ini].valor){
			maior = l;
		}
		if(r <tam_total+ini && V[r].valor>V[maior].valor){
			maior = r;
		}
		if(maior == i+ini){
			break;
		}

		aux2 = V[i+ini];
		V[i+ini] = V[maior];
		V[maior] = aux2;

		i = maior-ini;
	}
}

int removeRoot(Dado *V, int tam_total, int i){

	int aux = V[i].valor;
	int valor = V[i+tam_total- 1].valor;
    V[i].valor = valor;

    tam_total = tam_total - 1;

    heapify(V, tam_total, 0, i);
	return aux;
}

void makeHeap(Dado *V, int tam_total, int ini){
	int i;
	
	for(i=(tam_total/2); i>=0; i-- ){
		heapify(V, tam_total, i, ini);
	}
}

//---------------------------------------------------------------------------------//

int tamanhoParte(int i, int tam_total, int tam_part){
	int tam_real;
	if (i + tam_part > tam_total){
		tam_real = tam_total - i;
	} else { 
		tam_real = tam_part;
	}
	return tam_real;
}