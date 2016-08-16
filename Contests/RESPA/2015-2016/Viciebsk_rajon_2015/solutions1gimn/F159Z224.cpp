#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define DEBUGs

using namespace std;

const int INF = (int) 1e9;
const int SWAG =  228;
const long long INFll = (long long) 1e18;

int main()
{
//    ios_base::sync_with_stdio(0);
#ifdef DEBUGs
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...)
    #define cerr if(0)cerr
#endif // DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d %d\n", &n, &m);
    string s;
    getline(cin, s);
    int x = 0;
    for (int i = 0; i < n * m; ++i)
    {
        printf("%c", s[x]);
        x += n;
        if (x >= n * m)
            x = (x % (n * m)) + 1;
    }
    return 0;
}
