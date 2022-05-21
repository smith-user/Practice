#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    int M;
    inputFile >> N >> M;

    // 1 : Ax + By + C > 0
    // 2 : Ax + By + C < 0

    double supA1, infA1;
    double supA2, infA2;
    supA1 = supA2 = INT32_MAX;
    infA1 = infA2 = -INT32_MAX;
    bool ok1 = true;
    bool ok2 = true;
    int rightCount = 0;
    int leftCount = 0;
    int x, y;
    double t;
    for(int i = 0; i < M; i++)
    {
        inputFile >> x >> y;
        if(N % 2 == 0 && x == N / 2)
        {
            ///B = -1
            ok1 = y < 1.0 * N / 2;
            ok2 = y > 1.0 * N / 2;
            continue;
        }

        t = 1.0 * (2*y-N) / (2*x-N);

        if(x > 1.0 * N / 2)
        {
            ///B = -1
            infA1 = max(infA1, t);
            supA2 = min(supA2, t);
            rightCount++;

        } else {
            ///B = -1
            supA1 = min(supA1, t);
            infA2 = max(infA2, t);
            leftCount++;
        }
    }
    if((ok1 && supA1 > infA1) || (ok2 && supA2 > infA2) || rightCount == M || leftCount == M)
        outputFile << "YES" << endl;
    else
        outputFile << "NO" << endl;
}