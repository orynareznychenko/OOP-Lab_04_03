#pragma once
#include <stdexcept>

class Array {
protected:
    static const int MAX_SIZE = 256;
    unsigned char data[MAX_SIZE];
    int count;

    bool rangeCheck(int index) const;

public:
    Array(int n = 0, unsigned char initVal = 0);
    virtual ~Array();

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    virtual Array* add(const Array* other) const;
    int getCount() const;
};