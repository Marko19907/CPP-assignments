#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_) {
    if (denominator_ != 0) {
        numerator = numerator_;
        denominator = denominator_;
        reduce();
    }
    else {
        throw "nevneren ble null";
    }
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction fraction = *this;
    fraction += other;
    return fraction;
}

Fraction Fraction::operator-(int number) const {
    Fraction fraction;
    fraction.set(number, 1);
    fraction = *this - fraction;
    return fraction;
}

Fraction operator-(int number, const Fraction &other) {
    Fraction fraction;
    fraction.set(number, 1);
    fraction = fraction - other;
    return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    set(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    set(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator-() const {
    Fraction fraction;
    fraction.numerator = -numerator;
    fraction.denominator = denominator;
    return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;
    fraction *= other;
    return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    set(numerator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    Fraction fraction = *this;
    fraction /= other;
    return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    set(numerator * other.denominator, denominator * other.numerator);
    return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    return compare(other) == 0;
}

bool Fraction::operator!=(const Fraction &other) const {
    return compare(other) != 0;
}

bool Fraction::operator<=(const Fraction &other) const {
    return compare(other) <= 0;
}

bool Fraction::operator>=(const Fraction &other) const {
    return compare(other) >= 0;
}

bool Fraction::operator<(const Fraction &other) const {
    return compare(other) < 0;
}

bool Fraction::operator>(const Fraction &other) const {
    return compare(other) > 0;
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = numerator;
    int b = denominator;
    int c;
    if (a < 0)
        a = -a;

    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    numerator /= a;
    denominator /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > other, 0 hvis de er like, -1 ellers
//
int Fraction::compare(const Fraction &other) const {
    Fraction fraction = *this - other;
    if (fraction.numerator > 0)
        return 1;
    else if (fraction.numerator == 0)
        return 0;
    else
        return -1;
}

void print(const string &text, const Fraction &fraction) {
    cout << text << fraction.numerator << " / " << fraction.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);


    cout << "---- task_1a, part a ----" << endl;

    Fraction e(15, 8);
    print("e = ", e);

    e = e - 1;
    print("e - 1 = ", e);

    Fraction f(13, 2);
    print("f = ", f);

    f = 5 - f;
    print("5 - f = ", f);


    return 0;
}
