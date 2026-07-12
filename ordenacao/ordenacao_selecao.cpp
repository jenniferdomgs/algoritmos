#include <iostream>
#include <vector>

using namespace std;

// para pegar o menor precisa percorrer todos os elementos: O(n)
int busca_menor(vector<int>& lista, int n) { // lista desordenada e tamanho dela
    int menor = lista[0];
    int index_menor = 0;
    for (int i = 0; i < n; i++) { // n
        if (lista[i] < menor) {
            menor = lista[i];
            index_menor = i;
        }
    }
    return index_menor;
}

// pegar o menor n vezes é O(n) x O(n) = O(n²)
void ordenacao_selecao(vector<int>& lista, int n, vector<int>& new_lista) { // lista desordenada, tamanho dela e novalista
    int restante = n;
    for (int i = 0; i < n; i++) { // n
        int menor = busca_menor(lista, restante); // n
        new_lista[i] = lista[menor];
        lista[menor] = lista[restante - 1];
        restante--;
    }
}

int main() {
    int n;
    std::cin >> n;
    
    vector<int> lista(n);
    vector<int> resultado(n);

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    
    ordenacao_selecao(lista, n, resultado);

    for (int i = 0; i < n; i++) {
        cout << resultado[i] << std::endl;
    }

    return 0;
}