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
void makeHeap(Dado *V, int tam_total, int ini);
void heapify(Dado *V, int tam_total, int i, int ini);
void heapify_bottom_up(Dado *V, int tam_total, int i);

#endif
