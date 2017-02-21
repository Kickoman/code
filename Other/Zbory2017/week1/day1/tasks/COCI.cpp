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
    #define TASK "next"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

typedef long long ll;
typedef long double ld;

const int INF = int(1e9);
const ll INFll = ll(1e18);
const int MOD = int(1e9) + 7;
const char array_sep[] = " ";
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

class mintree
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
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int pos, int value)
    {
        for (t[pos += n] = value; pos > 1; pos >>= 1)
            t[pos >> 1] = min(t[pos], t[pos ^ 1]);
    }

    void add(int pos, int value)
    {
        for (t[pos += n] += value; pos > 1; pos >>= 1)
            t[pos >> 1] = min(t[pos], t[pos ^ 1]);
    }

    int query(int l, int r) // Interval [l, r)
    {
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = min(res, t[l++]);
            if (r & 1)
                res = min(res, t[--r]);
        }
        return res; // viartańnie -INF značyć, što ničoha nie bylo znojdziena 
    }               // u vypadku, kali masiŭ nie źmiaščaje eliementaŭ roŭnych -INF

    mintree(vector<int> &v)
    {
        n = v.size();
        t.resize(n << 1, -INF);
        build(v);
    }
};

int main()
{
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    maxtree mx(a);
    mintree mn(a);

    int need = n - k;

    multiset<int> diffs;
    for (int i = 0; i < need - 1; ++i)
        diffs.insert(a[i + 1] - a[i]);

    // for (auto x: diffs)
    //     cout << x << endl;

    int ans = *diffs.begin() + (mx.query(0, need) - mn.query(0, need));
    logger("ans: " + itos(ans), 3);
    for (int i = 1; i < n - need; ++i)
    {
        int cur_big = mx.query(i, i + need) - mn.query(i, i + need);
        if (diffs.empty()) Error("diffs is empty, what the fuck?!");

        diffs.erase(a[i] - a[i - 1]);
        diffs.insert(a[i + need - 1] - a[i + need - 2]);
        int cur_ans = *diffs.begin() + cur_big;
        ans = min(ans, cur_ans);
    }
    printf("%d\n", ans);
    return 0;
}