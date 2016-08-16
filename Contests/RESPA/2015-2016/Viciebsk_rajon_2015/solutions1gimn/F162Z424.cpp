#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back

const long long INF = 1000000000000000ll;
const long long I = 100000000ll;

vector<vector<pair<long long, int> > > dp, f;

pair<long long, int> a[100100];

vector<int> q;

int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (m <= 1000){
    for (int i=1; i<=m; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    dp.resize(m+3);
    a[0] = mp(0ll, 0);
    sort(a, a+m+1);
    int z = 1;
    while (z < n) z*= 2;
    for (int i=0; i<=m; i++)
        dp[i].resize(n+3);
    for (int i=0; i<=m; i++)
        dp[i][0] = mp(INF, i);
    dp[0][0].F = INF;
    for (int i=1; i<=m; i++)
        for (int k=1; k<=n; k++){
            if (k > i) break;
            for (int j=i-1; j>=0; j--){
                long long c = min(a[i].F - a[j].F, dp[j][k-1].F);
                if (c > dp[i][k].F){
                    dp[i][k] = mp(c, j);
                }
            }
        }
    pair<long long, int> ans = mp(0, 0);
    for (int i=1; i<=m; i++)
        if (ans.F <= dp[i][n].F){
            ans = mp(dp[i][n].F, i);
        }
    while (n > 0){
        q.pb(a[ans.S].S);
        ans.S = dp[ans.S][n].S;
        n--;
    }
    //cout << ans.F << endl;
    for (int i=q.size()-1; i>=0; i--)
        cout << q[i] << ' ';
    }
    else{
    for (int i=1; i<=m; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    dp.resize(m+3);
    f.resize(m+3);
    a[0] = mp(0ll, 0);
    sort(a, a+m+1);
    int z = 1;
    while (z < n) z*= 2;
    for (int i=0; i<=m; i++){
        dp[i].resize(n+3);
        f[i].resize(n+3);
    }
    for (int i=0; i<=m; i++)
        dp[i][0] = mp(INF, i);
    dp[0][0].F = INF;
    for (int i=0; i<=m; i++)
        for (int k=0; k<=n; k++){
            if (k > i) break;
            if (i > 0 && f[i][k].F < f[i-1][k].F) f[i][k] = f[i-1][k];
            if (f[i][k].F > dp[i][k].F){
                dp[i][k] = f[i][k];
            }
            int y = m+1;
            for (int j=i+1; j<=m; j++){
                if (a[j].F - a[i].F >= dp[i][k].F){
                    y = j;
                    break;
                }
                long long c = a[j].F - a[i].F;
                if (c > dp[j][k+1].F){
                    dp[j][k+1] = mp(c, i);
                }
            }
            if (y <= m && dp[i][k].F > f[y][k+1].F)
                f[y][k+1] = mp(dp[i][k].F, i);
        }
    pair<long long, int> ans = mp(0, 0);
    for (int i=1; i<=m; i++)
        if (ans.F <= dp[i][n].F){
            ans = mp(dp[i][n].F, i);
        }
    while (n > 0){
        q.pb(a[ans.S].S);
        ans.S = dp[ans.S][n].S;
        n--;
    }
    for (int i=q.size()-1; i>=0; i--)
        cout << q[i] << ' ';

    }
    return 0;
}



