#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    int* data = new int[N];

    for (int i = 0; i < N; i++)
        inputFile >> data[i];

    int* subSeq = new int[N];
    for (int i = 0; i < N; i++) {
        subSeq[i] = 1;
        for (int j = 0; j < i; j++)
            if (data[j] < data[i])
                subSeq[i] = max(subSeq[i], 1 + subSeq[j]);
    }

    int result = subSeq[0];
    for (int i = 0; i < N; i++)
        result = max(result, subSeq[i]);

    outputFile << result << endl;
    inputFile.close();
    outputFile.close();
}