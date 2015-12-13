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
pair <int,int> a[150000];
vector <pair<int,int > > b[150000];
pair <int,int> sr;
vector <int> d;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n;
    cin>>m>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].first;a[i].second=i;}
        a[n].first=0;
       a[n].second=n;
    sort(a,a+n+1);
    n++;
    for (int i=0;i<n;i++)
        b[i].push_back(make_pair(a[n-1].first-a[i].first,n-1));


    for (int i=1;i<m;i++)
     {
        for (int j=n-i-2;j>-1;j--) {sr.first=0;sr.second=0;
           for (int kk=j+1;kk<n-i;kk++) {
                int v=sr.first;
            sr.first=max(sr.first,min(a[kk].first-a[j].first,b[kk][i-1].first));
       if (sr.first!=v) sr.second=kk;

            }
            b[j].push_back(make_pair(sr.first,sr.second));

        }
     }


     int l=m-1;int r=0;
     while (l>-1)
     {
         d.push_back(a[b[r][l].second].second);
         r=b[r][l].second;
         l--;
     }
     for (int i=0;i<d.size();i++)
        cout<<d[i]+1<<' ';

 }
