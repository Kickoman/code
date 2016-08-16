#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define DEBUGs

using namespace std;

const int INF = (int) 1e9;
const int SWAG =  228;
const long long INFll = (long long) 1e18;

int main()
{
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...)
    #define cerr if(0)cerr
#endif // DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    long long sum = 0;
//    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    cerr << sum << " " << sum % n << endl;

    if (sum % ((long long) n) == 0)
    {
        printf("YES\n");
        long long k = 0;
        for (int i = 0; i < n; ++i)
            k += abs((sum / (long long) n) - a[i]);
        printf("%d\n", k / 2);
    }
    else
    {
        printf("NO\n");
        printf("%d\n", n - (sum % n));
    }

//    sort(a.begin(), a.end());

    return 0;
}
