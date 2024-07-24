#include <iostream>

//나만의 Array 를 만드는 프로젝트.

namespace MyArray{
class Array {
private:
    const int dim; // 몇 차원 배열인지.
    int* size; // 각 차원마다 몇 개의 배열이 있는지.
    struct Address {
        int level;
        void* next;
    };
    Address* top;


public:
    Array(int dim, int* array_size);
    Array(const Array& arr);
    ~Array();
    void initialize_address(Address* current);
    void copy_address(Address * dst, Address * src);
    void delete_address(Address* current);

};


Array::Array(int dim, int* array_size) : dim(dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) {
        size[i] = array_size[i];
    }
    top = new Address;
    top->level = 0;
    initialize_address(top);// 빈 배열공간 heap 에 생성.
}

Array::Array(const Array &arr) : dim(arr.dim) {
    size = new int[arr.dim];
    for (int i = 0; i < arr.dim; i++) {
        size[i] = arr.size[i];
    }
    top = new Address;
    top->level = 0;
    initialize_address(top);// 빈 배열공간 heap 에 생성.
    copy_address(top, arr.top);
}

Array::~Array() {
    delete_address(top);
    delete[] size;
}

void Array::initialize_address(Address *current) {
    if (!current) return;
    if (current->level == dim - 1) {
        current->next = new int[size[current->level]];
        return;
    }
    current->next = new Address[size[current->level]];
    for (int i = 0; i < size[current->level]; i++) {
        (static_cast<Address*>(current->next) + i)->level = current->level + 1;
        initialize_address(static_cast<Address*>(current->next) + i);
    }
}

void Array::copy_address(Address *dst, Address *src) {
    if (dst->level == dim - 1) {
        for (int i = 0; i < size[dst->level]; ++i)
            static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
        return;
    }
    for (int i = 0; i != size[dst->level]; i++) {
        Address* new_dst = static_cast<Address*>(dst->next) + i;
        Address* new_src = static_cast<Address*>(src->next) + i;
        copy_address(new_dst, new_src);
    }
}

void Array::delete_address(Address *current) {
    if (!current) return;
    for (int i = 0; i < size[current->level]; i++) {
        delete_address(static_cast<Address*>(current->next) + i);
    }
    if (current->level == dim - 1) {
        delete[] static_cast<int*> (current->next);
    }
    else {
        delete[] static_cast<Address*> (current->next);
    }
}

}


int main() {
    return 0;

}
