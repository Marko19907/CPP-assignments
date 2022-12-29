#include <iostream>

using namespace std;

template<typename T, typename S>
class Pair {
public:
    const T first;
    const S second;

    Pair(T first, S second) : first(first), second(second) {};

    bool operator>(const Pair &other) {
        return (first + second) > (other.first + other.second);
    }

    Pair operator+(const Pair &other) {
        return Pair(first + other.first, second + other.second);
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 is larger" << endl;
    else
        cout << "p2 is larger" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;

    return 0;
}

/* Printout:
p1: 3.5, 14
p2: 2.1, 7
p1 is larger
Sum: 5.6, 21
*/
