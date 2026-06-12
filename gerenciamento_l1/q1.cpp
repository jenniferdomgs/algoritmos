#include <chrono>
#include <iostream>
#include <stdexcept>
class vector
{
private:
    int *data;
    unsigned int size_, capacity_, increase_size_;
    void increase_capacity()
    {
        this->capacity_ += this->increase_size_;
        int *new_data = new int[this->capacity_];
        for (int i = 0; i < this->size_; ++i)
            new_data[i] = data[i];
        delete[] this->data;
        this->data = new_data;
    }

public:
    vector()
    {
        this->size_ = 0;
        this->capacity_ = 1000;
        this->increase_size_ = 1000;
        this->data = new int[1000];
    }
    void push_back(int value)
    {
        if (this->size() == this->capacity())
            increase_capacity();
        this->data[this->size_++] = value;
    }

    int get_at(int index)
    {
        if (index < 0 or index >= size())
            throw std::out_of_range("Index out of range");
        return this->data[index];
    }

    unsigned int size()
    {
        return this->size_;
    }

    unsigned int capacity()
    {
        return this->capacity_;
    }

    ~vector()
    {
        delete[] this->data;
    }
};

int main(int argc, char **argv)
{
    vector v1;
    int n;
    auto inicio = std::chrono::high_resolution_clock::now();

    std::cin >> n;
    while (n != -1)
    {
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

/* PARA 100 DE AUMENTO
Teste 1...
Tempo de execução: 117ms.
Elementos lidos: 100000
Capacidade atual: 100000
Teste 2...
Tempo de execução: 335ms.
Elementos lidos: 200000
Capacidade atual: 200000
Teste 3...
Tempo de execução: 728ms.
Elementos lidos: 300000
Capacidade atual: 300000
Teste 4...
Tempo de execução: 1327ms.
Elementos lidos: 400000
Capacidade atual: 400000
Teste 5...
Tempo de execução: 2046ms.
Elementos lidos: 500000
Capacidade atual: 500000
Teste 6...
Tempo de execução: 2865ms.
Elementos lidos: 600000
Capacidade atual: 600000
Teste 7...
Tempo de execução: 3881ms.
Elementos lidos: 700000
Capacidade atual: 700000
Teste 8...
Tempo de execução: 5064ms.
Elementos lidos: 800000
Capacidade atual: 800000
Teste 9...
Tempo de execução: 6467ms.
Elementos lidos: 900000
Capacidade atual: 900000
Teste 10...
Tempo de execução: 7869ms.
Elementos lidos: 1000000
Capacidade atual: 1000000
*/