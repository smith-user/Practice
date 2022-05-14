#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int K;
    inputFile >> K;
    int result =  2 + K % 5 + 7 * (K / 5);
    if (K > 36)
        result++;
    if (K > 44)
        result++;
    if (result == 56 || result == 63 || result == 70 || result == 71)
        result += 2;
    outputFile << result << endl;
}