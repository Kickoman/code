#include <iostream>
#include <cstdio>

using namespace std;

int   f[2500][2500],
    fld[2500][2010];

int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
//            cerr << i << " " << j << endl;
            scanf("%d", &fld[i][j]);
        }
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        f[i][0] = 1 - fld[i][0],
        sum += f[i][0];
    for (int i = 0; i < m; ++i)
        f[0][i] = 1 - fld[0][i],
        sum += f[0][i];
    if (f[0][0])
        sum--;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            if (!fld[i][j])
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1,
                sum += f[i][j];
    printf("%lld\n", sum);
//    cout << sum << endl;
    return 0;
}
