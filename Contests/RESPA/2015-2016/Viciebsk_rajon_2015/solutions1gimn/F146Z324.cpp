#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);


    int n,m;

    scanf("%d%d", &n, &m);
    long long ans = 0;

    int a[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j =0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                a[i][j] = 0;
            }
            else
            {
                cin >> a[i][j];
            }
            if (i!=0 && j!=0)
            {
                if (a[i][j] == 1)
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = a[i][j - 1] + 1;
                }

                a[i][j]=min( a[i][j] , a[i - 1][j - 1] + 1 );
                a[i][j]=min( a[i][j] , min( a[i - 1][j] + 1 , a[i][j - 1] + 1 ) );

                ans +=a[i][j];
            }
        }
    }

    cout << ans <<endl;


    return 0;
}
