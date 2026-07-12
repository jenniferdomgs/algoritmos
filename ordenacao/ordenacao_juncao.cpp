#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& lista, int n, int inicio, int meio, int fim) {
    vector<int> esquerda(lista.begin() + inicio, lista.begin() + meio + 1); 
    vector<int> direita(lista.begin() + meio + 1, lista.begin() + fim + 1);

    // vão indicar qual o proximo elemento
    int topoEsq = 0; 
    int topoDir = 0;

    for (int i = inicio; i <= fim; i++) { // O(n)
        if (topoEsq >= (int)esquerda.size()) { // se a esquerda ja zerou = pega o topo da direita
            lista[i] = direita[topoDir];
            topoDir++;

        } else if (topoDir >= (int)direita.size()) { // se a direita ja zerou = pega o topo da esquerda
            lista[i] = esquerda[topoEsq];
            topoEsq++;

        } else if (esquerda[topoEsq] <= direita[topoDir]) { // nenhum zerou e o menor é da esquerda = coloca ele na posição atual da lista
            lista[i] = esquerda[topoEsq];
            topoEsq++;

        } else { // o menor é da direita
            lista[i] = direita[topoDir];
            topoDir++;
        }
    }
}
 
// O(n) x log(n) == O(n log n)
void merge_sort(vector<int>& lista, int n, int inicio=0, int fim=-1) { // dei valores p usuario n ter que passar o inicio e fim
    if (fim == -1) {
        fim = lista.size() - 1; 
    }
    if (inicio < fim) { // se inicio é >= fim é pq a lista tem 1 ou nenhum elemento (já é ordenada)
        int meio = (fim + inicio) / 2; 
        // 2 chamadas recursivas n/2 (cada uma com metade da lista) == log(n)
        merge_sort(lista, n, inicio, meio); 
        merge_sort(lista, n, meio + 1, fim);
        merge(lista, n, inicio, meio, fim); // O(n)
    }
}

int main() {
    int n;
    std::cin >> n;
    
    vector<int> lista(n);

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    
    merge_sort(lista, n);

    for (int i = 0; i < n; i++) {
        cout << lista[i] << std::endl;
    }

    return 0;
}