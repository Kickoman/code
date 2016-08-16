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

int main()
{
//  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #define debug(...) printf(__VA_ARGS__)
#else
  freopen("arsenal.in", "r", stdin);
  freopen("arsenal.out", "w", stdout);
  #define debug(...)
#endif //LOCAL
  int k;
  scanf("%d\n", &k);
  string s;
  getline(cin, s);
  vector<vector<char> > izg(k);
  for (int i = 0; i < k; ++i)
    izg[i].resize(s.size(), (char) 1);

  int x = 0, y = 0;
  for (int i = 0, dir = -1; i < (int) s.size(); ++i)
  {
//    cerr << s << endl;
    izg[x][y] = s[i];
    if (x == k - 1 || x == 0)
      dir *= -1;
//    cerr << dir << endl;
    x += dir;
    y++;
  }

  for (int i = 0; i < k; ++i)
    for (int j = 0; j < s.size(); ++j)
      if (izg[i][j] != (char) 1)
        cout << izg[i][j];
  return 0;
}
