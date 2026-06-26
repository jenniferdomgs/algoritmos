# include <iostream>

int caminhoValido(int labirinto[8][8], int linha, int coluna, int l, int c) {]
    // se linha ou coluna for menor que 0 ou maior que o tamanho do labirinto ou se a posção for 1 -> retorna 0
    if (l<0 || c<0 || l>=linha || c>=coluna || labirinto[l][c]==1) {
        return 0;
    }
    
    if (l==linha-1 && c==coluna-1) {
        return 1;
    }

    if (caminhoValido(labirinto, linha, coluna, l+1, c)) {
        return 1;
    }

    if (caminhoValido(labirinto, linha, coluna, l, c+1)) {
        return 1;
    }

    return 0;
}

int main() {
    int linha, coluna, labirinto[8][8];
    std::cin >> linha >> coluna;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            std::cin >> labirinto[i][j];
        }
    }
    if (caminhoValido(labirinto, linha, coluna, 0,0)) {
        std::cout << "Existe um caminho válido!" << std::endl;
    } else {
        std::cout << "Não existe caminho válido!" << std::endl;
    }
    return 0;
}