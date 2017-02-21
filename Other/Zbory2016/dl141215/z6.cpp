#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

#ifdef LOCAL
    #define TASK "task"
    #define debug(...) printf(__VA_ARGS__)
#else
    #define TASK "table"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

int main()
{
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, l, k;
    scanf("%d %d %d", &n, &l, &k);
    vector<pair<int, int> > a(k);
    for (int i = 0; i < k; ++i)
        scanf("%d %d", &a[i].F, &a[i].S);
    vector<int> table(n, -1);
    vector<bool> was(n + 2);
    for (int i = 0, u = 0, p = 0; i < n; ++i)
        if (u < k)
        {
            if (table[i] == -1)
            {
                table[i] = a[u].F;
                int j = i;
                while (table[(j + l) % n] != -1 && j < n)
                    j = (j + 1) % n;
                if (table[(j + l) % n] != -1)
                {
                    printf("-1\n");
                    return 0;
                }
//                was.insert(a[u].F);
//                was.insert(a[u].S);
                was[a[u].F] = true;
                was[a[u].S] = true;
                table[(j + l) % n] = a[u++].S;
                cerr << (i < n) << endl;
                p += 2;
            }
        }
        else
        {
            cerr << "chlen" << endl;
            for (int j = 0; j < n; ++j)
                if (table[j] != -1)
                {
//                    cerr << "lel" << endl;
                    continue;
                }
                else
                {
                    cerr << "lel" << endl;
                    int x = 1;
                    while (was[x])
                        ++x;
                    table[j] = x;
//                    was.insert(x);
                    was[x] = true;
                    p++;
                }
            if (p < n)
            {
                printf("-1\n");
                return 0;
            }
        }
    for (int i = 0; i < table.size(); ++i)
        printf("%d ", table[i]);
    return 0;
}
