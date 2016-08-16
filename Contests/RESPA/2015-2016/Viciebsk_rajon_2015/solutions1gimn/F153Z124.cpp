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

int a[1000100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    long long s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % n == 0) {
        cout << "YES" << endl;
        long long x = s / n;
        long long ans = 0;
        sort(a, a + n);
        for (int i = 0; i < n && a[i] < x; i++)
            ans += (x - a[i]);
        cout << ans << endl;
    }
    else {
        cout << "NO" << endl;
        long long x = n - s % n;
        cout << x << endl;
    }
    return 0;
}
