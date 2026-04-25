// Escreva um algoritmo que retorne a quantidade da maior sublista contígua não decrescente de um array A de n elementos. Uma sublista contígua não decrescente é uma sequência contígua em A onde todo elemento da lista é menor-igual ao seu sucessor.

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

    int cont = 0; // 1

    for(int i = 1; i < n; i++) { // n
        if(numeros[i] >= numeros[i+1]) { // n
            cont += 1; // n
        }
    }

    std::cout << cont << std::endl; // 1

    return 0; // 1
    // equação do tempo de execução: 4n + 6
    // desempenho: O(n) = linear
}