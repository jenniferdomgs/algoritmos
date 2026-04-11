#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int contador = 0;
    int original = num; 

    for (int i = 1; i <= original; i++) {
        if (original % i == 0) { // se i é divisor do num original, incrementa
            contador++;
        }
    }

    std::cout << contador << std::endl;
    return 0;
}