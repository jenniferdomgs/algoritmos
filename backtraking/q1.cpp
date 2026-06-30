# include <iostream>

int caminhoValido(int labirinto[6][6], bool visitado[6][6], int linha, int coluna, int l, int c) {
    // se é fora dos limites, se é parede ou se já visitou
    if (l<0 || c<0 || l>=linha || c>=coluna || labirinto[l][c]==1 || visitado[1][c]) {
        return 0;
    }
    
    if (l==linha-1 && c==coluna-1) {
        return 1;
    }

    visitado[l][c] = true; // já visitou

    if (caminhoValido(labirinto, visitado, linha, coluna, l + 1, c)) { // baixo
        return 1;
    }

    if (caminhoValido(labirinto, visitado, linha, coluna, l - 1, c)) { // cima
        return 1;
    }

    if (caminhoValido(labirinto, visitado, linha, coluna, l, c + 1)) { // direita
        return 1;
    }

    if (caminhoValido(labirinto, visitado, linha, coluna, l, c - 1)) { // esquerda
        return 1;
    }

    return 0;
}

int main() {
    int linha, coluna, labirinto[6][6];
    bool visitado[6][6] = {false}; // tudo sem ser visitado

    std::cin >> linha >> coluna;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            std::cin >> labirinto[i][j];
        }
    }

    if (caminhoValido(labirinto, visitado, linha, coluna, 0, 0)) {
        std::cout << "Existe um caminho válido!" << std::endl;
    } else {
        std::cout << "Não existe caminho válido!" << std::endl;
    }
    return 0;
}