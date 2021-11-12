#include <iostream>
#include <fstream>
#include <map>

using namespace std;

bool isNumber(string input) {
    if (input[0] != '-' and not isdigit(input[0]))
        return false;
    bool flagPoint = false;
    bool result = true;
    for (int i = 1; i < input.length() and result; i++) {
        result = isdigit(input[i]) or (input[i] == '.' and not flagPoint);
        if (input[i] == '.')
            flagPoint = true;
    }
    return result;
}

int task15() {
    string fileName;
    cout << "Имя файла: ";
    cin >> fileName;
    ifstream inputFile(fileName);
    ofstream outputFile("output15.txt");
    if (!inputFile) {
        outputFile << "File Reading Error!" << endl;
        return 1;
    }
    string line;
    string substr;
    int countLine = 1;
    while (!inputFile.eof()) {
        inputFile >> line;
        substr = "";
        for (int i = 0; i < line.length(); i++) {
            if ((isNumber(substr + line[i] + line[i + 1])) \
            or (isNumber(substr + line[i])))
                substr += line[i];
            else if (isNumber(substr)) {
                outputFile << substr << " - " << countLine << endl;
                substr = line[i];
            } else
                substr = line[i];
        }
        if (isNumber(substr))
            outputFile << substr << " - " << countLine << endl;
        countLine++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}

int task26() {
    string fileName;
    cout << "Имя файла: ";
    cin >> fileName;
    ifstream inputFile(fileName);
    ofstream outputFile("output26.txt");
    if (!inputFile) {
        outputFile << "File Reading Error!" << endl;
        return 1;
    }
    string line;
    inputFile >> line;
    inputFile.close();
    map <char, int> alphabet;
    char letter;
    for (char c : line) {
        if (not isalpha(c))
            continue;
        letter = toupper(c);
        if (alphabet.count(letter) == 0)
            alphabet[letter] = 1;
        else
            alphabet[letter]++;
    }
    for (auto i : alphabet) {
        outputFile << i.first << ": " << i.second << endl;
    }
    outputFile.close();
    return 0;
}

int main() {
    task15();
    task26();
}