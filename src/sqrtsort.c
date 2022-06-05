#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metodos.h"


int* sqrByBubble(int *V, int tam_total){
    int aux1, aux2 = 0, n;
	int tam_part = (int) sqrt(tam_total);			// Definir os tamanhos de cada parte e o numero de partes
	int n_part = (int) floor(tam_total/tam_part);
	if(tam_total % tam_part > 0) {n_part++;}

	for(aux1 = 0; aux1 < n_part; aux1++) {			//Ordena cada uma das partes
		aux2 = tam_part*aux1;
		bubbleSort(V, aux2, tam_part, tam_total);
	}
	
	Dado *Vmaiores = (Dado*) malloc(10000*sizeof(Dado));
	int *Vnew = calloc(tam_total, sizeof(int));
	int maior = -999999999;

	for(aux1 = 0; aux1 < n_part; aux1++) {			// seleciona os maiores de cada parte
		aux2 = tam_part*aux1;
		Vmaiores[aux1].valor = V[aux2];
        Vmaiores[aux1].indice = aux2;
        Vmaiores[aux1].percorridos = 0;
	}
		
	for(n=tam_total-1; n>=0; n--) {						//ordena os maiores valores no novo vetor ordenado
		for(aux1=0; aux1<n_part; aux1++) {
		    if(Vmaiores[aux1].valor > maior) {
				maior = Vmaiores[aux1].valor;
				aux2 = aux1;
			}
		}
		Vnew[n] = maior;
        Vmaiores[aux2].indice++;
        Vmaiores[aux2].percorridos++;

		if(Vmaiores[aux2].percorridos < tam_part && Vmaiores[aux2].indice < tam_total) {
			Vmaiores[aux2].valor = V[Vmaiores[aux2].indice];
		} else {
			Vmaiores[aux2].valor = -999999999;
		}
	    maior = -999999999;
	}
	free(Vmaiores);
	return Vnew;
}


int* sqrByHeap(int *V, int tam_total){
	int aux1, aux2 = 0, n;
	int tam_part = (int) sqrt(tam_total);			// Definir os tamanhos de cada parte e o numero de partes
	int n_part = (int) floor(tam_total/tam_part);
	if(tam_total % tam_part > 0) {n_part++;}

	for(aux1 = 0; aux1 < n_part; aux1++) {			//Ordena cada uma das partes
		aux2 = tam_part*aux1;
		makeHeap(V, aux2, tam_part, tam_total);
	}
    //---------------------------------------------------------------------------------------------------//
	Dado Vmaiores[tam_part];
	int *Vnew = calloc(tam_total, sizeof(int));
	int maior = -999999999;

	for(aux1 = 0; aux1 < n_part; aux1++) {			// seleciona os maiores de cada parte
		aux2 = tam_part*aux1;
		Vmaiores[aux1].valor = V[aux2];
        Vmaiores[aux1].indice = aux2;
        Vmaiores[aux1].percorridos = 0;
		//printf("%d -- %d - %d - %d \n", aux1, Vmaiores[aux1].indice, Vmaiores[aux1].valor, Vmaiores[aux1].percorridos);
	}
		
	for(n=tam_total-1; n>=0; n--) {						//ordena os maiores valores no novo vetor ordenado
	
	}
	return Vnew;
}

