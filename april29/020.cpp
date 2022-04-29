#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;

    int num;
    inputFile >> num;
    int prevNum = num;
    int currentCount = 1;
    int maxCount = 0;
    bool top = true;
    for(int i = 0; i < N - 1; i++)
    {
        inputFile >> num;
        if ((top && num > prevNum) || (!top && num < prevNum))
        {
            currentCount++;
            top = !top;
        }
        else
        {
            maxCount = max(currentCount, maxCount);
            currentCount = 1;
            if (num != prevNum)
            {
                top = num < prevNum;
                currentCount++;
            }
        }
        prevNum = num;
    }
    maxCount = max(currentCount, maxCount);
    outputFile << maxCount << endl;
    inputFile.close();
    outputFile.close();
}