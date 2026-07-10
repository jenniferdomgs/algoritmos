#include <iostream>

// ordenação por seleção
void selection_sort(int num[], int tam) {
    for (int i = 0; i < tam -1; i++) {
        int i_min = i;
        for (int j = i +1; j < tam; j++) {
            if (num[j] < num[i_min]) {
                i_min = j;
            }
        }
    }
    int aux = num[i];
    num[i] = num[i_min];
    num[i_min] = aux;
}