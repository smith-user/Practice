#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;
    string result;
    switch (n)
    {
        case 12:
        case 1:
        case 2:
            result = "Winter";
            break;
        case 3:
        case 4:
        case 5:
            result = "Spring";
            break;
        case 6:
        case 7:
        case 8:
            result = "Summer";
            break;
        case 9:
        case 10:
        case 11:
            result = "Autumn";
            break;
        default:
            result = "Error";
    }
    outputFile << result << endl;
}
