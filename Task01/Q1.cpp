
#include <iostream>
using namespace std;

void callByValue(int x) {
    x = 100;
}

void callByReference(int &x) {
    x = 100;
}

void callByPointer(int *x) {
    *x = 100;
}

int main() {
    int a = 10;

    callByValue(a);
    cout << "Call by Value: " << a << endl;

    callByReference(a);
    cout << "Call by Reference: " << a << endl;

    callByPointer(&a);
    cout << "Call by Pointer: " << a << endl;

    return 0;
}
