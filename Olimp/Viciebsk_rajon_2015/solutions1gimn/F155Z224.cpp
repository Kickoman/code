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

vector <pair<pair<int, int>, char> > g;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int stl = 0, str = 0;
    for (int ii = 0; ii < s.size(); ii++)
    {
        g.pb(mp(mp(str, stl), s[ii]));
        str++;
        if (str == n)
            str = 0, stl++;
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < n * m; i++)
        cout << g[i].S;
    return 0;
}
