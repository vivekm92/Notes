#ifndef __DS_STACK__
#define __DS_STACK__

#include <iostream>
#include <exception>

namespace ds {

    template<typename Data>
    class ArrayStack {
        private:
            class StackEmptyException: public std::exception {
                public:
                    virtual const char* what() const throw() {
                        return "Stack is empty";
                    }
            } stack_empty;

            class StackFullException: public std::exception {
                public:
                    virtual const char* what() const throw() {
                        return "Stack is Full";
                    }
            } stack_full;

            Data* stack;
            int n_elements;
            int capacity;

        public:
            ArrayStack(int capacity) {
                this->capacity = capacity;
                this->n_elements = 0;
                this->stack = new Data[capacity];
            }

            ~ArrayStack() {
                delete [] stack;
            }

            inline bool is_empty() const { return n_elements == 0 ? true : false; }

            inline bool size() { return n_elements; }

            inline void pop() {
                if (n_elements == 0) { throw stack_empty; }
                n_elements--;
            }

            inline Data& top() {
                if (n_elements == 0) { throw stack_empty; }
                return stack[n_elements - 1];
            }

            void push(const Data& value) {
                if (n_elements == capacity) { throw stack_full; }
                stack[n_elements++] = value;
            }

    };
}

#endif
