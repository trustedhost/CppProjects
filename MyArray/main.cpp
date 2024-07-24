#include <iostream>

//나만의 Array 를 만드는 프로젝트.

namespace MyArray{
class Array;
class Int;
// Array에 [] 연산자를 도입하기 위해서 결과값인 int 처럼 행동하도록 wrapper class 를 선언한다.
//[] 연산자를 통해서 int 값에 접근할 때에는 int 변수처럼 행동하고, 아닌 경우, 주소값을 반환하도록 해야 한다.
// void* data 를 두어, level 이 dim-1  인 경우 data 를 int* 로 형변환, 아닌 경우 Address* 로 형변환.


class Array {
friend Int;
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
    Int operator[](const int index);

};
class Int {
private:
    int level;
    void* data;
    Array* array;

public:
    Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL);
    Int(const Int& i);
    Int operator[](int index);
    operator int();
    Int& operator=(const int& a);
};

Array::Array(int dim, int *array_size) : dim(dim) {
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
    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
        delete_address(static_cast<Address*>(current->next) + i);
    }
    if (current->level == dim - 1) {
        delete[] static_cast<int*> (current->next);
    }
    else {
        delete[] static_cast<Address*> (current->next);
    }
}

Int Array::operator[](const int index) {
    return Int(index, 1, static_cast<void*>(top), this);
}

Int::Int(int index, int _level, void *_data, Array *_array) : level(_level), data(_data), array(_array) {
    if(level < 1 || index >= array->size[level - 1]) {
        data = NULL;
        return;
    }
    if (level == array->dim) {
        data = static_cast<void*>(static_cast<int*>(static_cast<Array::Address*>(data)->next) + index);
    } else {
        data = static_cast<void*>( static_cast<Array::Address*>( static_cast<Array::Address*>(data)->next) + index);
    }

}

Int::Int(const Int &i) : level(i.level), data(i.data), array(i.array) {}

Int Int::operator[](int index) {
    if (!data) return 0;
    return Int(index, level + 1, data, array);
}

Int::operator int() {
    if(data) return *static_cast<int *>(data);
    return 0;
}

Int &Int::operator=(const int &a) {
    if (data) *static_cast<int*>(data) = a;
    return *this;
}


}


int main() {
    int size[] = {2, 3, 4};
    MyArray::Array arr(3, size);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                          << std::endl;
            }
        }
    }

}
