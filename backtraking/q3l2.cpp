#include <iostream>
#include <vector>
using namespace std;

struct resposta {
    bool existe;
    vector<int> sublista;
};

resposta temSublistaSomaS(int* lista, int n, int soma) {
    if (soma == 0) {
        return {true, {}};
    }

    if (soma < 0 || n == 0) {
        return {false, {}};
    }

    resposta r = temSublistaSomaS(lista, n-1, soma - lista[n-1]); 
    if (r.existe) {
        r.sublista.push_back(lista[n-1]);
    } else {
        r = temSublistaSomaS(lista, n-1, soma);
    }
    return r;
}

int main() {
    int* lista, n, s;
    std::cin >> n >> s;

    lista = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    resposta r = temSublistaSomaS(lista, n, s);
    if(r.existe) {
        std::cout << "Existe sublista de soma " << s;
        for (int i = 0; i < n; i++) {
            std::cout << r.sublista[i] << " ";
        }
    } else {
        std::cout << "Não existe sublista de soma " << s << std::endl;
    }

    delete [] lista;
    return 0;
}