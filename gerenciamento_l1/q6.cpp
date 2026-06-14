// Implemente um método que receba uma outra lista como parâmetro e determine a quantidade de números que são comuns às duas listas. O método deve retornar a quantidade de números comuns.

#include <iostream>

class vector {
    private:
        int *data;
        unsigned int size_, capacity_;

    public:
        // construtor
        vector() {
            this->size_ = 0;
            this->capacity_ = 1000;  
            this->data = new int[this->capacity_];
        }

        // destrutor
        ~vector() {
            delete[] this->data;
        }

        // add elemento ao fim do vector (como append em py)
        void push_back(int value) {
            if (this->size() == this->capacity())  
                return;                            
            this->data[this->size_] = value;
            this->size_++;
        }

        // add elemento ao inicio do vector
        void push_front(int value) {
            if (this->size() == this->capacity()) {
                return;
            }
            for(unsigned int i = size_; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = value;
            size_++;
        }

        // inserir elemento no indice
        bool insert_at(int index, int value) { // se o indice é negativo ou n existe na lista ou tamanho já é igual a capacidade -> retorna falso
            if (index < 0 || index > (int)size_ || size_ == capacity_) {
                return false;
            } 
            for (unsigned int i = size_; i > (unsigned int)index; i--) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size_++;
            return true;
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

        // remove o último e retorna (-1 se a lista for vazia)
        int pop_back() {
            if (this->size_ == 0) {
                return -1; 
            }
            this->size_--;
            return this->data[this->size_]; // último elemento
        }

        // remove o primeiro e retorna (-1 se a lista for vazia)
        int pop_front() {
            if (this->size_ == 0) {
                return -1;
            }
            int value = data[0];
            remove_at(0);
            return value;
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

        // retorna o primeiro elemento (-1 se a lista for vazia)
        int return_first() {
            if (this->size_ == 0) {
                return -1;
            }
            return data[0];
        }

        // retorna o último elemento (-1 se a lista for vazia)
        int return_last() {
            if (this->size_ == 0) {
                return -1;
            }
            return data[size_ - 1];
        }

        // conta as ocorrências de um elemento na lista (0 se a lista for vazia ou não tiver)
        int count(int value) {
            int cont = 0;
            if (this->size_ == 0) {
                return 0;
            }
            for (unsigned int i = 0; i < size_; i++) {
                if (data[i] == value) {
                    cont++;
                }
            }
            return cont;
        }

        // zerar tamanho da lista
        void clear() {
            this->size_ = 0;
        }

        // contar quantos elementos comuns 2 vetores têm
        unsigned int contar_comuns(const vector &other) {
            unsigned int cont = 0;
            for (int i = 0; i < this->size_; i++) {
                int atual = this->data[i];
                for (int j = 0; i < (int)other.size_; j++) {
                    if (other.data[j] == atual) {
                        cont++;
                        break;
                    }
                }
            }
            return cont;
        }

        void push_back_vector(const vector &other) {
            if (this->size_ == this->capacity_) {
                return;
            }
            

        }

};

