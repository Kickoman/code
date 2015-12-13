#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

long long ans = 0;

int f[2020][2020], a[2020][2020];

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
        f[i][j] = 0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++){
        if (a[i][j] == 1)
            continue;
        int k = min(f[i-1][j], f[i][j-1]);
        if (a[i-k][j-k] != 0) k--;
        k++;
        f[i][j] = k;
        ans += 1ll*k;
    }

    cout << ans << endl;
    return 0;
}


