#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metodos.h"
#include "sqrtsort.h"

int main (void){

    int tam[4] = {10000, 100000, 1000000, 10000000};    //tamanho dos casos
    int i, v;
    clock_t timer;
    float temp_m[8] = {0, 0, 0, 0, 0, 0, 0, 0}, temp_aux;
    Dado* vetor = (Dado*)malloc(10000000*sizeof(Dado));
    Dado* vetor_ordenado = (Dado*)malloc(10000000*sizeof(Dado));

    int vezes = 2;                         // numero de testes realizados

    for(v=0; v<vezes; v++){
        for(i=0; i<4; i++){

            gerarVetor(vetor, 10000000);    // gera um vetor aleatorio pra cada caso

            //---------------------------- SqrtSort pelo Heap ----------------------------------------//
            timer = clock();
            vetor_ordenado = sqrByHeap(vetor, tam[i]);
            timer = clock() - timer;

            temp_aux = ((float)timer/CLOCKS_PER_SEC);
            temp_m[i] = temp_m[i] + ((temp_aux*1000)/vezes);

            //------------------------- SqrtSort pelo Bubblesort -------------------------------------//

            timer = clock();
            vetor_ordenado = sqrByBubble(vetor, tam[i]);
            timer = clock() - timer;

            temp_aux = ((float)timer/CLOCKS_PER_SEC);
            temp_m[i+4] = temp_m[4+i] + ((temp_aux*1000)/vezes);
        }  
    }

    //-------------------------------- imprime os tempos de cada caso --------------------------------//

    printf("SqrSort por Heap:\n");
    for(i=0; i<4; i++){
        printf("tamanho: %d - %.5f ms \n", tam[i], temp_m[i]);
    }
    printf("SqrSort por BubbleSort:\n");
    for(i=0; i<4; i++){
        printf("tamanho: %d - %.5f ms \n", tam[i], temp_m[4+i]);
    }

    free(vetor_ordenado);
    free(vetor);
    return 0;
}

