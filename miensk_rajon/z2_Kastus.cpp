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

bool notNumber(char x)
{
  return (x < '0' || x > '9');
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
  int Q;
  scanf("%d\n", &Q);

  vector<vector<int> > et(9);
  vector<bool> ans;


  for (int i = 0; i < 9; ++i)
  {
    char x;
    while ((x = getchar()) && x != '\n')
      if (x == '*')
        et[i].push_back(-SWAG);
      else
        et[i].push_back((int) x - '0');
  }

  for (int k = 0; k < Q; ++k)
  {
    vector<vector<int> > user(9);
    for (int i = 0; i < 9; ++i)
    {
      char x;
      while ((x = getchar()) && x != '\n')
        if (notNumber(x))
          user[i].push_back(-SWAG);
        else
          user[i].push_back((int) x - '0');
    }

    bool ok = true;

    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if ((et[i][j] > 0 && et[i][j] != user[i][j]) || user[i][j] < 0)
          ok = false;

//    cerr << ok << endl;
    for (int i = 0; i < 9 && ok; ++i)
    {
      vector<int> non(10, 0);
      for (int j = 0; j < 9; ++j)
        non[user[i][j]]++;
      for (int j = 1; j < 10; ++j)
        if (non[j] != 1)
          ok = false;
    }

    for (int j = 0; j < 9 && ok; ++j)
    {
//      cerr << j << " ";
      vector<int> non(10, 0);
      for (int i = 0; i < 9; ++i)
        non[user[i][j]]++;
      for (int i = 1; i < 10; ++i)
        if (non[i] != 1)
          ok = false;
    }
//    cerr << ok << endl;

    for (int o = 0; o < 7 && ok; o += 3)
    {
      vector<int> non(10, 0);
      for (int i = o; i < o + 3; ++i)
        for (int j = o; j < o + 3; ++j)
          non[user[i][j]]++;
      for (int i = 1; i < 10; ++i)
        if (non[i] != 1)
          ok = false;
    }

    ans.push_back(ok);
  }

  for (int i = 0; i < Q; ++i)
    printf((ans[i]) ? "Y" : "N");

  return 0;
}
