#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

template<typename _response>
void logger(_response info, int type) // text, type of log
{
#ifdef LOCAL
    if (type == 1)
    {
        cerr << info << endl;
    } else if (type == 2) {
        cout << info << endl;
    } else {
        cerr << info << endl;
        cout << info << endl;
    }
#endif // LOCAL
}

template<typename _response>
void Error(_response errorcode)
{
    logger(errorcode, 3);
    exit(228);
}

template<typename _type>
class sqrtdec
{
private:
    int n;
    int len;
    vector<vector<_type>> source;
    vector<_type> blocks;
public:
    void build(vector<_type> &v)
    {
        n = int(v.size());

        len = int(sqrt(n)) + 1;
        blocks.resize(len);
        source.resize(len);

        for (int i = 0; i < n; ++i)
            blocks[i / len] = max(blocks[i / len], v[i]),
            source[i / len].push_back(v[i]);
    }

    void rebuild()
    {
        vector<_type> tmp;
        for (size_t i = 0; i < source.size(); ++i)
            for (size_t j = 0; j < source[i].size(); ++j)
                tmp.push_back(source[i][j]);

        source.clear();
        blocks.clear();

        build(tmp);
    }

    _type query(int l, int r)
    {
        // -INF bo sqrt-dekampazycyja pa max
        // -INF because it is max-sqrtdec
        int res = -INF;

        for (int i = l; i <= r;)
            if (i % len == 0 && i + len - 1 <= r)
            {
                res = max(res, blocks[i / len]);
                i += len;
            } else {
                if (i / len >= source.size()) Error("i / len is bigger than source.size()");
                if (i % len >= source[i / len].size()) Error("i \% len is bigger than source[i / len].size()");
                res = max(res, source[i / len][i % len]);
                ++i;
            }

        return res;
    }

    void modify(int pos, _type value)
    {
        int block = --pos / len;
        pos %= len;

/*
        TOĹKI DLIA SUM (i padobnych)
        ONLY FOR SUM
        blocks[block] += value - source[block][pos];
        source[block][pos] = value;
*/

        // dlia max/min:
        // for max/min:
        source[block][pos] = value;
        blocks[block] = -INF;
        for (size_t i = 0; i < source[block].size(); ++i)
            blocks[block] = max(blocks[block], source[block][i]);
    }

    void insert(vector<vector<_type>> &v, int block, int pos, _type value)
    {
        vector<_type> newblock;
        _type newmax = -INF;
        for (size_t i = 0; i < pos; ++i)
            newblock.push_back(v[block][i]),
            newmax = max(newmax, v[block][i]);

        newblock.push_back(value);
        newmax = max(newmax, value);

        for (size_t i = pos; i < v[block].size(); ++i)
            newblock.push_back(v[block][i]),
            newmax = max(newmax, v[block][i]);

        v[block] = newblock;
        blocks[block] = newmax;
    }

    void _add(int value, int cnt)
    {
        int block = len - 1;

        while (block > 0 && blocks[block] < value && source[block].size() <= cnt)
            cnt -= source[block].size(),
            --block;

        // my majem block dy reštu cnt;

        int newpos = source[block].size();

        while (newpos > 0 && source[block][newpos - 1] < value && cnt)
            --cnt,
            --newpos;

        insert(source, block, newpos, value);
    }

    vector<vector<_type>> get_source()
    {
        return source;
    }

    vector<_type> get_blocks()
    {
        return blocks;
    }

    int block_size(int block_number)
    {
        return (int) source[block_number].size();
    }

    int size()
    {
        return len;
    }

    sqrtdec()
    {}

    sqrtdec(vector<_type> &v)
    {
        build(v);
    }
};

int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);


    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    sqrtdec<int> dec(a);

    dec.rebuild();

    dec.modify(3, 18);
    dec.modify(5, -4);

    auto tmp = dec.get_blocks();
    printf("SIZE: %d\n", (int) tmp.size());
    for (auto x: tmp)
        printf("%d\n", x);

    auto tmp2 = dec.get_source();

    printf("\nSOURCE:\n");
    for (int i = 0; i < int(tmp2.size()); ++i)
    {
        printf("Source[%d]: ", i);
        for (int j = 0; j < int(tmp2[i].size()); ++j)
            printf("%d ", tmp2[i][j]);
        printf("\n");
    }


    return 0; // ############# RETURN #########
    int m;
    scanf("%d", &m);

    while (m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        printf("max[%d; %d] = %d\n", l + 1, r + 1, dec.query(l, r));
    }
    return 0;
}