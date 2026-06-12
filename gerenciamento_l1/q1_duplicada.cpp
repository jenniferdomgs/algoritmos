// O programa a seguir lê uma sequencia indefinida de números inteiros, armazenando-os em um vector dinâmico. A
// leitura termina quando o número −1 é lido.

# include <iostream>
# include <chrono>
# include <stdexcept>


class vector {
    private:
        int *data;
        unsigned int size_, capacity_, increase_size_;
        void increase_capacity() {
            // se a capacidade é 0, soma a capacidade com ela mesma 
            if (this->increase_size_ == 0)
                this->capacity_ += this->capacity_;
            else     // se não, incrementa o tamanho a capacidade
                this->capacity_ += this->capacity_;
            int *new_data = new int[this->capacity_ * 2];
            for (unsigned int i = 0; i < this->size_; i++) {
                new_data[i] = data[i];
            }
            delete[] this->data;
            this->data = new_data;
        }

    public:
        vector() {
            this->size_ = 0;
            this->capacity_= 100;
            this->increase_size_ = 0;
            this->data = new int[100];
        }

        void push_back(int value) {
            if (this->size() == this->capacity_) {
                increase_capacity();
            }
            this->data[this->size_++] = value;
        }

        int get_at(int index) {
            if (index < 0 || index >= static_cast<int>(this->size_)) {
                throw std::out_of_range("Index out of range");
            }
            return this->data[index];
        }

        unsigned int size() {
            return this->size_;
        }

        unsigned int capacity() {
            return this->capacity_;
        }

        ~vector() {
            delete[] this->data;
        }
};

int main(int argc, char **argv) {
    vector v1;
    int n;
    auto inicio = std::chrono::high_resolution_clock::now();
    std::cin >> n;
    while (n != -1) {
        v1.push_back(n);
        std::cin >> n;
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count();
    std::cerr << "Tempo de execução: " << duracao << "ms." << std::endl;
    std::cout << "Elementos lidos: " << v1.size() << std::endl;
    std::cout << "Capacidade atual: " << v1.capacity() << std::endl;
    return 0;
}


/*
teste 1:
Tempo de execução: 3768ms.
Elementos lidos: 100000
Capacidade atual: 102400

teste 2:
Tempo de execução: 3554ms.
Elementos lidos: 200000
Capacidade atual: 204800

teste 3:
Tempo de execução: 3695ms.
Elementos lidos: 300000
Capacidade atual: 409600

teste 4:
Tempo de execução: 3658ms.
Elementos lidos: 400000
Capacidade atual: 409600

teste 5:
Tempo de execução: 3837ms.
Elementos lidos: 500000
Capacidade atual: 819200

teste 6:
Tempo de execução: 3610ms.
Elementos lidos: 600000
Capacidade atual: 819200

teste 7:
Tempo de execução: 4086ms.
Elementos lidos: 700000
Capacidade atual: 819200

teste 8:
Tempo de execução: 4465ms.
Elementos lidos: 800000
Capacidade atual: 819200

teste 9:
Tempo de execução: 4373ms.
Elementos lidos: 900000
Capacidade atual: 1638400

teste 10:
Tempo de execução: 4975ms.
Elementos lidos: 1000000
Capacidade atual: 1638400

*/