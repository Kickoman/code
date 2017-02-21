/**
  *     gównokod by candelabra
***/

/*────────────────────────────────────
▄▄▄───────────▄▄▄▄▄▄▄─────────────────
█▀░▀█──────▄▀▀▀░░░░░░░▀▀▄▄────────────
█░░░░█───▄▀░░░░░░░░░░░░░░░▀▄───────▄▄▄
█▄░░░▀▄▄▀░░██░░░░░░░░░░░░░░▀█────█▀▀░█
─█░░░░█▀░░░▀░░░░░░░░██░░░░░░▀█─▄█░░░░█
─▀█░░▄█░░░░░░░▄▄▄░░░░▀░░░░░░░███░░░░█▀
──█▄░█░░░░░▄███████▄░░░░░░░░░█▀░░░░▄▀─
──▀█░█░░░░▄██████████░░░░░░░▄█░░░░▄▀──
───███░░░░███████████░░░░░░▄█░░░░█▀───
────█░░░░░██████████▀░░░░░░█░░░░█▀────
────█░░░░░░▀███████▀░░░░░░░█▄▄▄▀──────
────█░░░░░░░░▀▀▀▀░░░░░░░░░░░▀█────────
────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
──────────────────────────────────────*/

#include <bits/stdc++.h>

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
    #define TASK "points"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

typedef long long ll;
typedef long double ld;

const int INF = int(1e9);
const ll INFll = ll(1e18);
const char array_sep[] = "\n";
const char array_end[] = "";


const char pair_sep[] = ",";
const char pair_end[] = "";


const char map_sep[] = "->";
const char map_end[] = "\n";


template<typename A> ostream & operator<<(ostream & os, const vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
      os << x[i] << array_sep;
    os << array_end;
    return os;
}


template<typename A, typename B> ostream & operator<<(ostream & os, const pair<A, B> & x)
{
    os << x.first << pair_sep << x.second << pair_end;
    return os;
}


template<typename A> istream & operator>>(istream & is, vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
      is >> x[i];
    return is;
}


template<typename A, typename B> istream & operator>>(istream & is, pair<A, B> & x)
{
    is >> x.first >> x.second;
    return is;
}


template<typename _key, typename _val> ostream & operator<<(ostream & os, map<_key, _val> & mp)
{
    for(auto it : mp)   // not for C++98 or earlier
      os << it->F << map_sep << it->S << map_end;
    return os;
}

template<typename _key, typename _val> ostream & operator<<(ostream & os, unordered_map<_key, _val> & mp)
{
    for(auto it : mp)   // not for C++98 or earlier
      os << it->F << map_sep << it->S << map_end;
    return os;
}

template<typename _key> ostream & operator<<(ostream& os, set<_key>& st)
{
    os << "{";
    for(auto& it: st)
        os << it << ", ";
    os << "}";
}


template<typename _response> void die(_response ans)
{
    cout << ans << endl;
    exit(0);
}

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

template<typename element>
string itos(element x)
{
    string res;
    if (x == 0)
        return "0";
    bool negative = false;
    if (x < 0)
        negative = true,
        x *= -1;
    while (x)
        res = char(x % 10 + '0'),
        x /= 10;
    if (negative)
        res = "-" + res;
    return res;
}

int stoint(string s)
{
    bool negative = false;
    if (s[0] == '-')
        negative = true;
    int res = 0;
    for (int i = (negative ? 1 : 0); i < (int) s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            Error("Fuck! '" + s + "' is not a number!\n");
        res *= 10,
        res += (int) s[i] - '0';
    }
    if (negative)
        res *= -1;
    return res;
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
        // kali parožni
        // if empty
        if (blocks.size() == 0)
        {
            vector<int> tmp(1, value);
            build(tmp);
            return;
        }

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
    // ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    freopen(TASK ".err", "w", stderr);
#endif // LOCAL
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//#endif // LOCAL
    int n;
    scanf("%d", &n);

    sqrtdec<int> dec;

    int root = int(sqrt(n));
    map<int, int> ans;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        dec._add(x, y);
        ans[x] = i + 1;

        if (i % root == 0) dec.rebuild();
    }

    auto res = dec.get_source();
    for (int i = 0; i < res.size(); ++i)
        for (int j = 0; j < res[i].size(); ++j)
        {
            int cur = res[i][j];
            printf("%d ", ans[cur]);
        }
    return 0;
}