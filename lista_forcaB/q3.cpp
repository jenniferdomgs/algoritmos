//  Sub-lista contígua de soma máxima

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int A[n];
    
    for(int i = 0; i < n; i++) { // n vezes
        std::cin >> A[i];
    }

    int soma_max = A[0];
    int inicio = 0, fim = 0;

    for(int i = 0; i < n; i++) { // n vezes
        int soma_atual = 0;

        for(int j = i; j < n; j++) { // n vezes
            soma_atual += A[j];

            if(soma_atual > soma_max) {
                soma_max = soma_atual;
                inicio = i;
                fim = j;
            }
        }
    }

    std::cout << "soma máxima: " << soma_max << std::endl;
    std::cout << "Indices: " << inicio << " a " << fim << std::endl;

    return 0;
    
}

// T(n) = n + n X n = n + n² = O(n²)