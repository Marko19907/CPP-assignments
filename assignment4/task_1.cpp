#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string contains(const vector<int> &numbers, const int searchValue) {
    auto it = std::find(numbers.begin(), numbers.end(), searchValue);
    if (it != numbers.end()) {
        return "Vector contains " + to_string(*it);
    }
    else {
        return "Vector does not contain " + to_string(searchValue);
    }
}

int main() {
    vector<int> numbers;

    numbers.emplace_back(3);
    numbers.emplace_back(5);
    numbers.emplace_back(7);
    numbers.emplace_back(11);
    numbers.emplace_back(13);

    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;

    numbers.emplace(numbers.cbegin(), 2);
    cout << "Front after modification: " << numbers.front() << endl;

    cout << "4: " << contains(numbers, 4) << endl;
    cout << "11: " << contains(numbers, 11) << endl;

    return 0;
}
