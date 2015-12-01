#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int f[2500][2500];

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
  vector<long long> x(n + 1), y(m + 1);
  for (int i = 1; i <= n; ++i)
    scanf("%I64d", &x[i]);
  for (int i = 1; i <= m; ++i)
    scanf("%I64d", &y[i]);
  for (int i = 0; i <= n; ++i)
    cerr << x[i] << " ";
  cerr << endl;
  for (int i = 0; i <= m; ++i)
    cerr << y[i] << " ";
  cerr << endl;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
    {
      if (i == 0 || j == 0)
        f[i][j] = 0;
      else
        if ((long long) sqrt(x[i] * y[j]) * (long long) sqrt(x[i] * y[j]) == x[i] * y[j])
        {
          cerr << i << " " << j << " " << x[i] << " " << y[j] << endl;
          f[i][j] = f[i - 1][j - 1] + 1;
        }
        else
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
  if (f[n][m] == 0)
  {
    printf("0\n");
    return 0;
  }
  printf("%d\n", f[n][m]);
  int i = n, j = m;
//  int axs = -1, axe, ays = -1, aye;
  vector<int> ax, ay;
  while (j >= 0 && i >= 0 && f[i][j] != 0)
  {
    while (i > 0 && f[i - 1][j] == f[i][j])
      --i;
    while (j > 0 && f[i][j - 1] == f[i][j])
      --j;
    ax.push_back(i);
    ay.push_back(j);
    --i, --j;
  }
  for (int i = ax.size() - 1; i >= 0; --i)
    printf("%d ", ax[i]);
  printf("\n");
  for (int i = ay.size() - 1; i >= 0; --i)
    printf("%d ", ay[i]);
  printf("\n");
//  axe = i + 1, aye = j + 1;
//  printf("%d %d\n%d %d\n", axs, axe, ays, aye);


  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= m; ++j)
      debug("%3d", f[i][j]);
    debug("\n");
  }
  return 0;
}
