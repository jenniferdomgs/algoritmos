# include <iostream>

int soma(int a, int b) {
    int ans = a + b;
    return ans;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int s = soma(a, b);
    std::cout << s << std::endl;
    return 0;
}