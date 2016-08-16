#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector <int > ans,p;
int z,m,n;
vector <pair <int, int> > a;
void dfs(int v, int k)
{
    if (k>z)
        exit;
    p.push_back(v);
    if (p.size() == m)
    {
        if (k>z)
        {
            z = k;
            ans.resize(0);
            for (int i=0; i<p.size(); i++)
                ans.push_back(a[p[i]].second);
        }
        exit;
    }
    for (int i=v+1;i<n; i++)
    {
        dfs(i,min(k,a[i].first-a[v].first));
        p.resize(p.size()-1);
    }
}
int main()
{
    ios_base::sync_with_stdio();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> m >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end());
    if (n == m)
    {
        for (int i=0; i<a.size(); i++)
            cout << a[i].second+1 << " ";
        return 0;
    }
    if (m == 1)
    {
        cout << a[n-1].second+1<< endl;
        return 0;
    }
    for (int i=0; i<n; i++)
    {
        dfs(i,a[i].first);
        p.resize(0);
    }
    for (int i=0; i<ans.size(); i++)
        cout << ans[i]+1 << " ";
return 0;
}
