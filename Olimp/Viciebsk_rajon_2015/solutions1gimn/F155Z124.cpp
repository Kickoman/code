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

int a[1000010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    ll s = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];s += a[i]; }
    if (s % n == 0){
        cout << "YES" << endl;
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > (s / n)) ans += (a[i] - (s / n));
        cout << ans << endl;
        return 0;
    }
    cout << "NO" << endl;
    cout << n - (s % n) << endl;
    return 0;
}
