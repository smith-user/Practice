#include <iostream>
#include <map>

using namespace std;

int main() {
    long N;
    cin >> N;
    long a;
    long result = 0;
    map <long, long> mp;

    for (long i = 0; i < N; i++)
    {
        cin >> a;
        if (mp.find(a) == mp.end())
            mp[a] = 1;
        else
            mp[a] += 1;

        if (mp[a] > (N/2))
            result = a;
    }
    cout << result << endl;

    return 0;
}
