#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
const int M = 20;
int infinito = 999999;

int caminhoValido(int lab[N][M], int linhas, int colunas, int l, int c, int linhaFinal, int colunaFinal) {
    if (l < 0 || c < 0 || l >= linhas || c >= colunas || lab[l][c] == -1) {
        return infinito;
    }

    int celula = lab[l][c];

    if (l == linhaFinal && c == colunaFinal) {
        return celula; 
    }

    lab[l][c] = -1; 

    int menorCaminho = min({
        caminhoValido(lab, linhas, colunas, l+1, c, linhaFinal, colunaFinal), // baixo
        caminhoValido(lab, linhas, colunas, l-1, c, linhaFinal, colunaFinal), // cima
        caminhoValido(lab, linhas, colunas, l, c+1, linhaFinal, colunaFinal), // direita
        caminhoValido(lab, linhas, colunas, l, c-1, linhaFinal, colunaFinal)  // esquerda
    });

    lab[l][c] = celula; 

    if (menorCaminho >= infinito) {
        return infinito;
        return celula + menorCaminho;
    }
}

int main() {
    int linhas, colunas, linhaFinal, colunaFinal;
    cout << "Numero de linhas: ";
    cin >> linhas;
    cout << "Numero de colunas: ";
    cin >> colunas;
    cout << "Linha Final: ";
    cin >> linhaFinal;
    cout << "Coluna Final: ";
    cin >> colunaFinal;

    int lab[N][M];
    cout << "Digite o valor da celula (1 a 1000, ou -1): " << endl;
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> lab[i][j];
        }
    }

    int resultado = caminhoValido(lab, linhas, colunas, 0, 0, linhaFinal, colunaFinal);

    if (resultado >= infinito) {
        cout << "Nenhum caminho válido encontrado!" << endl;
    }
        
    else {
        cout << resultado << endl;
    }
    
    return 0;
}