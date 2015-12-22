#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


int v[1100];
int main()
{
   // freopen("task.in", "r", stdin);
   // freopen("task.out", "w", stdout);
    int n, a,b;
    cin >> a >> b;
    cin >> n;
    int x = 10000000, y;
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
        if (abs(v[i]-b)<x)
        {
           x = abs(v[i]-b);
           y = v[i];
        }
    }
    int ans = min(abs(y-b)+1,abs(a-b));
    cout << ans << endl;
    return 0;
}
