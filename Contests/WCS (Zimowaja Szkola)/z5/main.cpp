#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const long long INFll = (long long) 1e18;

long long pw(long long x, long long y)
{
  long long res = 1;
  for (long long i = 0; i < y; ++i)
    res *= x;
  return res;
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
  long long x;
  int p;
  cerr << pw(3, 3);
  cin >> x >> p;
  long long b = p - 1;
  int ans = 0;

  vector<int> lp(10000010, 0), pr;
  for (int i = 2; i < 10000010; ++i)
  {
    if (lp[i] == 0)
      pr.push_back(i),
      lp[i] = i;
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] < 10000010; ++j)
      lp[pr[j] * i] = pr[j];
  }
  cerr << endl << pr.back();
  for (int i = 0; i < (int) pr.size(); ++i)
  {
    long long c = 1;
    for (int j = 0; j < b; ++j)
    {
      c *= pr[i];
      if (c > x )
      {
        cout << ans;
        return 0;
      }
    }
    ans++;
  }
  cout << ans;
  return 0;
}
