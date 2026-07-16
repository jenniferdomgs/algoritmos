#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> lista(n);
    int cont = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int soma = lista[i] + lista[j] + lista[k];
                if (soma % 2 != 0) {
                    cont++;
                }
            }
        }
    }

    std::cout << cont << std::endl;
    return 0;
}