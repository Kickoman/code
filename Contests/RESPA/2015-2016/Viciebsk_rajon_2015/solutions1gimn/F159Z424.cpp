#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define DEBUGs
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = (int) 1e9;
const int SWAG =  228;
const long long INFll = (long long) 1e18;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (a.S != b.S ? a.S > b.S : (a.F.S != b.F.S ? a.F.S > b.F.S : a.F.F > b.F.F));
//    return (a.F.S != b.F.S ? a.F.S > b.F.S : (a.S != b.S ? a.S < b.S : a.F.F > b.F.F));
//    return (a.F.F != b.F.F ? a.F.F < b.F.F : (a.F.S != b.F.S ? a.F.S < b.F.S : a.S < b.S));
}

int main()
{
//    ios_base::sync_with_stdio(0);
#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#define cerr if(0)cerr
#endif // DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > a(m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }

    sort(a.begin(), a.end());
    int lv = (m - n) / (n - 1);
    vector<int> ans;
    int k = 0;
    for (int i = a.size() - 1, k = 0; i >= 0 && k < n; ++k, i -= lv + 1)
        ans.push_back(a[i].S + 1);

    for (int i = ans.size() - 1; i > -1; --i)
        printf("%d ", ans[i]);
    return 0;
}
