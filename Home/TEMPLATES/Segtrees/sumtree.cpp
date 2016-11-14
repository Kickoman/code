class sumtree
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
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void modify(int pos, int value)
    {
        for (t[pos += n] = value; pos > 1; pos >>= 1)
            t[pos >> 1] = t[pos] + t[pos ^ 1];
    }

    void add(int pos, int value)
    {
        for (t[pos += n] += value; pos > 1; pos >>= 1)
            t[pos >> 1] += value;
    }

    int query(int l, int r) // Interval [l, r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }

    sumtree(vector<int> &v)
    {
        n = v.size();
        t.resize(n << 1, 0);
        build(v);
    }
};
