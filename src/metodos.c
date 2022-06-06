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


//---------------------------------------------------------------------------------//


void heapify(int *V, int tam_total, int i){
	int aux, aux2;
	int l, r, maior;
	while(i < tam_total){
		l = 2*i+1;
		r = 2*i+2;
		maior = i;

		if(l <tam_total && V[l]>V[i]){
			maior = l;
		}
		if(r <tam_total && V[r]>V[maior]){
			maior = r;
		}
		if(maior == i){
			break;
		}

		aux2 = V[i];
		V[i] = V[maior];
		V[maior] = aux2;

		i = maior;
	}
}

void heapify_bottom_up(int *V, int tam_total, int i){
	while(i > 0){
		int p = (i-1)/2;
		if(V[p]<V[i]){
			
			i = p;
		}
		else{
			break;
		}
	}
}



void makeHeap(int *V, int tam_total){
	int i;
	
	for(i=(tam_total/2); i>=0; i-- ){
		heapify(V, tam_total, i);
	}
}

