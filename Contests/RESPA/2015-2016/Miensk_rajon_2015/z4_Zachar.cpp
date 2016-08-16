#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include <cstring>
#include <unordered_map>
#include <set>

using namespace std;

bool f[11010];

void prec()
{
  memset(f, 0, sizeof f);
  for(int i = 9998; i >= 0; i--)
  {
    int g = 10;
    bool ok = false;

    for(int it = 0; it < 4; it++)
    {
      for(int j = 1; j <= 3; j++)
      {
        if(i % g / (g / 10) + j < 10)
          ok = ok || (f[i + j * g / 10]);

      }
      g *= 10;
    }
    f[i] = !ok;
  }
}

int main()
{
  prec();
  int n;
  scanf("%d", &n);
  while(n--)
  {
    int q;
    scanf("%d", &q);
    printf(f[q] ? "Y" : "N");
  }
  return 0;
}
