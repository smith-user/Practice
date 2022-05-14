#include <iostream>
#include <fstream>
#include <map>

using namespace std;

bool IsSpace(char c) {
    string spaces = ".,:;-'\"!?\n \t";
    for(auto space : spaces)
        if (c == space)
            return true;
    return false;
}


string inputString(string str) {
    string word;
    int i = 0;
    while(i < str.length() && !IsSpace(str[i]))
        word += tolower(str[i++]);
    return word;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M;
    inputFile >> N >> M;
    map<string, int> dict;
    string word;
    for (int i = 0; i < N; i++) {
        inputFile >> word;
        dict[inputString(word)] = 0;
    }

    while (!inputFile.eof()) {
        inputFile >> word;
        word = inputString(word);
        if (dict.find(word) == dict.end()) {
            outputFile << "Some words from the text are unknown." << endl;
            return 0;
        }
        dict[word]++;
    }

    for (auto pair : dict) {
        if (pair.second == 0) {
            outputFile << "The usage of the vocabulary is not perfect.";
            return 0;
        }
    }
    outputFile << "Everything is going to be OK." << endl;
}