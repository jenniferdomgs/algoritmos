# include <chrono>
# include <iostream>

bool primo(long long n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    if(n % 2 == 0) {
        return false;
    }

    bool p = true;
    int d = 3;

    while(p <= n / 2 && d <= n / 2) {
        if(n % d == 0) {
            p = false;
        }

        d = d + 2;
    }

    return p;
}

int main() {
    long long n;
    std::cin >> n;

    // início do cronômetro
    auto beg = std::chrono::high_resolution_clock::now();
    bool p = primo(n);

    // fim do cronômetro
    auto end = std::chrono::high_resolution_clock::now();

    if(p) {
        std::cout << n << " is prime" << std::endl;
    } else {
        std::cout << n << " is not prime" << std::endl;
    }

    auto dur = end - beg; // duração do cronômetro
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
    std::cerr << n << " Processing time: " << duration << " microsecond(s)" << std::endl;
    return 0;

}