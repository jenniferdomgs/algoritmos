// Escreva um algoritmo que leia um array A de n números inteiros e retorne a maior diferença de 2 (dois) elementos consecutivos de A. 

// a) Escreva a equação de tempo de execução do seu algoritmo. 
// b) Determine, usando a notação big-Oh, o desempenho, no pior caso, do seu algoritmo.

# include <iostream>

int main() {
    int n; // 1
    std::cin >> n; // 1
    int* numeros = new int[n]; // 1

    for(int i = 0; i < n; i++) { // n
        std::cin >> numeros[i];
    }

    int maiorDifer = 0; // 1

    for(int i = 1; i < n; i++) { // n
        int difer = numeros[i] - numeros[i-1]; // n 

        if(difer > maiorDifer) { // n
            maiorDifer = difer; // n
        }
    }

    std::cout << maiorDifer << std::endl; // 1

    return 0; // 1

    // equação de tempo de execução : T(n) = 5n + 7
    // desempenho : O(n) = linear
}