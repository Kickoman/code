#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> tin, up;
vector<pair<int, int> > ans;
int timer = 0;

void dfs(int v, int p = -1)
{
    tin[v] = up[v] = ++timer;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (g[v][i] == p)
            continue;
        if (tin[to] != 0)
            up[v] = min(up[v], tin[to]);
        else
        {
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (up[to] > tin[v])
                ans.push_back(make_pair(v + 1, to + 1));
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL
    int n, m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    for (int i = 0, x, y; i < m; ++i)
    {
        scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    for (auto i = 0; i < ans.size(); ++i)
        printf("%d -- %d\n", ans[i].first, ans[i].second);
    return 0;
}
