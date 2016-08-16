#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> d;

int getmin(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tr && r == tr)
        return d[v];
    int tm = (tl + tr) / 2;
    return min(getmin(v * 2, tl, tm, l, min(r, tm)), getmin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
#ifdef LOCAL
    freopen("../task.in", "r", stdin);
    freopen("../task.out", "w", stdout);
    #define debug(...) printf(__VA_ARGS__);
#else
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = -228;
    int L = 1, R = n + 1;
    d.resize(4 * (n + 2));
    while (L < R)
    {
        int l = (L + R) / 2;
        l = 3;
        for (int i = 0; i < d.size(); ++i)
            d[i] = 0;
        int z = 1;
        while (z < n + 2)
            z *= 2;

        for (int i = z; i < z + l; ++i)
            d[i] = a[i - z + 1];

        for (int i = z - 1; i > 0; --i)
            d[i] = min(d[i * 2], d[i * 2 + 1]);
        cerr << l << endl;
        for (int i = z + l + 1; i < z + n + 2; ++i)
            d[i] = getmin(1, 0, n, i - z - l, i - z - 1);
        cerr << z << endl;
        for (int i = 0; i < 2 * z; ++i)
            cerr << d[i] << " ";
    return 0;
        if (d[n + 1] <= m)
            cerr << d[n + 1] << endl;
        if (d[n + 1] > m)
            R = l - 1;
        if (d[n + 1] < m)
            L = l + 1;
    }

    return 0;
}
