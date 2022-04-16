#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int coord[] = {0, 0};

    int n;
    inputFile >> n;
    char axis;
    int value;
    for(int i = 1; i <= n; i++)
    {
        inputFile >> axis >> value;
        switch(axis)
        {
            case 'X':
                coord[0] += value;
                break;
            case 'Y':
                coord[0] += value;
                coord[1] += value;
                break;
            case 'Z':
                coord[0] += (-1) * value;
                coord[1] += value;
                break;
            default:
                ;
        }
    }

    outputFile << max(abs(coord[0]), abs(coord[1])) << endl;
    inputFile.close();
    outputFile.close();
}