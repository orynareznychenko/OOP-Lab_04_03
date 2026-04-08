#include "Array.h"

bool Array::rangeCheck(int index) const {
    return (index >= 0 && index < count);
}

Array::Array(int n, unsigned char initVal) {
    count = (n > MAX_SIZE) ? MAX_SIZE : (n < 0 ? 0 : n);
    for (int i = 0; i < count; ++i) {
        data[i] = initVal;
    }
}

Array::~Array() {}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) throw std::out_of_range("Index out of range");
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    if (!rangeCheck(index)) throw std::out_of_range("Index out of range");
    return data[index];
}

Array* Array::add(const Array* other) const {
    int max_c = (count > other->count) ? count : other->count;
    Array* res = new Array(max_c);
    for (int i = 0; i < max_c; ++i) {
        unsigned char val1 = (i < count) ? data[i] : 0;
        unsigned char val2 = (i < other->count) ? other->data[i] : 0;
        res->data[i] = val1 + val2;
    }
    return res;
}

int Array::getCount() const {
    return count;
}