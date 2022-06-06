#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metodos.h"
#include "sqrtsort.h"

int main (void){

    int tam[4] = {10000, 100000, 1000000, 10000000};
    int i, c, vezes=1;
    //clock_t timer;
    //float temp_m[8] = {0, 0, 0, 0, 0, 0, 0, 0}, temp_aux;
    int teste[10] = {76, 18, 1, 43, 42, 2, 5, 7, 9, 10};
    //int* vetor = (int*)malloc(10000000*sizeof(int));
    //int vetor[1000000];
    //int* aux = (int*)malloc(10000000*sizeof(int));

    //for(i=0; i<1; i++){

        //gerarVetor(vetor, 1000000);

        //----------------------------------------------------------------//
        //timer = clock();
        //aux = sqrByBubble(vetor, 1000000);
        //timer = clock() - timer;

        //temp_aux = ((float)timer/CLOCKS_PER_SEC);
        //temp_m[0] = (temp_m[0] + temp_m[i]*1000)/vezes;

        //----------------------------------------------------------------//

    //}
    
    makeHeap(teste, 10);
    for(i=0; i<10; i++){
        printf("%d - ", teste[i]);
    }

    //printf("%.5f\n", temp_m[0]);
    
    //free(aux);
    //free(vetor);
    

    return 0;
}

