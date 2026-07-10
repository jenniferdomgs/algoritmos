#include <iostream>

int somaDigitos(int num) {
    if (num >= 0 && num <= 9) {
        return num;
    }
    else {
        return (num % 10) + somaDigitos(num / 10);
    }
}

int main() {
    int numero;
    std::cin >> numero;

    std::cout << somaDigitos(numero);

    return 0;
}