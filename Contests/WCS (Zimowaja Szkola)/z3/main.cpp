#include <iostream>
#include <cstdio>
#include <queue>

#define F first
#define S second
#define mp make_pair

using namespace std;

const int sx[4] = {-1, 0, 1,  0};
const int sy[4] = { 0, 1, 0, -1};

int fld[110][110];
bool used[110][110];

//bool exist(int x, int y)
//{
//  return (x >= 0 && y >= 0 && y < m && x < n);
//}

int main()
{
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #define debug(...) printf(__VA_ARGS__)
#else
  #define debug(...)
  #define cerr if(0)cerr
#endif // LOCAL
  int n, m;
  scanf("%d %d\n", &n, &m);
  char tc;
  scanf("%c\n", &tc);
  cerr << tc << endl;
  int dir;
  if (tc == '>')
    dir = 1;
  if (tc == 'v')
    dir = 2;
  if (tc == '<')
    dir = 3;
  if (tc == '^')
    dir = 0;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char x;
      scanf("%c", &x);
      fld[i][j] = (x == 'x' ? 1 : 0);
    }
    scanf("\n");
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      debug("%d ", fld[i][j]);
    debug("\n");
  }

  int k = 0;
  if (dir == 1 || dir == 3)
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 1; j < m; ++j)
        if ((fld[i][j - 1] == 1 && fld[i][j] == 0) || (j == m - 1 && fld[i][j] == 1))
          ++k;
    }
  }
  else
  {
    for (int j = 0; j < m; ++j)
    {
      for (int i = 1; i < n; ++i)
        if ((fld[i - 1][j] == 1 && fld[i][j] == 0) || (i == n - 1 && fld[i][j] == 1))
        {
          cerr << i << " " << j << endl;
          ++k;
        }
    }
  }
  cerr << k;
  if (k > 20)
    printf("No\n");
  else
  {
    bool ok = true;
    if (dir == 1)
      for (int i = 0; i < n; ++i)
        if (fld[i][m - 1] == 1)
          ok = false;
    if (dir == 2)
      for (int j = 0; j < m; ++j)
        if (fld[n - 1][j] == 1)
          ok = false;
    if (dir == 3)
      for (int i = 0; i < n; ++i)
        if (fld[i][0] == 1)
          ok = false;
    if (dir == 0)
      for (int j = 0; j < m; ++j)
        if (fld[0][j] == 1)
          ok = false;
    if (ok)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
