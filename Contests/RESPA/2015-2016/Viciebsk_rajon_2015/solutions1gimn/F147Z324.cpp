#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int a[2100][2100];

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                ans++;
        }
    int f = 1;
    while (f + 1 <= n && f + 1 <= m)
    {
        f++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != 1)
                    if (i + f <= n)
                        if (j+f <= m)
                        {
                            int p = 0;
                            for (int x = i; x < i + f; x++)
                            {
                                if (p == 1)
                                    break;
                                for (int y = j; y < j + f; y++)
                                {
                                    if (a[x][y] == 1)
                                    {
                                        p = 1;
                                        break;
                                    }
                                }
                            }
                            if (p != 1)
                                ans++;
                        }
            }
    }
    cout << ans;
    return 0;
}
