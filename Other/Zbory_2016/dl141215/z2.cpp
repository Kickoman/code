#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("olymp.in", "r", stdin);
    freopen("olymp.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> t(2 * n + 1);
    t[1] = n;
    for (int i = 1, un = n - 1; i < n; ++i)
        t[i << 1] = t[i],
        t[i << 1 ^ 1] = un--;
    for (int i = 2 * n - 1; i >= n; --i)
        printf("%d ", t[i]);
    return 0;
}