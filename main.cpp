#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to count word frequencies
void countWordFrequencies(const string& text, map<string, int>& wordCount) {
    string word;
	for (char ch : text) {// Loop through each character in the text
        if (isspace(ch) || ch == ',' || ch == '.' || ch == '!' || ch == '?') {
            if (!word.empty()) {
                ++wordCount[word];
				word.clear();// Clear the word
            }
        }
        else {
            word += ch;
        }
    }
    if (!word.empty()) {
        ++wordCount[word];
    }
}

// Function to print word frequencies
void printWordFrequencies(const map<string, int>& wordCount) {
    for (const auto& entry : wordCount) {
        cout << entry.first << " - " << entry.second << endl;
    }
}

int main() {
    string text = "This is a test text. This text is for testing purposes! Is this text working correctly? Yes, it is.";
    cout << "Test text: \n" << text << endl;

    map<string, int> wordCount;
    countWordFrequencies(text, wordCount);

    cout << "\nWord frequencies:\n";
    printWordFrequencies(wordCount);

    return 0;
}
