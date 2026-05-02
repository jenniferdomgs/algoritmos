#include <iostream>

bool temParSoma(int A[], int n, int soma) {
    for (int i = 0; i < n; i++) { // executa n vezes
        for (int j = i + 1; j < n; j++) { // executa n vezes
            if (A[i] + A[j] == soma) {
                return true;
            }
        }
    }
    return false;
} // n²: O(n²): Quadrática

int main() {
    int n, soma;
    std::cin >> n >> soma;

    int A[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    if (temParSoma(A, n, soma)) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}


// TESTES:
// n = 6, soma = 2, entradas: 1, 0, 0, 2, 0, 1
// n = 9, soma = 15, entradas: 1, 5, 7, 9, 7, 3, 4, 8, 2
// n = 12, soma = 21, entradas: 7, 8, 5, 2, 1, 6, 4, 3, 7, 8, 9, 7
// n = 24, soma = 3, entradas: 7, 8, 5, 2, 1, 19, 5, 0, 0, 2, 0, 16, 4, 3, 7, 8, 9, 7, 97, 3, 4, 8, 0, 3