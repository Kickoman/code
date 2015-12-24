#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
unsigned long long ans;
long long x[101000], y[101100];
int main()
{
   freopen("points.dat", "r", stdin);
   freopen("points.sol", "w", stdout);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i=1; i<=n; i++)
    {
        sum1 += x[i-1];
        sum2 += x[i-1]*x[i-1];
        sum3 += y[i-1];
        sum4 += y[i-1]*y[i-1];
        ans += ((i-1)*x[i]*x[i]-2*x[i]*sum1+sum2);
        ans += ((i-1)*y[i]*y[i]-2*y[i]*sum3+sum4);
    }
    cout << ans << endl;
    return 0;
}
