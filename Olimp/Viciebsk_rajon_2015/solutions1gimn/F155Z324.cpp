#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;

int a[2100][2100];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= min(n, m); i++){
        for (int ii = 0; ii <= n - i; ii++)
            for (int jj = 0; jj <= m - i; jj++)
            {
                bool fl = true;
                for (int i1 = ii; i1 < ii + i; i1++)
                    for (int j1 = jj; j1 < jj + i; j1++)
                        if (a[i1][j1] == 1) {fl = false; break;}
                if (fl) ans++;
            }
    }

    cout << ans << endl;
    return 0;
}
