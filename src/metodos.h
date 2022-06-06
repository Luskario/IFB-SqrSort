#ifndef metodos
#define metodos

struct dado
{
    int valor;
    int indice;
    int percorridos;
};

typedef struct dado Dado;

void gerarVetor(int *V, int tamanho);
void bubbleSort(int *V, int ini, int tam, int tam_total);
//------------------------------------------------------------------------//
void makeHeap(int *V, int tam_total);
void heapify(int *V, int tam_total, int i);

#endif
