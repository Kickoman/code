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
    int n;
    cin >> n;
    int a[n+100];
    unsigned long long sum = 0;
    int maxi = 0;
    for (int  i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        maxi = max(a[i], maxi);
    }
    int ans = 0;
    if (sum % n == 0)
    {
        cout << "YES" << endl;
        int p = sum;
        p /= n;
        for (int i = 0; i < n; ++i)
            if (a[i] > p)
                ans += (a[i] - p);
        cout << ans;
    }
    else
    {
        cout << "NO" << endl;
        for (int i = 0; i < n; ++i)
            ans += (maxi - a[i]);
        cout << ans;
    }
    return 0;
}
