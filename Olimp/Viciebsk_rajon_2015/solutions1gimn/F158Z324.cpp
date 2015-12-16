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

int a[2001][2001], f[2001][2001];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,fl=0;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
           cin >> a[i][j];
           if (a[i][j]==1) fl=1;
        }
    for (int i=1; i<n; i++)
        {
            f[i][0]=1;
            if (a[i][0]==1) f[i][0]=0;
        }
    for (int j=0; j<m; j++)
    {
        f[0][j]=1;
        if (a[0][j]==1) f[0][j]=0;

    }
    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
        if (a[i][j]==1)
        f[i][j]=0;
        else
        if (f[i][j-1]!=f[i-1][j])
                f[i][j]=min(f[i-1][j],f[i][j-1])+1;
        else
        {
            int fl=0;
            if (i>j)
            {
                int jj=0;
                for (int ii=abs(i-j); ii<=i && ii!=i && jj!=j; ii++)
                    for (int jj=0; jj<=j && ii!=i && jj!=j; jj++)
                    if (f[ii][jj]==0) fl=1;
            }
            if (i<j)
            {
                int jj=0;
                for (int ii=0; ii<=i && ii!=i && jj!=j; ii++)
                    for (jj=abs(i-j); jj<=j && ii!=i && jj!=j; jj++)
                    if (f[ii][jj]==0)
                    {
                        fl=1;
                    }
            }
            if (i==j)
            {
                int jj=0;
                for (int ii=0; ii<=i && ii!=i && jj!=j; ii++)
                    for (int jj=0; jj<=j && ii!=i && jj!=j; jj++)
                    if (f[ii][jj]==0)
                    {
                        fl=1;
                    }
            }
            if (f[i-1][j]==f[i][j-1]&& fl==0)
                f[i][j]=f[i-1][j]+1;
            else if (fl==1 && f[i-1][j]==f[i][j-1])
                    f[i][j]=min(f[i-1][j],f[i][j-1]);
        }
    long long s=0;
    for (int i=0; i<n; i++)
      {
          for (int j=0; j<m; j++)
            s+=f[i][j];
      }
    cout << s;
    return 0;
}
