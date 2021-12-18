#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a;
    int result = 0;
    int k = 0;
    map <int, int> mp;
    int num[N];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        if (mp.find(num[i]) == mp.end())
            mp[ num[i] ] = 1;
        else
            mp[ num[i] ] += 1;

        if (mp[ num[i] ] > k || (mp[ num[i] ] == k && num[i] < result)) {
            result = num[i];
            k = mp[ num[i] ];
        }
    }

    string output = "";
    for(int i : num)
        if (i != result)
            output += to_string(i) + ' ';
    for(int i = 0; i < k; i++)
        output += to_string(result) + ' ';
    cout << output << endl;
    return 0;
}