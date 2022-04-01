#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int s;
    inputFile >> s;

    int petr, sergey, kate;
    petr = sergey = (int)(s / 6);
    kate = (int)(2 * s / 3);
    outputFile << petr << ' ' << kate << ' ' << sergey << endl;

    inputFile.close();
    outputFile.close();
}
