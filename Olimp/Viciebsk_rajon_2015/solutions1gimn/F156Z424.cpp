#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<deque>

using namespace std;

vector <int> x;
int n, m;
pair <int, int> a[100010];

void bi(int l, int r)
{
    if (x.size() >= n || l >= r - 1) return;
if ((n - x.size())% 2 == 1){
    int no = 0, mami = 0;
    for (int i = l + 1; i < r; i++)
    {
        int o = min(a[i].first - a[l].first, a[r].first - a[i].first);
        if (o > mami)
        {
            mami = o;
            no = i;
        }
    }
    x.push_back(no);
    bi(l, no);
    bi(no, r);
    return;
}
    int no = 0, noo = 0, mami = 0;
    for (int i = l + 1; i < r; i++)
        for (int j = i + 1; j < r; j++)
    {
        int o = min(a[i].first - a[l].first, a[j].first - a[i].first);
        int oo = min(a[j].first - a[i].first, a[r].first - a[j].first);
        o = min(o, oo);
        if (o > mami)
        {
            mami = o;
            no = i;
            noo = j;
        }
    }
    x.push_back(no);
    x.push_back(noo);
    bi(l, no);
    bi(no, noo);
    bi(noo, r);
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + m);
    x.push_back(0);
    x.push_back(m - 1);
    bi(0, m - 1);
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
        cout << a[x[i]].second << ' ';
    return 0;
}
