#include <iostream>
#include <cmath>

using namespace std;

int task1491 () {
    const int arrayLength = 100000;
    int N;
    cin >> N;
    int a, b, c;
    int knights[arrayLength] = {};

    for (int i = 0; i < N + 1; i++)
    {
        cin >> a >> b >> c;
        a--;
        for(; a < b; a++)
            knights[a] += c;
    }

    for (int i = 0; i < N; i++)
        cout << knights[i] << ' ';

    return 0;
}

int task1510 () {
    const long arrayLength = (int)pow(10, 9);
    int N;
    cin >> N;
    int a;
    int numbers[arrayLength] = {}

    for (int i = 0; i < N + 1; i++)
    {
        cin >> a >> b >> c;
        a--;
        for(; a < b; a++)
            knights[a] += c;
    }

    for (int i = 0; i < N; i++)
        cout << knights[i] << ' ';

    return 0;
}


int main() {
    task1491();
}
