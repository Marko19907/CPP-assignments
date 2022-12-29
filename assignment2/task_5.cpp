#include <iostream>

using namespace std;

int main() {
    double number = 42;
    double *pointer = &number;
    double &reference = number;

    // fetch the value of 'number' in 3 different ways
    cout << "Value of number #1: " << number << endl;
    cout << "Value of number #2: " << *pointer << endl;
    cout << "Value of number #3: " << reference << endl;

    return 0;
}
