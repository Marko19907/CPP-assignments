#include <iostream>

using namespace std;

/**
 * Number of temperature samples to take.
 */
const int SAMPLES = 5;

/**
 * Number of samples that are below 10, excluding 10.
 */
int belowTen = 0;

/**
 * Number of samples that are between 10 and 20, including both 10 and 20.
 */
int betweenTenAndTwenty = 0;

/**
 * Number of samples that are above 20, excluding 20.
 */
int aboveTwenty = 0;

int main() {
    cout << "Input " << SAMPLES << " temperature samples" << endl;

    int index = 0;
    while (index < SAMPLES) {
        cout << "Temperature sample #" << index + 1 << ": ";

        double temperature;
        cin >> temperature;

        if (temperature < 10) {
            belowTen++;
        }
        else if (temperature > 20) {
            aboveTwenty++;
        }
        else {
            betweenTenAndTwenty++;
        }

        index++;
    }

    cout << endl;
    cout << "Samples under 10: " << belowTen << endl;
    cout << "Samples between 10 and 20: " << betweenTenAndTwenty << endl;
    cout << "Samples above 20: " << aboveTwenty << endl;

    return 0;
}
