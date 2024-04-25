#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

namespace TextProcessor {
    
    int countVowels(const std::string& str) {
        int count = 0;
        for (char c : str) {
            if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') {
                count++;
            }
        }
        return count;
    }

 
    int countWords(const std::string& str) {
        std::istringstream iss(str);
        int count = 0;
        std::string word;
        while (iss >> word) {
            count++;
        }
        return count;
    }

    std::string reverseString(const std::string& str) {
        std::string reversed = str;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    std::string capitalizeSecondLetter(const std::string& str) {
        std::string result = str;
        bool capitalize = false;
        for (char& c : result) {
            if (std::isalpha(c)) {
                if (capitalize) {
                    c = std::toupper(c);
                    capitalize = false;
                } else {
                    capitalize = true;
                }
            } else {
                capitalize = false;
            }
        }
        return result;
    }
}

int main() {
    using namespace std;
    using namespace TextProcessor;

 
    ifstream inputFile("textfile.txt");

  
    string fileData;
    if (inputFile.is_open()) {
        stringstream buffer;
        buffer << inputFile.rdbuf();
        fileData = buffer.str();
        inputFile.close();
    } else {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    int vowelCount = countVowels(fileData);
    cout << "Number of vowels: " << vowelCount << endl;

    
    int wordCount = countWords(fileData);
    cout << "Number of words: " << wordCount << endl;

    string reversed = reverseString(fileData);
    cout << "Reversed statement: " << reversed << endl;

    string capitalized = capitalizeSecondLetter(fileData);
    cout << "Statement with second letter capitalized: " << capitalized << endl;

    return 0;
}
