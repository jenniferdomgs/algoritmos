// Um determinado material perde metade de sua massa a cada período fixo de tempo, dependendo das condições ambientais. Conhecendo o período de tempo t (inteiro, em segundos) e a massa inicial mi (número real), escreva um algoritmo que determine em quanto tempo a massa do material se reduz a 1g ou menos. 

# include <iostream>

int main(){
    int tempo; // 1
    float massa; // 1
    int tempoTotal =  0; // 1

    std::cin >> tempo; // 1
    std::cin >> massa; // 1

    while(massa > 1){ // x vezes
        massa /= 2; // x -> log2(n): a cada iteração massa é dividida por 2, então x = log2(n)
        tempoTotal += tempo; // x
    }

    std::cout << tempoTotal << std::endl; // 1

    return 0; // 1
}

// equação: 7 + 3(log2(n))