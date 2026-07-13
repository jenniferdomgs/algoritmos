#include <iostream>
#include <vector>

using namespace std;

// começa a percorrer pelo segundo elemento -> compara o atual com os anteriores
// se é menor que algum, move ele para antes do maior
// faz isso da direita p esquerda até o anterior (j) ser 0

// O(n) x O(n) = O(n²)
// no caso do vetor ja ta ordenado não entra no while, então fica O(n)
void ordenacao_insercao(vector<int>& lista, int n) {
    for (int i = 1; i < n; i++) { // n
        int chave = lista[i];
        int j = i-1;
        
        while (j >= 0 && lista[j] > chave) { // i (vai de 1 até n-1) == O(n-1)
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
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
    
    ordenacao_insercao(lista, n);

    for (int i = 0; i < n; i++) {
        cout << lista[i] << std::endl;
    }

    return 0;
}