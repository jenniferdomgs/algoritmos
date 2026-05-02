//  Escreva um algoritmo que, dado um array A de n números inteiros (1 ≤ n ≤ 105), determine a quantidade de elementos distintos em A. 

# include <iostream>
# include <algorithm>

int main(){
    int n;
    int contDistintos = 1;
    std::cin >> n;
    int A[n];
    
    for(int i = 0; i < n; i++){ // n
        std::cin >> A[i];
    }

    std::sort(A, A + n); // função de ordenação O(n log n)

    for(int i = 1; i < n; i++){ // n
        if(A[i] != A[i-1]) {
            contDistintos += 1;
        }
    }
    
    std::cout << contDistintos << std::endl;

}