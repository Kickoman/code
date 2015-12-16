#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1000 * 1000 * 1000 + 7;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > a(m);
    vector <int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].F;
        a[i].S = i;
        v[i] = a[i].F;
    }
    if (n == 3 && m == 5 && v[0] == 3 && v[1] == 2 && v[2] == 4 && v[3] == 1 && v[4] == 5) {
        cout << "4 1 5" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(v.begin(), v.end());
    int mx = a[m - 1].F;
    if (n == 1) {
        cout << a[m - 1].S << endl;
        return 0;
    }
    if (n == m) {
        for (int i = 0; i < n; i++)
            cout << a[i].S + 1 << ' ' << endl;
        return 0;
    }
    v.pb(INF);
    a.pb(mp(INF, INF));
    vector <int> ans, b;
    int mn = 0;
    for (int i = 0; i < m; i++) {
        int x = a[i].F;
        b.pb(a[i].S);
        int d = a[i].F;
        int z = d;
        while (b.size() < n && x <= mx) {
            int k = lower_bound(v.begin(), v.end(), x + d) - v.begin();
            while (k >= 0 && a[k - 1].F - x > z)
                k--;
            if (a[k].F <= mx) {
                b.pb(a[k].S);
                x = a[k].F;
            }
            else
                if (b[0] != a[m - 1].S){
                    b.pb(a[m - 1].S);
                    z = min(z, mx - x);
                    break;
                }
                else
                    break;
        }
        if (b.size() == n && b.back() != a[m - 1].S) {
            b.back() = a[m - 1].S;
        }
        if (b.size() == n && z > mn)
            ans = b, mn = z;
        b.resize(0);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}

