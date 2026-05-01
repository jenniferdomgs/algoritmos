# include <iostream>
#include <iomanip>

int main() {
    float diametro;
    float pi = 3.14159265359;
    
    std::cin >> diametro;

    float raio = diametro / 2;
    float area = pi * (raio * raio);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Área: " << area << std::endl;
    return 0;
}