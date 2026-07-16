#include <iostream>

bool temSublistaSomaS(int* lista, int n, int soma) {
    if (soma == 0) {
        return true;
    }

    if (soma < 0 || n == 0) {
        return false;
    }

    bool r = temSublistaSomaS(lista, n-1, soma - lista[n-1]); 
    r = r || temSublistaSomaS(lista, n-1, soma);
    return r;
}

int main() {
    int* lista, n, s;
    std::cin >> n >> s;

    lista = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    if(temSublistaSomaS(lista, n, s)) {
        std::cout << "Existe sublista de soma!" << std::endl;
    } else {
        std::cout << "Não existe sublista de soma!" << std::endl;
    }

    delete lista;
    return 0;
}