# include <iostream>

class ll_int {
    private:
        struct node {
            int value;
            node *next, *prev;
        };

        node *head, *tail;
        unsigned int size_;

    public:
        ll_int() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }
        
        ~ll_int() {
            node *current = this->head;
            while (current != nullptr) {
                node *next = current->next;
                delete current;
                current = next;
            }
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }

        bool find(int value) {
            node *current = this->head;
            while (current != nullptr) {
                if (current->value == value) { // se a lista for ordenada
                    return true;
                }
                if (current->value > value) {
                    return false;
                }
                current = current->next;
            }
            return false;
        }

        int count(int value) {
            int cont = 0;
            node *current = this->head;
            while (current != nullptr) {
                if (current->value == value) {
                    cont++;
                }
                if (current->value > value) {
                    break;
                }
                current = current->next;
            }
            return cont;
        }
};