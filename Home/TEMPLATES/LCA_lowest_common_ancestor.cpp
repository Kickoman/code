#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

const int lg = 32; // Fix by Andrzej Bierlin

int tm = 0;
vector<vector<int> > tree, up;
vector<int> tin, tout;

void dfs(int v, int p)
{
  tin[v] = ++tm;
  up[v][0] = p;
  for (int i = 1; i <= lg; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];

  for (int i = 0; i < (int) tree[v].size(); ++i)
    if (tree[v][i] != p)
      dfs(tree[v][i], v);
  cerr << v << " " << p << endl;
  tout[v] = ++tm;
}

bool upper(int a, int b)
{
  return (tin[a] < tin[b] && tout[a] > tout[b]);
}

int lca(int a, int b)
{
  if (upper(a, b))
    return a;
  if (upper(b, a))
    return b;
  for (int i = lg; i >= 0; --i)
    if (!upper(up[a][i], b))
      a = up[a][i];
  return up[a][0] + 1;
}

int main()
{
//#ifdef LOCAL
  freopen("../Trying_LCA_memory/task.in", "r", stdin);
  freopen("../Trying_LCA_memory/task.out", "w", stdout);
//#endif // LOCAL
  cerr << "POCZATEK\n";
  int n, m;
  scanf("%d %d", &n, &m);
  tree.resize(n);
  up.resize(n);
  tin.resize(n);
  tout.resize(n);
  for (int i = 0; i < (int) up.size(); ++i)
    up[i].resize(lg + 1);
  for (int i = 0; i < m; ++i)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    tree[x].pb(y);
    tree[y].pb(x);
  }

  dfs(0, -1);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("LCA(%d, %d) = %d\n", a, b, lca(a, b));
  }
  printf("LEL");
  cerr << n << " lel " << m << endl;
  return 0;
}
