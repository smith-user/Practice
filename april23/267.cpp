#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, x, y;
    inputFile >> N >> x >> y;
    double countTime = min(x, y);
    countTime +=  1.0 * x * y * (N - 1) / (x + y);
    int result = (int)countTime;;
    if (countTime - (int)countTime > 10e-7)
        result = (int)countTime + 1;
    outputFile << result << endl;
    inputFile.close();
    outputFile.close();
}