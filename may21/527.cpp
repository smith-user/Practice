#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool f(long long a, long long b, long long c, long long d){
    if (a == c && b == d)
        return true;
    while (b != 0){
        if (b > a){
            swap(a, b);
            if (a == c && b == d)
                return true;
        }
        if (b > 0){
            long long t = a % b;
            if (b == d && t <= c && c <= a && (a - c) % b == 0)
                return true;
        }
    }
    return false;
}


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int K;
    long long a, b, c, d;

    int k;
    inputFile >> k;
    for (int i = 0; i < k; i++){
        inputFile >> a >> b >> c >> d;
        if (f(a, b, c, d))
            outputFile << "YES" << endl;
        else
            outputFile << "NO" << endl;
    }
    return 0;
}