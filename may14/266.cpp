#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int* minutes = new int[1440] {};
    int N;
    int hOpening, mOpening, hClosure, mClosure;
    int timeOpening, timeClosure;
    inputFile >> N;
    for(int i = 0; i < N; i++)
    {
        inputFile >> hOpening >> mOpening >> hClosure >> mClosure;
        timeOpening = hOpening * 60 + mOpening;
        timeClosure = hClosure * 60 + mClosure;
        do
        {
            minutes[timeOpening % 1440]++;
            timeOpening++;
        }
        while(timeOpening % 1440 != timeClosure);
    }

    int k = 0;
    for(int i = 0; i < 1440; i++)
        if(minutes[i] == N)
            k++;
    outputFile << k << endl;
}