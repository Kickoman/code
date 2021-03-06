#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> tin, up, ans;

int timer = 0;

void dfs(int v, int p = -1)
{
  tin[v] = up[v] = ++timer;
  int children = 0;

  for (int i = 0; i < g[v].size(); ++i)
  {
    int to = g[v][i];

    if (to == p)
      continue;

    if (tin[to] != 0)
      up[v] = min(up[v], tin[to]);
    else
    {
      children++;
      dfs(to, v);
      up[v] = min(up[v], up[to]);

      if (up[to] >= tin[v] && p != -1)
        ans[v] = true;
    }
  }
  if (p == -1 && children > 1)
    ans[v] = true;
}

int main()
{
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #define debug(...) printf(__VA_ARGS__);
#else
  #define debug(...)
#endif
  int n, m;
  scanf("%d %d", &n, &m);

  g.resize(n);
  tin.resize(n);
  up.resize(n);
  ans.resize(n);

  for (int i = 0; i < m; ++i)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0);

  for (int i = 0; i < n; ++i)
    debug("%d: %d %d\n", i, tin[i], up[i]);

  int k = 0;
  for (int i = 0; i < ans.size(); ++i)
    k += ans[i];
  printf("%d\n", k);

  for (int i = 0; i < ans.size(); ++i)
    if (ans[i])
      printf("%d\n", i + 1);
  return 0;
}
