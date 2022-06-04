#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, s;
    in >> n >> s;
    vector <vector<bool>> isFriend(1 + n, vector<bool>(1 + n));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            in >> v;
            isFriend[i][j] = (v == 1);
        }
    vector<bool>visited(1 + n, false);
    int ans = 0;
    {
        if (visited[cur])
            return;
        visited[cur] = true;
        ans++;
        for (int v = 1; v <= n; ++v)
            if (isFriend[cur][v])
                visit(v);
    };
    visit(s);
    out << ans - 1;
    return 0;
}