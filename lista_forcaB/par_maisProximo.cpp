#include <iostream>
#include <cmath>
#include <utility>

int distancia(int x1, int y1, int x2, int y2) {
    int distanciaX = x1 - x2;
    int distanciaY = y1 - y2;
    return sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));

}

std::pair<int, int> par_mais_proximos(int x[], int y[], int n) {
    int menorDistancia = distancia(x[0], y[0], x[1], y[1]);
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distancia(x[i], y[i], x[j], y[j]) < menorDistancia) {
                p1 = i;
                p2 = j;
            }
        }
    }
    return std::make_pair(p1, p2);
}
