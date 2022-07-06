#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metodos.h"


Dado* sqrByBubble(Dado *V, int tam_total){
    int aux1, aux2 = 0, n;
	int tam_part = (int) sqrt(tam_total);			// Define o tamanho de cada parte
	int n_part = (int) floor(tam_total/tam_part);	// Define o numero de partes
	if(tam_total % tam_part > 0) {n_part++;}

	//------------------------- Ordena cada uma das partes ---------------------------------------//

	for(aux1 = 0; aux1 < n_part; aux1++) {			
		aux2 = tam_part*aux1;
		bubbleSort(V, aux2, tam_part, tam_total);
	}
	
	Dado *Vmaiores = (Dado*) malloc(10000*sizeof(Dado));
	Dado *Vnew = calloc(tam_total, sizeof(Dado));
	int maior = -999999999;

	//-------------------------- Seleciona os maiores de cada parte --------------------------------//

	for(aux1 = 0; aux1 < n_part; aux1++) { 
		aux2 = tam_part*aux1;
		Vmaiores[aux1].valor = V[aux2].valor;
       		Vmaiores[aux1].indice = aux2;
        	Vmaiores[aux1].percorridos = 0;
	}

	//-------------------------- Ordena os maiores valores no novo vetor ordenado ------------------//
		
	for(n=tam_total-1; n>=0; n--) {						
		for(aux1=0; aux1<n_part; aux1++) {
		    if(Vmaiores[aux1].valor > maior) {
				maior = Vmaiores[aux1].valor;
				aux2 = aux1;
			}
		}
		Vnew[n].valor = maior;
        Vmaiores[aux2].indice++;
        Vmaiores[aux2].percorridos++;

		if(Vmaiores[aux2].percorridos < tam_part && Vmaiores[aux2].indice < tam_total) {
			Vmaiores[aux2].valor = V[Vmaiores[aux2].indice].valor;
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
	int tam_part = (int) sqrt(tam_total);			// Define o tamanho de cada parte 
	int n_part = (int) floor(tam_total/tam_part);	// Define o numero de partes
	if(tam_total % tam_part > 0) {n_part++;}

	//------------------------- Ordena cada uma das partes em Heaps ---------------------------------//

	for(aux1 = 0; aux1 < n_part; aux1++) {			
		aux2 = tam_part*aux1;
		tam_real = tamanhoParte(aux2, tam_total, tam_part);
		makeHeap(V, tam_real, aux2);
	}
	
	Dado *Vmaiores = (Dado*) malloc(10000*sizeof(Dado));
	Dado aux3;
	Dado *Vnew = calloc(tam_total, sizeof(Dado));
	int maior = -999999999;

	//-------------------------- Seleciona os maiores de cada parte ------------------------------------//

	for(aux1 = 0; aux1 < n_part; aux1++) {
		aux2 = tam_part*aux1;
		tam_real = tamanhoParte(aux2, tam_total, tam_part);
		Vmaiores[aux1].valor = removeRoot(V, tam_real, aux2);
        	Vmaiores[aux1].indice = aux2;
        	Vmaiores[aux1].percorridos = tam_real-1;
	}
	
	//------------------------- Ordena os vetor dos maiores em Heap ------------------------------------//
	
	makeHeap(Vmaiores, n_part, 0);

	//------------------------- Seleciona a raiz da Heap dos maiores e o reordena ----------------------//

	for(n=tam_total-1; n>=0; n--) {	
			
		Vnew[n].valor = Vmaiores[0].valor;
		
		if(Vmaiores[0].percorridos > 0){
			Vmaiores[0].valor  = removeRoot(V, Vmaiores[0].percorridos, Vmaiores[0].indice);
			Vmaiores[0].percorridos--;
			heapify(Vmaiores, n_part, 0, 0);
		} else{
			aux3 = Vmaiores[0];
			Vmaiores[0] = Vmaiores[n_part-1];
			Vmaiores[n_part-1] = aux3;
			n_part--;
			heapify(Vmaiores, n_part, 0, 0);
		}
	}

	free(Vmaiores);
	return Vnew;
}

