// Um novo vírus foi descoberto e sua taxa de transmissão é de 1.0 (100%), o que indica que a quantidade de infectados dobra a cada dia. Uma vez que o vírus se instala no seu corpo ele se mantém vivo e não causa nenhum mal a sua saúde, isto quer dizer que todos na cidade serão infectados. Faça um algoritmo que, dada a população de uma cidade, informe em quantos dias todos da cidade estarão infectados depois do primeiro cidadão ser infectado. Determine o desempenho do seu algoritmo usando a notação O (big-Oh). 


# include <iostream>

int main() {
    long long tamPopulacao; // 1
    int dias = 0; // 1 
    long long infectados = 1; // 1

    std::cin >> tamPopulacao; // 1

    while(infectados < tamPopulacao){ // x vezes 
        infectados *= 2; // x -> log2(n): a cada iteração infectados é multiplicada por 2, então x = log2(n)
        dias++; // x
    }
    
    std::cout << dias << std::endl; // 1
    return 0; // 1
}

// equação: 6 + 3*log2(n)