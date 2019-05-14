#ifndef __DS_ARRAY__
#define __DS_ARRAY__

#include <iostream>
#include <exception>

namespace ds {

    class ArrayIndexOutOfBounds: public std::exception {
        public:
            virtual const char* what() const throw {
                return "Array Index Out of Bounds";
            }
    }index_out_of_bounds;

    template<typename Data>
    class Array {
        private:
            Data* arr;
            int capacity;
            int n_elements;

        public:
            Array(int capacity) {
                this->arr = new Data[capacity];
                this->n_elements = 0;
            }

            ~Array() {
                delete [] arr;
            }

            inline int size() const { return size; }

            inline bool is_empty() { return n_elements == 0 ? true : false;}

            void reverse() {
                for (int i = 0; i <= size/2; i++){
                    int temp = arr[i];
                    arr[i] = arr[n - 1 - i];
                    arr[n - 1 - i] = temp;
                }
            }

            void insert(int idx, Data value) {
                if(idx > n_elements) { throw index_out_of_bounds;}

            }

            void remove(int idx) {
                if(idx >= n_elements) { throw index_out_of_bounds;}


            }

            void push(Data key) {
                if(idx >= capacity) { throw index_out_of_bounds;}

            }

            void pop() {

            }

            void rotate_left(int k) {

            }

            void rotate_right(int k) {
                k =  k %

            }

            Data max(){
                Data max_ = arr[0];
                for(int i = 0; i < size; i++) {
                    if (arr[i] > max_) {
                        max_ = arr[i];
                    }
                }
                return max_;
            }

            Data min(){
                Data min_ = arr[0];
                for(int i = 0; i < size; i++) {
                    if (arr[i] < min_) {
                        min_ = arr[i];
                    }
                }
                return min_;
            }

            inline const Data& operator[] const (int idx) {
                if (idx < 0 || idx >= size) { throw index_out_of_bounds; }
                return arr[idx];
            }
    };

    // template<typename Data>
    // class DynamicArray : public Array {
    //     private:
    //
    //
    // };


}

#endif
