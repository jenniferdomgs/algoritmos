#include <iostream>

class vector {
    int data[1000];
    unsigned int size_;
    unsigned int capacity_;  

    public:
        vector() {
            this->size_ = 0;
            this->capacity_ = 1000;  
        }

        // add elemento ao fim do vector (com append em py)
        void push_back(int value) {
            if (this->size() == this->capacity())  
                return;                            
            this->data[this->size_] = value;
            this->size_++;
        }

        // pega o elemento do indice 
        int get_at(int index) {
            if (index < 0 or index >= (int)size())
                return -1;
            return this->data[index];
        }

        unsigned int size() {
            return this->size_;
        }

        unsigned int capacity() {
            return this->capacity_;  
        }
};

int main() {
    vector v1;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        v1.push_back(x);
    }
    for(unsigned int i = 0; i < v1.size(); i++) {
        std::cout << v1.get_at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << v1.get_at(2);
    std::cout << std::endl;
}