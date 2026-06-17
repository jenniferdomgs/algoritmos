# include <iostream>

class ll_int {
    private:
        struct ll_int_node {
            int value;
            struct ll_int *next;
        };

    public:
        ll_int() {
            this->first = nullptr;
            this->last = nullptr;
        }

        void push_front(int value) {
            ll_int_node *new_node = new ll_int_node;
            new_node->value = value;
            new_node->next = nullptr;
            if (this->first == nullptr) {
                this->first = new_node;
            } else {
                this->last->next = new_node;
            }
            this->last = new_node;
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
        }

        void pop_front() {
            if (this->firt == nullptr) {
                return;
            }
            ll_int_node *to_remove = this->first;
            if (this->last == this->first) {
                this->last = nullptr;
                this->first = nullptr;
            }
        }

        void pop_back() {
            if (this->last == nullptr) {
                return;
            }
            if (this->first == this->last) {
                delete this->first;
                this->first = nullptr;
                this->last = nullptr;
            }
            ll_int_node *current = this->first;
            while (current->next != this->last) {
                current = current->next;
            }
            current->next = nullptr;
            delete this->last;
            this->last = current;
            }
        
        int front() {
            if (this->first != nullptr) {
                return this->last->value;
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
            while (current != 0) {
                ans += current->value;
                current = current->next;
            }
            return ans;
        }
        
        int size() {
            
        }
};

int main() {

}