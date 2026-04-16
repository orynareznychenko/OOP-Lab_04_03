#include "String.h"
#include <iostream>

String::String(int max_len) : Array(max_len + 1, 0) {
    data[0] = 0;
}

String::String(const char* str, int max_len) : Array(max_len + 1, 0) {
    int len = 0;
    while (str[len] != '\0' && len < max_len && len < 255) {
        data[len + 1] = str[len];
        len++;
    }
    data[0] = (unsigned char)len;
}

int String::length() const {
    return data[0];
}

Array* String::add(const Array* other) const {
    const String* s2 = dynamic_cast<const String*>(other);
    if (!s2) return new String(1);

    int len1 = data[0];
    int len2 = s2->data[0];
    int new_len = len1 + len2;

    if (new_len > 255) new_len = 255;

    String* res = new String(255);
    res->data[0] = (unsigned char)new_len;

    for (int i = 1; i <= len1; ++i) res->data[i] = data[i];
    for (int i = 1; i <= new_len - len1; ++i) res->data[len1 + i] = s2->data[i];

    return res;
}

String String::operator+(const String& other) const {
    Array* temp = this->add(&other);
    String* str_temp = dynamic_cast<String*>(temp);
    String result = *str_temp;
    delete temp;
    return result;
}

int String::find(const String& sub) const {
    int len = data[0];
    int sublen = sub.data[0];
    if (sublen == 0 || sublen > len) return -1;

    for (int i = 1; i <= len - sublen + 1; ++i) {
        bool match = true;
        for (int j = 1; j <= sublen; ++j) {
            if (data[i + j - 1] != sub.data[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

void String::remove(int index, int len_to_remove) {
    int current_len = data[0];
    if (index < 1 || index > current_len || len_to_remove <= 0) return;
    if (index + len_to_remove - 1 > current_len) {
        len_to_remove = current_len - index + 1;
    }

    for (int i = index; i <= current_len - len_to_remove; ++i) {
        data[i] = data[i + len_to_remove];
    }
    data[0] -= (unsigned char)len_to_remove;
}

void String::insert(int index, const String& sub) {
    int current_len = data[0];
    int sublen = sub.data[0];
    if (index < 1) index = 1;
    if (index > current_len + 1) index = current_len + 1;

    int new_len = current_len + sublen;
    if (new_len > 255) new_len = 255;
    int actual_added = new_len - current_len;

    for (int i = current_len; i >= index; --i) {
        if (i + actual_added <= 255) data[i + actual_added] = data[i];
    }
    for (int i = 0; i < actual_added; ++i) {
        data[index + i] = sub.data[i + 1];
    }
    data[0] = (unsigned char)new_len;
}

void String::print() const {
    for (int i = 1; i <= data[0]; ++i) {
        std::cout << (char)data[i];
    }
}