#include <iostream>
#include <cstdio>
#include <vector>

// TODO(Kastus#2): skonczy pracu
/*
    dadaj kanczatkova admounyja liki
    zastalosia dla subBiga dadac i dalej
*/


using namespace std;

struct bigInteger
{
    vector<int> E;
    bool N;
};

bigInteger delZeros(bigInteger x)
{
    while (x.E.size() > 1 && x.E.back() == 0)
        x.E.pop_back();
    return x;
}

bigInteger getBig()
{
    bigInteger res;
    string s;
    cin >> s;
    res.N = (s[0] == '-');
    for (int i = s.size() - 1; i > -1; --i)
        if (s[i] >= '0' && s[i] <= '9')
            res.E.push_back(s[i] - '0');
    return res;
}

inline void putBig(bigInteger x)
{
    if (x.N)
        printf("-");
    for (int i = x.E.size() - 1; i > -1; --i)
        printf("%d", x.E[i]);
    return;
}

int compBig(bigInteger a, bigInteger b)
{
/**
  * compig(a, b) ==
  *                  -1 - (a < b)
  *                   0 - (a = b)
  *                   1 - (a > b)
**/
    if (a.N != b.N)
        return (a.N ? -1 : 1);

    int res = -2;
    if (a.E.size() != b.E.size())
        res = (a.E.size() > b.E.size() ? 1 : -1);
    else
    {
        for (int i = a.E.size() - 1; i > -1; --i)
            if (a.E[i] != b.E[i])
                res = (a.E[i] > b.E[i] ? 1 : -1);
        res = (res == -2 ? 0 : res);
    }
    return (a.N ? res * -1 : res);
}

bigInteger sumBig(bigInteger a, bigInteger b)
{
    if (a.N != b.N) // Kali adno z likaw admownaje, viartajem jichniuju roznasc
    {
        if (compBig(a, b) == -1)
            swap(a, b);
        b.N = false;
        return subBig(a, b);
    }

    int lng = max(a.E.size(), b.E.size());
    while (a.E.size() < lng)
        a.E.push_back(0);
    while (b.E.size() < lng)
        b.E.push_back(0);

    int cur = 0;
    bigInteger res; // Inicyjalizacja adkazu
    res.E.resize(lng);
    for (int i = 0; i < lng; ++i)
    {
        int tmp = 0;
        tmp = a.E[i] + b.E[i] + cur;
        cur = tmp / 10;
        tmp %= 10;
        res.E[i] = tmp;
    }
    res.N = a.N;
    if (cur > 0)
        res.E.push_back(cur);
    return res;
}

bigInteger multiBig(bigInteger a, bigInteger b)
{
    bigInteger res;
    res.E.resize(a.E.size() + b.E.size());
    for (size_t i = 0; i < a.E.size(); ++i)
        for (int j = 0, carry = 0; j < (int) b.E.size() || carry; ++j) {
            long long cur = res.E[i + j] + a.E[i] * 1ll
                            * (j < (int) b.E.size() ? b.E[j] : 0) + carry;
            res.E[i+j] = int (cur % 10);
            carry = int (cur / 10);
        }
    while (res.E.size() > 1 && res.E.back() == 0)
            res.E.pop_back();
    res.N = (a.N != b.N);
    return res;
}

bigInteger subBig(bigInteger a, bigInteger b)
{
    if (a.N != b.N)
    {
        if (compBig(a, b) == -1)
            swap(a, b);
        b.N = false;
        return sumBig(a, b);
    }

    bigInteger res(max(a.size(), b.size()), 0);
    int lng = max(a.size(), b.size());
    while (a.size() < lng)
        a.push_back(0);
    while (b.size() < lng)
        b.push_back(0);
    if (compBig(a, b) == -1)
        swap(a, b);
    if (compBig(a, b) == 0)
        return delZeros(res);
    int cur = 0;
    for (int i = 0; i < lng; ++i)
    {
        int tmp = 0;
        a[i] -= cur;
        cur = 0;
        if (a[i] < b[i])
            cur++,
            a[i] += 10;
        res[i] = a[i] - b[i];
    }
    return delZeros(res);
}

bigInteger bigPow(bigInteger a, int b)
{
    bigInteger res(1, 1);
    for (int i = 0; i < b; ++i)
        res = multiBig(res, a);
    return res;
}

int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    bigInteger a, b;
//    int b;
    a = getBig();
    b = getBig();
//    scanf("%d", &b);
    putBig(subBig(a, b));
    return 0;
}
