# include <iostream>
#include <vector>
using namespace std;

// NAO DESCRESCENTE == valores só mantêm ou crescem
// DECRESCENTE == valores diminuem continuamente
bool nao_descrescente(vector<int>& lista, int n) {
    for (int i = 1; i < n; i++) {
        if (lista[i-1] > lista[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    vector<int> lista(n);

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    bool resultado = nao_descrescente(lista, n);

    if (resultado == true) {
        cout << "ordem não descrescente" << std::endl;
    } else {
        cout << "ordem descrescente" << std::endl;
    }

    return 0;
}



/*
TESTES
- Ordem não descrescente:
    1 1 3 4 4 5 6 7 7
    1 2 2 3 5 5
    1 2 2 3 3 4
    42
    7 7 7 7
    -10 -5 0 2 5


- Ordem decrescente:
    4 3 2 1
    10 8 7 6 5 2
    9 7 5 1
    1 5 2 8 3
*/