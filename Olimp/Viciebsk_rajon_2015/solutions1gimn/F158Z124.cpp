#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int a[1000000];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    long long s=0;
    for (int i=0; i<n; i++)
       {
          cin >> a[i];
          s+=a[i];
       }
    if (s % n != 0 )
    {
        cout << "NO" << endl;
        for (long long i=s; i<10000; i++)
            if (i % n==0)
        {
            cout << i-s;
            return 0;
        }
    }
    else
    {
        cout << "YES" << endl;
        long long ans=s / n,k=0;
        for (int i=0; i<n; i++)
        {
            if (a[i]<ans)
                k+=ans-a[i];
        }
        cout << k;
    }
    return 0;
}
