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

        // add elemento ao fim do vector (como append em py)
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

        // remove o último e retorna
        int pop_back() {
            if (this->size_ == 0) {
                return -1;
            }
            this->size_--;
            return this->data[this->size_]; // último elemento
        }

        // remove o elemento do indice indicado e desloca o resto p/ esquerda
        void remove(int index) {
            if (index < 0 || index >= (int)size_) {
                return;
            }
            for (unsigned int i = index; i < size_ -1; i++) {
                data[i] = data[i + 1];
            }
            size_--;
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
    std::cout << "indice 2: " << v1.get_at(2) << std::endl;
    std::cout << "ultimo elemento: " << v1.pop_back() << std::endl;

    v1.remove(1);

    for(unsigned int i = 0; i < v1.size(); i++) {
        std::cout << v1.get_at(i) << " ";
    }

    std::cout << std::endl;
    
}