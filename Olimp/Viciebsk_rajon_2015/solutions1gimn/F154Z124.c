#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector <int> a;
long long sum;
int main()
{
    ios_base::sync_with_stdio();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        sum+=x;
        a.push_back(x);
    }
    int kl  = 0;
    if (sum%n == 0)
    {
      cout << "YES" << endl;
      int d = sum/n;
      for (int i=0; i<a.size(); i++)
        if (a[i]<d)
            kl+=(d-a[i]);
      cout << kl << endl;
    }
    else
    {
        cout << "NO" << endl;
        kl = n*(sum/n+1) - sum;
        cout << kl << endl;
    }
return 0;
}
