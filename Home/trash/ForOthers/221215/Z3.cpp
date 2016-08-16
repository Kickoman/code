#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <cstring>
//#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

#define INF (1<<30)
#define F first
#define S second
#define mkp(a, b) make_pair(a, b)

const int sx[] = {-1, 0, 1, 0};
const int sy[] = {0, 1, 0, -1};

int n, a[1000][1000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            a[i+n][j] = a[i][j];
            a[i][j+n] = a[i][j];
            a[i+n][j+n] = a[i][j];
        }
    for(int i = 1; i <= 2*n; i++)
        for(int j = 1; j <= 2*n; j++)
        {
            a[i][j] += a[i-1][j];
            a[i][j] += a[i][j-1];
            a[i][j] -= a[i-1][j-1];
        }

    int ans = -(2e9);
    for(int i = 1; i <= 2*n; i++)
        for(int j = 1; j <= 2*n; j++)
            for(int x = 1; x <= i; x++)
                for(int y = 1; y <= j; y++)
                    if(i-x+1 <= n && j-y+1 <= n && a[i][j] - a[x-1][j] - a[i][y-1] + a[x-1][y-1] > ans)
                        ans = a[i][j] - a[x-1][j] - a[i][y-1] + a[x-1][y-1];
     cout << ans << endl;

    return 0;
}
