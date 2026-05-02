# include <iostream>

int main(){
    int x, y, l1, h1, l2, h2; // 6
    std::cin >> x >> y >> l1 >> h1 >> l2 >> h2; // 6
    if(l1 + l2 <= x && h1 <= y && h2 <= y){ // 6
        std::cout << "S" << std::endl; // 1
    } else {
        std::cout << "N" << std::endl; // 1
    }
}

// O(1): Constante