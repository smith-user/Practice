#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> digitsInNumber(int number, int k)
{
    vector<int> arr(k);
    for (int i = k - 1; i >= 0 && number > 0; --i, number /= 10)
    {
        arr[i] = number % 10;
    }
    return arr;
}

bool isPrime(int number)
{
    for (int i = 2; i <= sqrt(number); ++i)
        if (number % i == 0)
            return false;
    return true;
}


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    int k = 0;
    for (int numb = pow(10, N - 1); numb < pow(10, N); ++numb)
    {
        vector<int> arr = digitsInNumber(numb, N);
        if (isPrime(arr))
            ++k;
    }

    out << k;

    return 0;
}