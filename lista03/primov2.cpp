# include <chrono>
# include <iostream>

bool primo(long long n) {
    int divs = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            divs++;
        }
    }
    if(divs == 1) {
        return true;
    } else {
        return false;
    }
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