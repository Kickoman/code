typedef vector<int> bigInteger;

bigInteger delZeros(bigInteger x)
{
    while (x.size() > 1 && x.back() == 0)
        x.pop_back();
    return x;
}

bigInteger getBig()
{
    bigInteger res;
    string s;
    cin >> s;
    for (int i = s.size() - 1; i > -1; --i)
        res.push_back(s[i] - '0');
    return res;
}

inline void putBig(bigInteger x)
{
    for (int i = x.size() - 1; i > -1; --i)
        printf("%d", x[i]);
    return;
}

bigInteger iToBig(int x) // int to BigInteger
{
    bigInteger res;
    for (; x; x /= 10)
        res.push_back(x % 10);
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
/**
  * compig(a, b) ==
  *                  -1 - (a < b)
  *                   0 - (a = b)
  *                   1 - (a > b)
**/
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

bigInteger multiBig(bigInteger a, bigInteger b)
{
    bigInteger res(a.size()+b.size());
    for (size_t i = 0; i < a.size(); ++i)
        for (int j = 0, carry = 0; j < (int) b.size() || carry; ++j) {
            long long cur = res[i + j] + a[i] * 1ll * (j < (int) b.size() ? b[j] : 0) + carry;
            res[i+j] = int (cur % 10);
            carry = int (cur / 10);
        }
    while (res.size() > 1 && res.back() == 0)
            res.pop_back();
    return res;
}

bigInteger subBig(bigInteger a, bigInteger b)
{
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