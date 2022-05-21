#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int b;

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    inputFile >> b;
    if (b == 1 || b == 2 || b == 3 || b == 6){
        outputFile << -1;
        return 0;
    }
    if(b == 4){
        outputFile << 2 << endl << 1 << endl << 0 << endl << 1;
        return 0;
    }
    if(b == 5){
        outputFile << 1 << endl << 2 << endl << 0 << endl << 0 << endl << 2;
        return 0;
    }
    int* arr = new int[b + 1];
    arr[1] = 2;
    arr[2] = 1;
    arr[b - 4] = 1;
    arr[b] = b - 4;
    for(int i = 1; i < b + 1; i++)
        outputFile << arr[i] << endl;
    return 0;
}