#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int a[2100][2100], f[2100][2100];

int main() {
//    cin.tie(0);
//    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 0) {
                f[i][j] = 1 + min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j]));
                ans += f[i][j];
                //cout << f[i][j] << ' ';
            }
            else {
                f[i][j] = 0;
                //cout << f[i][j] << ' ';
            }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}

