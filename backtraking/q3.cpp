#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
const int M = 20;

int caminhoValido(int lab[N][M], int linhas, int colunas, int l, int c) {
    if (l < 0 || c < 0 || l >= linhas || c >= colunas || lab[l][c] == 1) {
        return 999999;
    }

    if (l == linhas - 1 && c == colunas - 1) {
        return 1;
    }

    lab[l][c] = 1; // marcando p/ dizer que visitou

    int menorCaminho = min({ 
                        1 + caminhoValido(lab, linhas, colunas, l+1, c), // para baixo
                        1 + caminhoValido(lab, linhas, colunas, l-1, c), // para cima
                        1 + caminhoValido(lab, linhas, colunas, l, c+1), // para direita
                        1 + caminhoValido(lab, linhas, colunas, l, c-1) // para esquerda
    });
    

    lab[l][c] = 0; 

    return menorCaminho;
}

int main() {
    int linhas, colunas;
    cout << "Numero de linhas: ";
    cin >> linhas;
    cout << "Numero de colunas: ";
    cin >> colunas;

    int lab[N][M];

    cout << "Digite 0 ou 1 (0 - livre e 1 - parede): " << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> lab[i][j];
        }
    }

    int resultado = caminhoValido(lab, linhas, colunas, 0, 0);

    if (resultado >= 999999) {
        cout << -1 << endl;
    } else {
        cout << resultado << endl;
    }

    return 0;
}