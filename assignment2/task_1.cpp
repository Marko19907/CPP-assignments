#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "i value = " << i << endl;
    cout << "i address = " << &i << endl;
    cout << endl;

    cout << "j value = " << j << endl;
    cout << "j address = " << &j << endl;
    cout << endl;

    cout << "*p value = " << *p << endl;
    cout << "*p address = " << p << endl;
    cout << endl;

    cout << "*q value = " << *q << endl;
    cout << "*q address = " << q << endl;
    cout << endl;

    // Task B
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;
    cout << p << " " << q << endl;

    return 0;
}
