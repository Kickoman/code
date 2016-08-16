#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int a[2000000];
long long s;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];s+=a[i];}
int ans=0;
    if (s % n == 0) cout<<"YES"<<endl;
    else {cout<<"NO"<<endl;int r=s/n;r++;
    cout<<r*n-s<<endl;return 0;}
     int r=s/n;
     for (int i=0;i<n;i++)
        if (a[i]<r) ans+=r-a[i];
        cout<<ans<<endl;
}
