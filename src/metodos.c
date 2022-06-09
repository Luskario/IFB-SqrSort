#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "metodos.h"


void gerarVetor(int *V, int tamanho){
	srand(time(NULL));
	int i;
	for(i=0; i<tamanho; i++){
		V[i] = rand() % 100000;
	}
}

void bubbleSort(int *V, int ini, int tam, int tam_total){
    int i, cont, aux;
		
	do {
		cont = 0;
		//System.out.println(ini);
		for(i=ini; (i<ini+tam-1) && (i<tam_total-1) ; i++) {	//Percorre o vetor
			
			if(V[i] < V[i+1]) {		//Troca
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

void heapify_bottom_up(Dado *V, int tam_total, int i){
	Dado aux;

	while(i > 0){
		int p = (i-1)/2;
		if(V[p].valor<V[i].valor){
			aux = V[i];
			V[i] = V[p];
			V[p] = aux;
			i = p;
		}
		else{
			break;
		}
	}
}

void makeHeap(Dado *V, int tam_total, int ini){
	int i;
	
	for(i=(tam_total/2); i>=0; i-- ){
		heapify(V, tam_total, i, ini);
	}
}

