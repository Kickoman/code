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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
    long long s = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
        m = max(m, a[i]);
    }
    long long r = 0;
    if (s % n == 0)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (a[i] - (s / n) > 0) r += (a[i] - (s / n));
        cout << r;
        return 0;
    }
    cout << "NO" << endl;
    for (int i = 0; i < n; i++)
        r += (m - a[i]);
    cout << r;
    return 0;
}
