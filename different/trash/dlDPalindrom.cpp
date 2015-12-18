#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <cmath>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

#ifdef LOCAL
    #define TASK "task"
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...)
    #define cerr if(0)cerr
    #define TASK "D"
#endif // LOCAL

typedef vector<int> bigInteger;


bigInteger getBig()
{
    bigInteger res;
    string s;
    char c = 'l';
    while ((c = getchar()) && c >= '0' && c <= '9')
        s += c;
//    cin >> s;
    for (int i = s.size() - 1; i > -1; --i)
        res.push_back(s[i] - '0');
    return res;
}

bigInteger sumBig(bigInteger a, bigInteger b)
{
    int lng = max(a.size(), b.size());
    while (a.size() < lng)
        a.push_back(0);
    while (b.size() < lng)
        b.push_back(0);

    int cur = 0;
    bigInteger res(lng);
    for (int i = 0; i < lng; ++i)
    {
        int tmp = 0;
        tmp = a[i] + b[i] + cur;
        cur = tmp / 10;
        tmp %= 10;
        res[i] = tmp;
    }
    if (cur > 0)
        res.push_back(cur);
    return res;
}

int compBig(bigInteger a, bigInteger b)
{
    int res = 0;
    if (a.size() != b.size())
        return (a.size() > b.size() ? 1 : -1);
    else
    {
        for (int i = a.size() - 1; i > -1; --i)
            if (a[i] != b[i])
                return (a[i] > b[i] ? 1 : -1);
        return 0;
    }
}

inline void putBig(bigInteger &x)
{
    for (int i = x.size() - 1; i > -1; --i)
        printf("%d", x[i]);
    return;
}


int main()
{
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    bigInteger n = getBig();
    {
        bigInteger tmp(1, 1);
        n = sumBig(n, tmp);
    }
    int main_lng = n.size();
    for (int i = 0; i < main_lng / 2;)
    {
        if (main_lng / 2 == i)
            break;
        if (n[i] == n[main_lng - 1 - i])
        {
            ++i;
            continue;
        }
        int backup = n[i];
        n[i] = n[main_lng - 1 - i];
        if (backup > n[i])
        {
            int carry = 1;
            int lng = main_lng;
            for (int j = i + 1; j < lng; ++j)
            {
                int tmp = 0;
                tmp = n[j] + carry;
                carry = tmp / 10;
                tmp %= 10;
                n[j] = tmp;
                if (!carry)
                    break;
            }
            continue;
        }
        ++i;

    }
    putBig(n);
    return 0;
}
