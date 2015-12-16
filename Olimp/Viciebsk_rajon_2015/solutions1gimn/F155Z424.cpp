#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;

bool used[100010];
vector <pair<ll, int> > a;
vector <pair<int, int> > ans;
vector <pair<ll, pair<int, int> > > g[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        ll x;
        cin >> x;
        a.pb(mp(x, i));
    }
    sort(a.begin(), a.end());
    if (n == m)
    {
        for (int i = 0; i < m; i++)
            cout << a[i].S + 1 << ' ';
        return 0;
    }
    if (n == 1)
    {
        cout << a[m - 1].S + 1;
        return 0;
    }
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            g[i].pb(mp(a[j].F - a[i].F, mp(a[i].S, a[j].S)));
    ans.pb(mp(a[m - 1].S, m - 1));
    used[m - 1] = true;
  //  return 0;
    for (int i = n - 1; i > 0; i--)
    {
        cout << i << ' ';
        if (i == n -2) break;
                ll f = -1;
                int no1, no2;
                for (int j = m - 2; j  > - 1 ; j--)
                if (j >= i - 1){ cout << "* "<<endl; //<< g[ans.back().S][j].F << endl;
                    if (!used[j] && g[ans[ans.size() - 1].S][j].F > f) f = g[ans[ans.size() - 1].S][j].F, no1 = j, no2= g[ans[ans.size() - 1].S][j].S.S;}
                used[no1] = true;
                ans.pb(mp(no2 ,no1));
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].F + 1 << ' ';
    return 0;
}
