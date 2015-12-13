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
    int n, m, k = -1;
    cin >> n >> m;
    string s;
    cin >> s;
    char a[n + 1][m + 1];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
        k++, a[i][j] = s[k];
    string ans = "";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        ans += a[i][j];
    cout << ans;
    return 0;
}
