#include <iostream>

int fatorial(int N) {
    if (N == 0 || N == 1) {
        return 1;
    }
    else {
        return N * fatorial(N-1);
    }
}

int main() {
    int N;
    std::cin >> N;

    std::cout << fatorial(N);

    return 0;
}