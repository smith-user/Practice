#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string data;
    getline(inputFile, data);
    int linePtr = 0;
    vector<int> lines;
    lines.push_back(0);
    int maxCount = -1;
    for(auto c : data)
    {
        switch(c)
        {
            case '\\' :
                lines.push_back(0);
                linePtr++;
                break;
            case '<' :
                if (lines[linePtr] > 0)
                    lines[linePtr]--;
                else if (linePtr > 0)
                {
                    lines[linePtr - 1] += lines[linePtr + 1];
                    lines.erase(lines.begin() + linePtr);
                    linePtr--;
                }
                break;
            case '^' :
                if(linePtr != 0)
                    linePtr--;
                break;
            case '|' :
                if(lines.size() > linePtr + 1)
                    linePtr++;
                break;
            default:
                if(c >= 32)
                    lines[linePtr]++;
                break;
        }
        maxCount = max(maxCount, lines[linePtr]);
    }
    outputFile << maxCount << endl;
}