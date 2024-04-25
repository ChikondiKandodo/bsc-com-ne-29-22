#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
    int count = 0;
    bool inWord = false;
    for (char c : str) {
        if (std::isspace(c)) {
            inWord = false;
        } else {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
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

int main() {
   
    std::ifstream inputFile("textfile.txt");

    std::string fileData;
    if (inputFile.is_open()) {
        std::getline(inputFile, fileData);
        inputFile.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    int vowelCount = countVowels(fileData);
    std::cout << "Number of vowels: " << vowelCount << std::endl;

    int wordCount = countWords(fileData);
    std::cout << "Number of words: " << wordCount << std::endl;

    std::string reversed = reverseString(fileData);
    std::cout << "Reversed statement: " << reversed << std::endl;

    std::string capitalized = capitalizeSecondLetter(fileData);
    std::cout << "Statement with second letter capitalized: " << capitalized << std::endl;

    return 0;
}