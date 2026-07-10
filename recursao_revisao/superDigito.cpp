#include <iostream>

int somaDigitos(int num) {
    if (num >= 0 && num <= 9) {
        return num;
    }
    else {
        return (num % 10) + somaDigitos(num / 10);
    }
}

int superDigito(int n) {
    if (n < 10) {
        return n;
    }
    else {
        return superDigito(somaDigitos(n));
    }
}

int main() {
    int numero;
    std::cin >> numero;

    std::cout << superDigito(numero);

    return 0;
}