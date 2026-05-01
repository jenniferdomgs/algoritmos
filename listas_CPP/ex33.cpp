# include <iostream>
#include <iomanip>

int main() {
    double diametro;
    double pi = 3.14159265359;
    
    std::cin >> diametro;

    double raio = diametro / 2;
    double area = pi * (raio * raio);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Área: " << area << std::endl;
    return 0;
}