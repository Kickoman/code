#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

char a[100110];

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int  n, m;
    char c;
    int  k = 0;
    cin >> n >> m;
    while (cin >>c)
    {
        a[k] = c;
        k++;
    }
    k--;
    string ans;
    for (int i = 0; i < n; i++)
    {
        int f = i;
        for (int  j = 0; j < m; j++)
        {
            ans += a[f];
            f+= n;
            if (f > k)
                break;
        }
    }
    cout << ans;
    return 0;
}
