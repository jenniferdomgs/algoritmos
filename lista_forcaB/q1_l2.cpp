#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> notas(n);
    vector<double> medias;

    for (int i = 0; i < n; i++)  // executa n vezes
        cin >> notas[i];
    
    // todas as possíveis combinações : C(n,3)
    for (int i = 0; i < n - 2; i++) // executa n vezes
        for (int j = i + 1; j < n - 1; j++) // executa n vezes
            for (int l = j + 1; l < n; l++) // executa n vezes
                medias.push_back((notas[i] + notas[j] + notas[l]) / 3.0);
    
    // ordena em ordem decrescente
    sort(medias.begin(), medias.end(), greater<double>()); // executa log n vezes
    
    
    cout << fixed << setprecision(1) << medias[k - 1] << endl;
    
    return 0;
}

// Desempenho em big O
// n + (n * n * n) + log n
// O(n³ log n)