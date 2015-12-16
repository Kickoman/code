#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

string s;
int main()
{
    ios_base::sync_with_stdio();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    cin >> s;
    int k = 0;
    vector < string> ans(n);
    for (int j=0; j<m; j++)
        for(int i=0; i<n; i++)
        {
             ans[i]+=s[k];
             k++;
        }
    for (int i=0; i<n; i++)
        for (int j=0; j<ans[i].size(); j++)
            cout << ans[i][j];
return 0;
}
