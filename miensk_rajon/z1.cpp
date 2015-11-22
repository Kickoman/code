#include <iostream>
#include <cstdio>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>

#define F first
#define S second
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1000000000; // 10^9
const long long llINF = 10000000000000000ll; // 10^16
const int SWAG = 228;
const int LEET = 1337;

//                  N  E  S   W  NE SE  SW  NW
const int sx[8] = {-1, 0, 1,  0, -1, 1,  1, -1};
const int sy[8] = { 0, 1, 0, -1,  1, 1, -1, -1};

bool comp(pair<double, int> a, pair<double, int> b)
{
  if (abs(a.first - b.first) > 0.00001)
    return a.first > b.first;
  else
    return a.second < b.second;
}

int main()
{
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #define debug(...) printf(__VA_ARGS__)
#else
  freopen("arsenal.in", "r", stdin);
  freopen("arsenal.out", "w", stdout);
  #define debug(...)
#endif //LOCAL
  int n;
  cin >> n;
  vector<int> p(n);
  int pc = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> p[i];
    pc += p[i];
  }
  vector<int> q(n);
  for (int i = 0; i < n; ++i)
    cin >> q[i];

  vector<vector<pair<double, int> > > udz(n);

  for (int i = 0; i < pc; ++i)
  {
    int uid, gid;
    double a, b, c, d;
    cin >> uid >> gid >> a >> b >> c >> d;
    --gid;
    udz[gid].push_back(make_pair(a + b + c + d, uid));
  }

  vector<pair<double, int> > ans;
  for (int i = 0; i < n; ++i)
  {
    sort(udz[i].begin(), udz[i].end(), comp);
    
    for (int j = 0; j < min(q[i], (int) udz[i].size()); ++j)
      if (udz[i][j].first != 0)
        ans.push_back(make_pair(udz[i][j].first, udz[i][j].second));
        
    int j = min(q[i] - 1, (int) udz[i].size());
    while (j < udz[i].size() && (abs(udz[i][j].F - udz[i][j + 1].F) < 0.00001) && udz[i][j].F != 0)
    {
      ++j;
      ans.push_back(udz[i][j]);
    }
  }
  sort(ans.begin(), ans.end(), comp);
  cout << ans.size() << fixed << setprecision(2) << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].S << " " << ans[i].F << endl;
  return 0;
}
