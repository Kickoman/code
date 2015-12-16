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
string s;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<n;i++)
    {
       int j=i;
       while (j<(n*m)){
        cout<<s[j];j+=n;}
    }
}
