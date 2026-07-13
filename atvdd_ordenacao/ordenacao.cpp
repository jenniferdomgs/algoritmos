#include "ordenacao.hpp"
#include <algorithm>
#include <vector>
using namespace std;

bool ordenado(int a[],  unsigned int t){
    for (unsigned int i = 1; i < t; i++) {
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
    for (unsigned int i = 1; i < t; i++) { 
        int chave = a[i];
        int j = i-1;

        while (j >= 0 && a[j] > chave) { 
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = chave;
    }
}

void merge(int a[], unsigned int inicio, unsigned int meio, unsigned int fim) {
    unsigned int tamEsq = meio - inicio + 1;
    unsigned int tamDir = fim - meio;

    int* esquerda = new int[tamEsq];
    int* direita  = new int[tamDir];

    for (unsigned int i = 0; i < tamEsq; i++) {
        esquerda[i] = a[inicio + i];
    }
    for (unsigned int i = 0; i < tamDir; i++) {
        direita[i]  = a[meio + 1 + i];
    }
    
    unsigned int topoEsq = 0;
    unsigned int topoDir = 0;

    for (unsigned int i = inicio; i <= fim; i++) {
        if (topoEsq >= tamEsq) {
            a[i] = direita[topoDir];
            topoDir++;

        } else if (topoDir >= tamDir) {
            a[i] = esquerda[topoEsq];
            topoEsq++;

        } else if (esquerda[topoEsq] <= direita[topoDir]) {
            a[i] = esquerda[topoEsq];
            topoEsq++;

        } else {
            a[i] = direita[topoDir];
            topoDir++;
        }
    }

    delete[] esquerda;
    delete[] direita;
}

// o mergesort original (ordena de forma recursiva)
void merge_sortR(int a[], unsigned int inicio, unsigned int fim) {
    if (inicio < fim) {
        unsigned int meio = (fim + inicio) / 2;
        merge_sortR(a, inicio, meio);
        merge_sortR(a, meio + 1, fim);
        merge(a, inicio, meio, fim);
    }
}

// auxiliar p ficar na assinatura exigida
void merge_sort(int a[], unsigned int t) {
    if (t == 0) return; 
    merge_sortR(a, 0, t - 1);
}