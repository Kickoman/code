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

char a[10001][10001];
string s;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> s;
    int k=0;
    for (int j=0; j<m; j++)
        for (int i=0; i<n; i++)
        {
           a[i][j]=s[k];
           k++;
        }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << a[i][j];
    }
    return 0;
}
