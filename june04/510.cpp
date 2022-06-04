#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    double* count = new double[n];
    count[0] = 1;
    for(int i=2; i<=n; i+=2)
    {
        count[i] = count[i - 2]*3;
        for (int j = i - 4; j >= 0; j -= 2)
            count[i] += count[j] * 2;
    }
    out << count[n];
    return 0;
}