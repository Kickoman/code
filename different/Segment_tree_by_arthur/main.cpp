#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n;
vector<int> t;

int query(int l, int r)
{
    int res = 0;
    cerr << l << " " << r << endl;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        cerr << l << " " << r << " " << res << "\n";
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

void build(vector<int> &v)
{
    for (int i = 0; i < n; ++i)
        t[n + i] = v[i];
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 ^ 1];
}

int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    scanf("%d", &n);
    t.resize(2 * n);
    vector<int> a(n + 2);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    build(a);


    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("Sum from %d to %d equals %d\n", l, r, query(l - 1, r));
    }
    return 0;
}
