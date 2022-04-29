#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int hashFunc(string input) {
    int sumCode = 0;
    for(int i = 0; i < input.length(); i++)
        sumCode += input[i] * (int)pow(2, input.length() - i - 1);
    return sumCode;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string S, T;
    inputFile >> S >> T;

    int hashT = hashFunc(T);
    int hashSegment = hashFunc(S.substr(0, T.length()));
    for(int i = 0; i < S.length() - T.length() + 1; i++)
    {
        if(hashT == hashSegment)
        {
            int j = 0;
            while(j < T.length() && S[i + j] == T[j])
                j++;
            if(j == T.length())
                outputFile << i << ' ';
        }
        hashSegment = (hashSegment - S[i] * (int)pow(2, T.length() - 1)) * 2 + S[i + T.length()];
    }
    outputFile << endl;
    inputFile.close();
    outputFile.close();
}