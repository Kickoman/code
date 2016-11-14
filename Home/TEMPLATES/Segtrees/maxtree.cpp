const int INF = int(1e9);

class maxtree
{
private:
    int n;
    vector<int> t;
public:
    void build(vector<int> &v)
    {
        for (int i = n; i < 2 * n; ++i)
            t[i] = v[i - n];
        for (int i = n - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int pos, int value)
    {
        for (t[pos += n] = value; pos > 1; pos >>= 1)
            t[pos >> 1] = max(t[pos], t[pos ^ 1]);
    }

    void add(int pos, int value)
    {
        for (t[pos += n] += value; pos > 1; pos >>= 1)
            t[pos >> 1] = max(t[pos], t[pos ^ 1]);
    }

    int query(int l, int r) // Interval [l, r)
    {
        int res = -INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(res, t[--r]);
        }
        return res; // viartańnie -INF značyć, što ničoha nie bylo znojdziena 
    }               // u vypadku, kali masiŭ nie źmiaščaje eliementaŭ roŭnych -INF

    maxtree(vector<int> &v)
    {
        n = v.size();
        t.resize(n << 1, -INF);
        build(v);
    }
};
