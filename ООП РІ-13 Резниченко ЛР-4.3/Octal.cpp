#include "Octal.h"
#include <iostream>
#include <stdexcept>

void Octal::trim() {
    while (count > 1 && data[count - 1] == 0) {
        count--;
    }
}

Octal::Octal(int n, unsigned char initVal) : Array((n > 100 ? 100 : n), initVal) {}

Octal::Octal(const char* str, int max_n) : Array(max_n, 0) {
    int len = 0;
    while (str[len] != '\0') len++;
    int actual_len = (len > 100) ? 100 : len;
    count = actual_len;

    for (int i = 0; i < count; ++i) {
        char c = str[len - 1 - i];
        if (c < '0' || c > '7') {
            throw std::invalid_argument("Error: Invalid octal digit entered!");
        }
        data[i] = c - '0';
    }
    trim();
}

Array* Octal::add(const Array* other) const {
    const Octal* o2 = dynamic_cast<const Octal*>(other);
    if (!o2) return new Octal(*this);

    int max_c = (count > o2->count) ? count : o2->count;
    Octal* res = new Octal(100);
    res->count = max_c;

    unsigned char carry = 0;
    for (int i = 0; i < max_c; ++i) {
        unsigned char val1 = (i < count) ? data[i] : 0;
        unsigned char val2 = (i < o2->count) ? o2->data[i] : 0;
        unsigned char sum = val1 + val2 + carry;
        res->data[i] = sum % 8;
        carry = sum / 8;
    }

    if (carry > 0 && max_c < 100) {
        res->data[max_c] = carry;
        res->count = max_c + 1;
    }
    res->trim();
    return res;
}

Octal Octal::operator+(const Octal& other) const {
    Array* temp = this->add(&other);
    Octal* octal_temp = dynamic_cast<Octal*>(temp);
    Octal result = *octal_temp;
    delete temp;
    return result;
}

Octal Octal::operator-(const Octal& other) const {
    if (*this < other) {
        return Octal(1, 0); 
    }
    Octal res(100);
    res.count = count;
    int borrow = 0;

    for (int i = 0; i < count; ++i) {
        int val1 = data[i];
        int val2 = (i < other.count) ? other.data[i] : 0;
        int diff = val1 - val2 - borrow;

        if (diff < 0) {
            diff += 8; 
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        res.data[i] = diff;
    }
    res.trim();
    return res;
}

bool Octal::operator==(const Octal& other) const {
    if (count != other.count) return false;
    for (int i = 0; i < count; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool Octal::operator!=(const Octal& other) const {
    return !(*this == other);
}

bool Octal::operator<(const Octal& other) const {
    if (count != other.count) return count < other.count;
    for (int i = count - 1; i >= 0; --i) {
        if (data[i] != other.data[i]) return data[i] < other.data[i];
    }
    return false;
}

bool Octal::operator>(const Octal& other) const {
    return other < *this;
}

void Octal::print() const {
    for (int i = count - 1; i >= 0; --i) {
        std::cout << (int)data[i];
    }
}