#pragma once
#include "Array.h"

class Octal : public Array {
private:
    void trim();
public:
    Octal(int n = 0, unsigned char initVal = 0);
    Octal(const char* str, int max_n = 100);

    virtual Array* add(const Array* other) const override;

    Octal operator+(const Octal& other) const;
    Octal operator-(const Octal& other) const; 

    bool operator==(const Octal& other) const;
    bool operator!=(const Octal& other) const;
    bool operator<(const Octal& other) const;
    bool operator>(const Octal& other) const;

    void print() const;
};