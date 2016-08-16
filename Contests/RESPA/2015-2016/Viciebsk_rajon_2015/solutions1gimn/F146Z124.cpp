
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);

    int n;
    scanf("%d", &n);
    int a[n];
    long long s = 0;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s += a[i];
        if (a[i]!=a[i-1] && i!=0)
        {
            f = 1;
        }
    }
    if (f==0)
    {
        cout << "YES" << endl;
        cout << 0 <<endl;
    }
    else
    {
        if (s%n==0)
        {
            cout << "YES" <<endl;
            int k = s/n;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i]>k)
                {
                    ans += a[i]-k;
                }
            }
            cout << ans <<endl;
        }
        else
        {
            int k = s/n;
            k*=n;
            cout << "NO" <<endl;
            cout << n - (s - k) << endl;
        }
    }


    return 0;
}
