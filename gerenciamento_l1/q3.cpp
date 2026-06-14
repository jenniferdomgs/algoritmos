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

        // pega o indice do elemento
        int get_index(int value) {
            for(unsigned i = 0; i < size_; i++) {
                if(this->data[i] == value) {
                    return i;
                }
            }
            return -1; // se não tem o elemento
        }

        // remove o último e retorna
        int pop_back() {
            if (this->size_ == 0) {
                return -1;
            }
            this->size_--;
            return this->data[this->size_]; // último elemento
        }

        // remove o elemento pelo indice, desloca os demais para esquerda e atualiza o tamanho 
        bool remove_at(int index) {
            if (index < 0 || index >= (int)size_) {
                return false;
            }
            for (unsigned int i = index; i < size_ -1; i++) { // O(n)
                data[i] = data[i + 1];
            }
            size_--;
            return true;
        }

        // remove o elemento pelo valor, desloca os demais para esquerda e atualiza o tamanho
        bool remove(int value) {
            for(unsigned int i = 0; i < size_; i++) { // O(n)
                if (this->data[i] == value) {
                    data[i] = data[i + 1];
                    size_--;
                    return true;
                }
            } 
            return false;
        }

        unsigned int size() {
            return this->size_;
        }

        unsigned int capacity() {
            return this->capacity_;  
        }
};

