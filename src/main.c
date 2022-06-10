#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metodos.h"
#include "sqrtsort.h"

int main (void){

    int tam[4] = {10000, 100000, 1000000, 10000000};
    int i, v, vezes=3;
    clock_t timer;
    float temp_m[8] = {0, 0, 0, 0, 0, 0, 0, 0}, temp_aux;
    Dado* vetor = (Dado*)malloc(10000000*sizeof(Dado));
    Dado* aux = (Dado*)malloc(10000000*sizeof(Dado));

    for(v=0; v<vezes; v++){
        for(i=0; i<4; i++){

            gerarVetor(vetor, 10000000);

            //----------------------------------------------------------------//
            timer = clock();
            aux = sqrByHeap(vetor, tam[i]);
            timer = clock() - timer;

            temp_aux = ((float)timer/CLOCKS_PER_SEC);
            temp_m[i] = (temp_m[i] + temp_aux*1000);

            //----------------------------------------------------------------//

            //timer = clock();
            //aux = sqrByHeap(vetor, tam[i]);
            //timer = clock() - timer;

            //temp_aux = ((float)timer/CLOCKS_PER_SEC);
            //temp_m[1] = (temp_m[4+i] + temp_aux*1000)/vezes;
        }  
    }

    
    printf("SqrSort por Bubble:\n");
    for(i=0; i<4; i++){
        printf("tamanho: %d - %.5f ms \n", tam[i], temp_m[i]);
    }
    printf("SqrSort por Heap:\n");
    for(i=0; i<1; i++){
        printf("tamanho: %d - %.5f ms \n", tam[i], temp_m[4+i]);
    }

    free(aux);
    free(vetor);
    

    return 0;
}

