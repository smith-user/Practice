#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    double amount = 100.00;
    double dollar, euro, newDollar, newEuro;
    inputFile >> dollar >> euro;
    for(int i = 0; i < N - 1; i++)
    {
        inputFile >> newDollar >> newEuro;
        amount *= max(1.0, max(newDollar / dollar, newEuro / euro));
        dollar = newDollar;
        euro = newEuro;
    }
    outputFile << fixed << setprecision(2) << amount << endl;
}
