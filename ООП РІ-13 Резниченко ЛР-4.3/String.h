#pragma once
#include "Array.h"

class String : public Array {
public:
    String(int max_len = 255);
    String(const char* str, int max_len = 255);

    int length() const;
    virtual Array* add(const Array* other) const override;

    String operator+(const String& other) const;

    int find(const String& sub) const;
    void remove(int index, int len_to_remove);
    void insert(int index, const String& sub);
    void print() const;
};