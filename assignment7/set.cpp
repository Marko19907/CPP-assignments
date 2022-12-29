#include <vector>
#include <ostream>
#include <algorithm>
#include <iostream>

using namespace std;

class Set {
public:
    Set();

    Set(const Set &) = default;

    /**
     * Unions of the two sets.
     */
    Set operator+(const Set &other) const;

    /**
     * Adds an int to the Set.
     */
    Set &operator+=(int number);

    /**
     * Sets this Set equal to the other.
     */
    Set &operator=(const Set &other);

    /**
     * Prints out the Set to the console.
     */
    friend ostream &operator<<(ostream &out, const Set &set);

private:
    /**
     * The backing array.
     */
    vector<int> array;

    /**
     * Adds the given int to the backing vector.
     */
    void add(int number);

    /**
     * Returns true if the Set contains the given value.
     */
    bool contains(int number);

    /**
     * Returns a String representation of the Set.
     */
    string toString() const;
};

Set::Set() = default;

Set Set::operator+(const Set &other) const {
    Set set = *this;
    for (int i : other.array) {
        set += i;
    }
    return set;
}

Set &Set::operator+=(const int number) {
    this -> add(number);
    return *this;
}

Set &Set::operator=(const Set &other) {
    array.clear();
    for (int i : other.array) {
        add(i);
    }
    return *this;
}

ostream &operator<<(ostream &out, const Set &set) {
    out << set.toString();
    return out;
}

string Set::toString() const {
    if (array.empty()) {
        return "{}";
    }

    string result = "{";

    size_t index = 0;
    while (index < array.size() - 1) {
        result += to_string(array[index]) + ", ";
        index++;
    }

    // Last index does not have a comma
    result += to_string(array[index]);
    result += "}";

    return result;
}

void Set::add(const int number) {
    if (!contains(number)) {
        array.emplace_back(number);
    }
}

bool Set::contains(const int number) {
    return any_of(array.begin(), array.end(), [number](int x) { return number == x; });
}

int main() {
    Set a;
    a += 2;
    a += 3;
    a += 3;

    Set b;
    b += 10;
    b += 20;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    Set c;
    c += 1;
    cout << "c = " << c << endl;

    c = c + a;
    cout << "c + a = " << c << endl;

    Set d;
    cout << "Empty set 'd' = " << d << endl; // Print an empty Set

    return 0;
}
