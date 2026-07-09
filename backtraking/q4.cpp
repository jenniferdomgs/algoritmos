# include <iostream>
using namespace std;

const int M = 20;
const int N = 20;

bool podeDeslocar(int lab[N][M], int linhas, int colunas, int l, int c, int linhaFinal, int colunaFinal) {
    if (l < 0 || c < 0 || l >= linhas || c >= colunas || lab[l][c] == 1) {
        return false;
    }

    if (l == linhaFinal && c == colunaFinal) {
        return true;
    }

    lab[l][c] = 1;

    bool existeCaminho = podeDeslocar(lab, linhas, colunas, linhaFinal, colunaFinal, l+1, c) || // para baixo
                            podeDeslocar(lab, linhas, colunas, linhaFinal, colunaFinal, l-1, c) || // para cima
                            podeDeslocar(lab, linhas, colunas, linhaFinal, colunaFinal, l, c+1) || // para direita
                            podeDeslocar(lab, linhas, colunas, linhaFinal, colunaFinal, l, c-1); // para esquerda
    
    lab[l][c] = 0;

    return existeCaminho;
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

    cout << "Digite 0 ou 1 (0 - livre e 1 - parede): " << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> lab[i][j];
        }
    }

    bool resultado = podeDeslocar(lab, linhas, colunas, linhaFinal, colunaFinal, 0, 0);
    cout << resultado << endl;

    return 0;
}