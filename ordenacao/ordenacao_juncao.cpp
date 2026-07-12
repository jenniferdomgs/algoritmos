#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& lista, int n, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        int meio = (fim + inicio) / 2;
        merge_sort(lista, n, inicio, meio);
        merge_sort(lista, n, meio + 1, fim);
        merge()
    }
}

void merge(vector<int>& lista, int n, int inicio, int meio, int fim) {
    // vector<int> esquerda(lista.begin() + inicio, lista.begin() + meio + 1);
    // vector<int> direita(lista.begin() + meio + 1, lista.begin() + fim + 1);
    // // indices p percorrer a lista original e as sublistas
    // int iEsquerda = 0; 
    // int iDireita = 0;
    // int iLista = inicio;

}