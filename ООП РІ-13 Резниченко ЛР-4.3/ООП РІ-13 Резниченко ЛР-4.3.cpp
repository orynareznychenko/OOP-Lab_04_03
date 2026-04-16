#include <iostream>
#include <typeinfo>
#include <string>
#include "Array.h"
#include "Octal.h"
#include "String.h"

using namespace std;

int main() {
    cout << "--- OCTAL CLASS TESTING ---\n";
    try {
        char b1[101], b2[101];
        cout << "Enter first octal number: "; cin >> b1;
        cout << "Enter second octal number: "; cin >> b2;

        Octal o1(b1);
        Octal o2(b2);

        Array* ptr1 = &o1;
        Array* ptr2 = &o2;
        Array* ptr_res = ptr1->add(ptr2);

        Octal o_res_add = o1 + o2;
        Octal o_res_sub = (o1 > o2) ? (o1 - o2) : (o2 - o1); 

        cout << "Octal 1: "; o1.print(); cout << "\n";
        cout << "Octal 2: "; o2.print(); cout << "\n";

        cout << "Addition result (ptr->add): ";
        dynamic_cast<Octal*>(ptr_res)->print(); cout << "\n";

        cout << "Addition result (o1 + o2): ";
        o_res_add.print(); cout << "\n";

        cout << "Subtraction result (larger - smaller): ";
        o_res_sub.print(); cout << "\n";

        cout << "Equality (o1 == o2): " << (o1 == o2 ? "True" : "False") << "\n";
        cout << "Comparison (o1 > o2): " << (o1 > o2 ? "True" : "False") << "\n";
        cout << "Result object type: " << typeid(*ptr_res).name() << "\n\n";

        delete ptr_res;
    }
    catch (const std::invalid_argument& e) {
        cout << "\nException caught: " << e.what() << "\n\n";
    }

    cout << "--- STRING CLASS TESTING ---\n";
    string sb1, sb2;
    cout << "Enter first string: "; cin.ignore(); getline(cin, sb1);
    cout << "Enter second string: "; getline(cin, sb2);

    String s1(sb1.c_str());
    String s2(sb2.c_str());

    Array& ref1 = s1;
    Array& ref2 = s2;
    Array* ref_res = ref1.add(&ref2);

    String s_res = s1 + s2;

    cout << "Concatenation result (ref.add): ";
    dynamic_cast<String*>(ref_res)->print(); cout << "\n";

    cout << "Concatenation result (s1 + s2): ";
    s_res.print(); cout << "\n";

    cout << "Result object type: " << typeid(*ref_res).name() << "\n\n";

    cout << "--- SUBSTRING OPERATIONS (String 1) ---\n";
    string sub_in;
    cout << "Enter substring to find/insert in String 1: "; getline(cin, sub_in);
    String sub_obj(sub_in.c_str());

    int pos = s1.find(sub_obj);
    cout << "Found at position: " << pos << "\n\n";

    cout << "Original String 1: "; s1.print(); cout << "\n";
    s1.insert(1, sub_obj);
    cout << "After insertion at index 1: "; s1.print(); cout << "\n";

    s1.remove(1, sub_obj.length());
    cout << "After removal of inserted substring: "; s1.print(); cout << "\n\n";

    cout << "--- RANGE CHECK TESTING ---\n";
    try {
        cout << "Accessing index 500...\n";
        s1[500] = 'X';
    }
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << "\n";
    }

    delete ref_res;
    return 0;
}