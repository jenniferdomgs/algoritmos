/*
Escreva uma função que, dado o valor x, retorne o índice de x no vetor/lista. Caso x não esteja na lista, a função deve retornar −1. Caso haja múltiplas ocorrências de x na lista, o índice da primeira ocorrência deve ser retornado. 
*/

#include <bits/stdc++.h>
using namespace std;

int get_index(int n, vector<int> lista) {
    for(int i = 0; i < lista.size(); i++) {  // tamanho da lista: n
        if(lista[i] == n) { // 1
            return i;
        } 
    }  
    // 1 == n+1 : O(n)
    return -1; // se percorrer toda a lista e n tiver o elemento
}

int main() {
    int n;
    std::cin >> n;
    vector<int> lista = {1, 3, 5, 6, 1, 5};

    std::cout << get_index(n, lista) << std::endl;

    return 0;

}