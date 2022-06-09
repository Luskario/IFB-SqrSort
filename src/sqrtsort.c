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


Dado* sqrByHeap(Dado *V, int tam_total){
	int aux1, aux2 = 0, n, tam_real;
	int tam_part = (int) sqrt(tam_total);			// Definir os tamanhos de cada parte e o numero de partes
	int n_part = (int) floor(tam_total/tam_part);
	if(tam_total % tam_part > 0) {n_part++;}

	for(aux1 = 0; aux1 < n_part; aux1++) {			//Ordena cada uma das partes
		aux2 = tam_part*aux1;
		if (aux2 + tam_part > tam_total){
			tam_real = tam_total - aux2;
		} else { tam_real = tam_part;}

		makeHeap(V, tam_real, aux2);
	}
	
	Dado *Vmaiores = (Dado*) malloc(10000*sizeof(Dado));
	Dado aux3;
	Dado *Vnew = calloc(tam_total, sizeof(int));
	int maior = -999999999;

	for(aux1 = 0; aux1 < n_part; aux1++) {			// seleciona os maiores de cada parte
		aux2 = tam_part*aux1;
		Vmaiores[aux1].valor = V[aux2].valor;
        Vmaiores[aux1].indice = aux2;
        Vmaiores[aux1].percorridos = 0;
	}

	makeHeap(Vmaiores, n_part, 0);
	for(aux1 = 0; aux1 < n_part; aux1++) {
		printf("%d ", Vmaiores[aux1].valor);
	}
	printf("\n");
	for(n=tam_total-1; n>=0; n--) {						//ordena os maiores valores no novo vetor ordenado
		Vnew[n].valor = Vmaiores[0].valor;
		aux3 = Vmaiores[0];
		Vmaiores[0] = Vmaiores[n_part-1];
		Vmaiores[n_part-1] = aux3;

		for(aux1 = 0; aux1 < n_part; aux1++) {
		printf("%d ", Vmaiores[aux1].valor);
	}
		printf("\n");

		heapify_bottom_up(Vmaiores, n_part, n_part-1);
	}


	free(Vmaiores);
	return Vnew;
}

