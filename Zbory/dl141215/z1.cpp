#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pob pop_back
#define last back()

using namespace std;

#ifdef LOCAL
    #define TASK "task"
    #define debug(...) printf(__VA_ARGS__)
#else
    #define TASK "tickets"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

typedef long long ll;

ll happy(ll x)
{
    if (x < 10)
        return x;
    ll sum = 0;
    while (x)
        sum += x % 10,
        x /= 10;
    return happy(sum);
}

int main()
{
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<ll> a(n), ans;
    vector<vector<ll> > pr(10);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        pr[happy(a[i])].pb(a[i]);
    }

    while (pr[3].size() > 1)
    {
        ans.pb(pr[3].last);
        pr[3].pob();
        ans[ans.size() - 1] *= pr[3].last;
        pr[3].pob();
    }

    while (pr[2].size() > 0 && pr[4].size() > 0)
    {
        ans.pb(pr[2].last * pr[4].last);
        pr[2].pob();
        pr[4].pob();
    }
    while (pr[2].size() > 2)
    {
        ans.pb(pr[2].last);
        pr[2].pob();
        ans[ans.size() - 1] *= pr[2].last;
        pr[2].pob();
        ans[ans.size() - 1] *= pr[2].last;
        pr[2].pob();
    }

    while (pr[2].size() > 0 && pr[3].size() > 0)
    {
        ans.pb(pr[2].last * pr[3].last);
        pr[2].pob();
        pr[3].pob();
    }

    for (int i = 2; i < 10; ++i)
        for (int j = 0; j < pr[i].size(); ++j)
            ans.pb(pr[i][j]);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    return 0;
}
