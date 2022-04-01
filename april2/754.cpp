#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    bool bCorrect = true;
    int maxWeight = 0;
    while(!inputFile.eof() and bCorrect)
    {
        int weight;
        inputFile >> weight;
        bCorrect = 94 <= weight and weight <= 727;
        if (bCorrect and weight > maxWeight)
            maxWeight = weight;
    }

    if(bCorrect)
        outputFile << maxWeight << endl;
    else
        outputFile << "Error" << endl;

    inputFile.close();
    outputFile.close();
}