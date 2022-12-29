#include <iostream>
#include <fstream>

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

void read_temperatures(double temperatures[], int length);

int main() {
    double temperatures[SAMPLES];
    read_temperatures(temperatures, SAMPLES);

    int index = 0;
    while (index < SAMPLES) {
        double temperature = temperatures[index];

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

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "temperatures.dat";
    ifstream file;
    file.open(filename);

    if (!file) {
        cout << "Could not open file!" << endl;
        exit(EXIT_FAILURE);
    }

    int number;
    int index = 0;
    while (file >> number && index < length) {
        temperatures[index] = number;
        index++;
    }

    file.close();
}
