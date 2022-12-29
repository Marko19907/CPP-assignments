#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * The tolerance below which the numbers are considered equal.
 */
const double TOL = 0.00001;

template <typename T> bool equal(T a, T b) {
    cout << "General version" << endl;
    if (!a || !b) {
        return false;
    }
    return a == b;
}

bool equal(double a, double b) {
    cout << "Double version" << endl;
    const double delta = abs(max(a, b)) - abs(min(a, b));

    if (delta < TOL) {
        return true;
    }

    return false;
}

int main() {
    int a = 5;
    int b = 10;
    cout << "a = " << a << ", b = " << b << endl;
    if (equal(a, b)) {
        cout << "a and b are equal" << endl;
    }
    else {
        cout << "a and b are not equal" << endl;
    }


    double c = 0.0001;
    double d = 0.00011;
    double e = 0.00000011;
    cout << fixed << showpoint << setprecision(8) << "c = " << c << ", d = " << d << ", e = " << e << endl;
    if (equal(c, d)) {
        cout << "c and d are equal" << endl;
    }
    else {
        cout << "c and d are not equal" << endl;
    }

    if (equal(c, e)) {
        cout << "c and e are equal" << endl;
    }
    else {
        cout << "c and e are not equal" << endl;
    }


    return 0;
}
