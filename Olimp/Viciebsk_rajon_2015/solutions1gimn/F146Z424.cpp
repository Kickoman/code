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

const int INF=1000000000;

int main()
{
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);

    int n , m;
    scanf("%d%d", &n, &m);
    vector < pair < int , int > > a(m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    int k = n-2;

    sort(a.begin() , a.end());
    if ( m==n){
        for (int i = 0; i < n; i++){
            cout << a[i].second<<" ";
        }
        cout<<endl;
        return 0;
    }

    vector < int > ans(n , 0) , s(n , INF) , r(n , 0);
    ///
    s[0] = a[0].first;
    ans[0] = a[0].second;
    s[n - 1] = a[m - 1].first;
    ans[n - 1] = a[m - 1].second;

    for (int i = 1; i < m - 1; i++)
    {
        int cur = a[i].first;
        int pos = a[i].second;
        bool f = false;
        if (k == 0)
        {
            for (int j = 1 ; j < n - 1 ; j++)
            {
                if ( cur > s[j - 1] && cur < s[j + 1])
                {
                    if ( min( cur - s[j - 1] , s[j + 1] - cur ) > r[j] )
                    {
                        r[j] = min( cur - s[j - 1] , s[j + 1] - cur );
                        f = true;
                        s[j] = cur;
                        ans[j] = pos;
                    }
                }
                if (f) break;
            }
        }
        else
        {
            for (int j = 1; j < n-1; j++)
            {
                if (ans[j] == 0)
                {
                    k--;
                    s[j] = cur;
                    ans[j] = pos;
                    if (s[j + 1] > 0  &&  s[j - 1] > 0)
                    {
                        r[j] = min(cur - s[j - 1] , s[j + 1] - cur);
                    }
                    if (k == 0)
                    {
                        for (int j = 1; j < n - 1; j++)
                        {
                            r[j] = min(cur - s[j - 1],s[j + 1] - cur);
                        }
                    }
                    break;
                }
            }
        }
    }


    ///
    for (int i = 0; i < n; i++)
    {
        cout <<ans[i]<<" ";
    }
    cout << endl;

    return 0;
}

