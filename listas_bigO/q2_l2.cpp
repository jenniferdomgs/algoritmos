//  Dado um array A de n elementos (1 ≤ n ≤ 106), você deve verificar se há elementos repetidos no array. Os elementos são números inteiros Ai (0 ≤ Ai ≤ 105) e não estão ordenados. 
// Descreva um algoritmo para determinar quantas vezes cada valor ocorre no array. 

# include <iostream>

int main(){
    int n;
    int cont = 0;
    std::cin >> n;
    int A[n];

    for(int i = 0; i < n; i++){ // executa n vezes
        std::cin >> A[i];
    }

    int atual = A[0];

    for(int i = 0; i < n; i++){ // executa n vezes
        if(A[i] == atual){
            cont += 1;
        } else {
            std::cout << "valor " << atual << " aparece " << cont << " vez(es)" << std::endl;
            atual = A[i];
            cont = 1;
        }
    }
    std::cout << "valor " << atual << " aparece " << cont << " vez(es)" << std::endl;
}

// n + n = O(n): Linear

