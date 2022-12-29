#include <iostream>

using namespace std;

string word1;
string word2;
string word3;

/**
 * Gets the 3 words from the user, a)
 */
void getWords() {
    cout << "Enter word #1: ";
    cin >> word1;
    cout << "Enter word #2: ";
    cin >> word2;
    cout << "Enter word #3: ";
    cin >> word3;
}

/**
 * Counts the number of 'er' occurrences in the given string, h)
 */
int getErOccurrences(const string &sentence) {
    int occurrences = 0;
    unsigned long index = 0;
    while (index < sentence.length()) {
        if (sentence[index] == 'e' && sentence[index + 1 % sentence.length()] == 'r') {
            occurrences++;
        }
        index++;
    }
    return occurrences;
}

int main() {
    // a)
    getWords();

    // b)
    const string sentence = word1 + " " + word2 + " " + word3;
    cout << "Sentence: '" << sentence << "' " << endl;

    // c)
    cout << "Word1 length: " << word1.length() << endl;
    cout << "Word2 length: " << word2.length() << endl;
    cout << "Word3 length: " << word3.length() << endl;
    cout << "Sentence length: " << sentence.length() << endl;

    // d)
    string sentence2 = sentence;

    // e)
    if (sentence2.length() >= 12) {
        const string replacement = "xxx";
        sentence2.replace(9, replacement.length(), replacement);
    }
    else {
        cout << "The sentence is not long enough to replace chars 10 to 12!" << endl;
    }
    cout << "Sentence: '" << sentence << "' " << endl;
    cout << "Sentence2: '" << sentence2 << "' " << endl;

    // f)
    if (sentence2.length() >= 4) {
        const string sentence_start = sentence.substr(0, 5);
        cout << "Sentence: '" << sentence << "' " << endl;
        cout << "Sentence start: '" << sentence_start << "' " << endl;
    }
    else {
        cout << "The sentence is not long enough to get the first 5 chars!" << endl;
    }

    // g
    if (sentence.find("hallo") != string::npos) {
        cout << "Sentence contains 'hallo'" << endl;
    }
    else {
        cout << "Sentence does not contain 'hallo'" << endl;
    }
    
    // h
    const int occurrences = getErOccurrences(sentence);
    cout << "'er' occurs " << occurrences << " time" << (occurrences == 1 ? "" : "s") << " in the sentence" << endl;

    return 0;
}
