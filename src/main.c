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
    Dado teste[10] = {{43, 0, 0},{12, 0, 0},{78, 0, 0},{32, 0, 0},{43, 0, 0},{11, 0, 0},{14, 0, 0},
                    {1, 0, 0},{15, 0, 0},{98, 0, 0}};
    //int* vetor = (int*)malloc(10000000*sizeof(int));
    //int vetor[1000000];
    //int* aux = (int*)malloc(10000000*sizeof(int));
    Dado* aux;

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
    for(i=0; i<10; i++){
        printf("%d - ", teste[i].valor);
    }
    printf("\n");
    //makeHeap(teste, 4, 6);
    sqrByHeap(teste, 10);
    for(i=0; i<10; i++){
        printf("%d - ", teste[i].valor);
    }

    //printf("%.5f\n", temp_m[0]);
    
    //free(aux);
    //free(vetor);
    

    return 0;
}

