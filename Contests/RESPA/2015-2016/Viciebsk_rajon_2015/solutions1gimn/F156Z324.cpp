#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<deque>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1], f[n + 1][m + 1];
    pair <int, int> b[n + 1][m + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 1)
        {
            b[i][j].first = j;
            b[i][j].second = i;
        }
        else
            if (i == 0 && j == 0)
        {
            b[i][j].first = -1;
            b[i][j].second = -1;
        }
        else
            if (i == 0 && j != 0)
        {
            b[i][j].first = b[i][j - 1].first;
            b[i][j].second = -1;
        }
        else
            if (i != 0 && j == 0)
        {
            b[i][j].first = -1;
            b[i][j].second = b[i - 1][j].second;
        }
        else
        if (i != 0 && j != 0)
        {
            b[i][j].first = b[i][j - 1].first;
            b[i][j].second = b[i - 1][j].second;
        }
        f[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    if (a[i][j] == 0)
        if (i == 0 || j == 0) f[i][j] = 1;
    else
        f[i][j] = max(min(j - b[i][j].first, min(i - b[i][j].second, f[i - 1][j - 1] + 1)), 1);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += f[i][j];
    cout << ans;
    return 0;
}
