#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    vector < pair <int, int> > l;
    vector <int> a, b, no, ans;
    int n, m;
    cin >> n >> m;
    for (int  i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        l.push_back(make_pair(c, i));
    }
    int maxi = 0;
    int nom = 0;
    sort(l.begin(), l.end());

    for (int j = 0; j < m; j++)
    {
        a.push_back(l[j].first);
        b.push_back(l[j].first);
        no.push_back(j);
    }
    for (int  i = 1; i < n; i++)
    {
        for (int j = i - 1; j < m; j++)
        {
            b[j] = a[j];
            a[j] = -1;
            for (int x = i - 1; x < j; x++)
            {
                int mini = min(l[j].first - l[x].first, b[x]);
                if (mini > a[j])
                {
                    a[j] = mini;
                    no[j] = x;
                }
                if (i == n-1)
                    if (maxi <= a[j])
                    {
                        maxi = a[j];
                        nom = j;
                    }
            }
        }
    }
    int t = nom;
    int kk = 1;
    while (kk <= n)
    {
        ans.push_back(l[t].second);
        t = no[nom];
        nom = t;
        kk++;
    }
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] + 1 << " ";
    return 0;
}
