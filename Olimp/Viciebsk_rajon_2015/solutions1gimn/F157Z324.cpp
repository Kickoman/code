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
int a[2100][2100],f[2100][2100];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    long long s=0;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        cin>>a[i][j];
    for (int i=0;i<n;i++)
    if (a[i][0]==0) f[i][0]=1;else f[i][0]=0;
    for (int i=0;i<m;i++)
        if (a[0][i]==0) f[0][i]=1;else f[i][0]=0;
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
        if (a[i][j]==1) f[i][j]=0;
    else f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i][j-1]))+1;
   for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            s+=f[i][j];cout<<s<<endl;
}
