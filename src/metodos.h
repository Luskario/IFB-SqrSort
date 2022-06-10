#ifndef metodos
#define metodos

struct dado
{
    int valor;
    int indice;
    int percorridos;
};

typedef struct dado Dado;

void gerarVetor(Dado *V, int tamanho);
void bubbleSort(Dado *V, int ini, int tam, int tam_total);
//------------------------------------------------------------------------//
void makeHeap(Dado *V, int tam_total, int ini);
void heapify(Dado *V, int tam_total, int i, int ini);
//------------------------------------------------------------------------//

int removeRoot(Dado *V, int tam_total, int i);

//------------------------------------------------------------------------//
int tamanhoParte(int i, int tam_total, int tam_part);
#endif
