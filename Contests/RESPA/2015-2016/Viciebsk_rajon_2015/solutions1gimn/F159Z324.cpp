#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define DEBUGs
#define F first
#define S second

using namespace std;

const int INF = (int) 1e9;
const int SWAG =  228;
const long long INFll = (long long) 1e18;

int field[2010][2010],
    f[2010][2010];

int main()
{
//    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...)
    #define cerr if(0)cerr
#endif // DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &field[i][j]);
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i)
        f[0][i] = 1 - field[0][i],
        ans += f[0][i];
    for (int i = 1; i < n; ++i)
        f[i][0] = 1 - field[0][i],
        ans += f[i][0];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
        {
            if (field[i][j])
                f[i][j] = 0;
            else
                f[i][j] = min(min(f[i - 1][j], f[i - 1][j - 1]), f[i][j - 1]) + 1;
            ans += f[i][j];
        }

    printf("%I64d\n", ans);
    return 0;
}
