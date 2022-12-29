#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;


    // Task 1 a)
    cout << "Task 1 a)" << endl;

    auto isOver15 = [](int i){ return 15 < i; };

    auto result1 = find_if(begin(v1), end(v1), isOver15);

    cout << *result1 << endl;


    // Task 1 b)
    cout << "Task 1 b)" << endl;

    /**
     * Returns true if the difference between the numbers is less than 2.
     */
    auto delta2 = [](int i, int j){ return (max(i, j) - min(i, j)) < 2; };

    auto result2 = equal(v1.begin(), v1.begin() + 5, v2.begin(), delta2);

    cout << result2 << endl;
    cout << (result2 ? "Equal" : "Not equal") << endl;


    auto result3 = equal(v1.begin(), v1.begin() + 4, v2.begin(), delta2);

    cout << result3 << endl;
    cout << (result3 ? "Equal" : "Not equal") << endl;


    // Task 1 c)
    cout << "Task 1 c)" << endl;

    auto isOdd = [](int i){ return (i % 2) != 0; };

    replace_copy_if(v1.begin(), v1.end(), v1.begin(), isOdd, 100);

    cout << "Modified v1: " << v1 << endl;


    return 0;
}
