#include <iostream>

using namespace std;

const int LENGTH = 20;

void generateNumbers(int numbers[]) {
    for (int i = 0; i < LENGTH; i++) {
        numbers[i] = i;
    }
}

int find_sum(const int *table, int length) {
    int sum = 0;
    int index = 0;
    while (index < length) {
        sum += *table;
        table++;
        index++;
    }
    return sum;
}

int main() {
    int numbers[LENGTH];
    generateNumbers(numbers);

    int sum10First = find_sum(numbers, 10);
    int sum5Next = find_sum(&numbers[10], 5);
    int sum5Last = find_sum(&numbers[15], 5);

    cout << "First 10 sum: " << sum10First << endl;
    cout << "Next 5 sum: " << sum5Next << endl;
    cout << "Last 5 sum: " << sum5Last << endl;

    return 0;
}
