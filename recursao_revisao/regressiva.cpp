#include <iostream>

int contagem_regressiva(int N) {
    std::cout << N << std::endl;
    if (N <= 1) {
        return 1;
    }
    else {
        return contagem_regressiva(N-1);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::cout << contagem_regressiva(N);
    return 0;
}