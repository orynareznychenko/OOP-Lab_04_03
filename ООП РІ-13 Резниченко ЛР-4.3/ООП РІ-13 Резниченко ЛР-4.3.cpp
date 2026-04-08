#include <iostream>
#include <typeinfo>
#include "Array.h"
#include "Octal.h"
#include "String.h"

using namespace std;

int main() {
    cout << "--- Testing Octal class ---\n";
    Octal o1("754");
    Octal o2("26");

    cout << "Octal 1: "; o1.print(); cout << "\n";
    cout << "Octal 2: "; o2.print(); cout << "\n";

    Array* ptr1 = &o1;
    Array* ptr2 = &o2;
    Array* ptr_res = ptr1->add(ptr2);

    cout << "[Pointer] Addition result: ";
    dynamic_cast<Octal*>(ptr_res)->print(); cout << "\n";
    cout << "Actual object type of ptr_res: " << typeid(*ptr_res).name() << "\n\n";

    delete ptr_res;

    cout << "--- Testing String class ---\n";
    String s1("Hello, ");
    String s2("World!");

    cout << "String 1: "; s1.print(); cout << " (Length: " << s1.length() << ")\n";
    cout << "String 2: "; s2.print(); cout << "\n";

    Array& ref1 = s1;
    Array& ref2 = s2;
    Array* ref_res = ref1.add(&ref2);

    cout << "[Reference] Concatenation result: ";
    dynamic_cast<String*>(ref_res)->print(); cout << "\n";
    cout << "Actual object type of ref_res: " << typeid(*ref_res).name() << "\n\n";

    String s3("Learning C++");
    String sub("++");
    int pos = s3.find(sub);
    cout << "Base string: "; s3.print(); cout << "\nFound '++' at position: " << pos << "\n";

    s3.remove(1, 9);
    cout << "After removal: "; s3.print(); cout << "\n";

    String sub2("Mastering ");
    s3.insert(1, sub2);
    cout << "After insertion: "; s3.print(); cout << "\n\n";

    cout << "--- Testing RangeCheck ---\n";
    try {
        unsigned char c = s1[300];
        cout << c;
    }
    catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << "\n";
    }

    delete ref_res;

    return 0;
}