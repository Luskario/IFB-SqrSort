#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


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

void heapify(int *V, int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
	int aux;
	int largest = i;

    if (l < n && V[l] > V[largest]){
		largest = l;
	}
        
    if (r < n && V[r] > V[largest]){
		largest = r;
	}

    if (largest != i) {
		aux = V[i];
		V[i] = V[largest];
		V[largest] = V[i];
        heapify(V, n, largest);
    }
}

void makeHeap(int *V, int ini, int tam, int tam_total){

}