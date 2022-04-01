#include <iostream>
#include <fstream>

using namespace std;

bool check(int a, int b, int c)
{
    return a + b == c;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int a, b, c;
    inputFile >> a >> b >> c;

    if (check(a, b, c) or check(a, c, b) or check(b, c, a))
        outputFile << "YES" << endl;
    else
        outputFile << "NO" << endl;
}
