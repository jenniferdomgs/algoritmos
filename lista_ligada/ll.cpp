#include <iostream>

class ll_int {
    private:
        struct ll_int_node {
            int value;
            ll_int_node *next;  
        };

        ll_int_node *first, *last;
        unsigned int size_;

    public:
        ll_int() {
            this->first = nullptr;
            this->last = nullptr;
            this->size_ = 0;
        }

        ~ll_int() {
            while (this->first != nullptr) {
                this->pop_front();
            }
        }

        void push_front(int value) {
            ll_int_node *new_node = new ll_int_node;
            new_node->value = value;
            new_node->next = this->first;  
            if (this->last == nullptr) {
                this->last = new_node;
            }
            this->first = new_node;
            this->size_++;
        }

        void push_back(int value) {
            ll_int_node *new_node = new ll_int_node;
            new_node->value = value;
            new_node->next = nullptr;
            if (this->first == nullptr) {
                this->first = new_node;
            } else {
                this->last->next = new_node;
            }
            this->last = new_node;
            this->size_++;
        }

        void pop_front() {
            if (this->first == nullptr) {  
                return;
            }
            ll_int_node *to_remove = this->first;
            this->first = this->first->next;  
            if (this->first == nullptr) {
                this->last = nullptr;
            }
            delete to_remove; 
            this->size_--;
        }

        void pop_back() {
            if (this->last == nullptr) {
                return;
            }
            if (this->first == this->last) {
                delete this->first;
                this->first = nullptr;
                this->last = nullptr;
                return; 
            }
            ll_int_node *current = this->first;
            while (current->next != this->last) {
                current = current->next;
            }
            current->next = nullptr;
            delete this->last;
            this->last = current;
            this->size_--;
        }

        int front() {
            if (this->first != nullptr) {
                return this->first->value;  
            } else {
                return -1;
            }
        }

        int back() {
            if (this->last != nullptr) {
                return this->last->value;
            } else {
                return -1;
            }
        }

        int sum() {
            int ans = 0;
            ll_int_node *current = this->first;
            while (current != nullptr) {
                ans += current->value;
                current = current->next;
            }
            return ans;
        }

        int size() {
            int cont = 0;
            ll_int_node *current = this->first;
            while (current != nullptr) { // O(n) : percorre todos os nós 
                cont += 1;
                current = current->next;
            }
            return cont;
        }

        int get_at(int index) {
            if (index < 0 || index >= size()) { // O(n) : size
                return -1;  
            }
            ll_int_node *current = this->first;  
            for (int i = 0; i < index; i++) { // O(n) : percorre tudo de novo
                current = current->next;
            }
            return current->value; 
            this->size_++;
        }

        void set_at(int i, int value) {
            if (this->first == nullptr) {
                return;
            }
            ll_int_node *current = this->first;
            for (int j = 0; j < i; j++) { // O(n) : percorre até indice
                current = current->next;
                if (current == nullptr) {
                    return;
                }
            }
            current->value = value; 
            this->size_++;
        }

        bool remove(int value) {

        }
    };
