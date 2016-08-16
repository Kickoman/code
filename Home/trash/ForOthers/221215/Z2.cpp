#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string >
#include <algorithm>
using namespace std;
int n, kl;
vector <int > ans;
int g[1000][1000], k[1000][1000];
int used[1000];
void dfs (int v, int p)
{
   used[v] = 1;
    for (int i=0; i<n; i++)
        if (g[v][i] == 1 && used[i] == 0)
        {
            g[v][i]=0;
            g[i][v]=0;
            dfs(i,v);
        }
  if (v!=0)
   ans.push_back(k[v][p]);
  if (ans.size()==1)
      ans.push_back(k[0][v]);
   //cout << v << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   cin >> n >> kl;
   for (int i=0; i<n*kl; i++)
   {
       int x, y;
       cin >> x >> y;
       x--;
       y--;
       g[x][y] = 1;
       g[y][x] = 1;
       k[x][y] = i;
       k[y][x] = i;
   }
   dfs(0,0);
   if (ans.size() != (n))
       cout <<"NO" << endl;
    else
    {
    cout << "YES" << endl;
   for (int i=0; i<ans.size();i++)
    cout << ans[i]+1 << endl;
   }
    return 0;
}


