#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int a[2100][2100], f[2100][2100];
int main()
{
    ios_base::sync_with_stdio();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                f[i][j] = 1;
            else
                f[i][j] = 0;
        }
    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
        {
            if (a[i][j] == 1)
                continue;
            int z = min(f[i-1][j],f[i][j-1]);
            if (z == 0)
                continue;
            f[i][j] = z;
            if (a[i-z][j-z] == 0)
                f[i][j]++;
        }
    long long ans = 0;
    for (int i=0; i<n; i++)
     for(int j=0; j<m; j++)
        ans += f[i][j];
    cout << ans << endl;
return 0;
}
