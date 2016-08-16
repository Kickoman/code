/**
  *     gównokod by candelabra
***/

#include <iostream>
#include <cstdio>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pob pop_back

using namespace std;

#ifdef LOCAL
    #define TASK "task"
    #define debug(...) printf(__VA_ARGS__)
#else
    #define TASK "lel"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

int main()
{
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#else
  //  freopen(TASK ".dat", "r", stdin);
   // freopen(TASK ".sol", "w", stdout);
#endif
	int n, m, y0, y1;
    return 0;
	scanf("%d %d %d %d",&n, &m, &y0, &y1);
	vector<int> a(n + 2);

	for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> b(m + 2);
	for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
	int k = 0,
	    j = 0,
	    last = -1;
	for (int i = 0; i < n; ++i)
	{
		while (j < m && abs(a[i] - b[j + 1]) < abs(a[i] - b[j]))
            ++j;
		if (last < j || abs(a[i - 1] - b[j]) == abs(a[i] - b[j]))
            ++k,
            last = j;
        else
            if (j < m && abs(a[i] - b[j + 1]) == abs(a[i] - b[j]))
                ++k,
                last = ++j;
            else last = j;
	}
	printf("%d\n", n-k);
	return 0;
    return 0;
}
