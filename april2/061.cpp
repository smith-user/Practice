#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int firstTeam = 0;
    int secondTeam = 0;

    while(!inputFile.eof())
    {
        int t;
        inputFile >> t;
        firstTeam += t;
        inputFile >> t;
        secondTeam += t;
    }

    if (firstTeam > secondTeam)
        outputFile << 1 << endl;
    else if (secondTeam > firstTeam)
        outputFile << 2 << endl;
    else
        outputFile << "DRAW" << endl;

    inputFile.close();
    outputFile.close();
}
