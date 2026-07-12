#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){
    for (int i = 1; i < t; i++) {
        if (a[i-1] > a[i]) {
            return false;
        }
    }
    return true;
}

void selecao(int a[], unsigned int t) {
    for (unsigned int i = 0; i < t; i++) {
        unsigned int index_menor = i; 
        for (unsigned int j = i + 1; j < t; j++) {
            if (a[j] < a[index_menor]) {
                index_menor = j;
            }
        }
        swap(a[i], a[index_menor]);
    }
}

void insercao(int a[], unsigned int t){
    for (int i = 1; i < n; i++) { 
        int chave = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > chave) { 
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = chave;
    }
}

/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t);
