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
    #define TASK "lel"
    #define debug(...)
    #define cerr if(0)cerr
#endif // LOCAL

typedef long long ll;
typedef long double ld;

const int INF = int(1e9);
const ll INFll = ll(1e18);
const char array_sep[] = " ";
const char array_end[] = "";


const char pair_sep[] = ",";
const char pair_end[] = "";


const char map_sep[] = "->";
const char map_end[] = "\n";


template<typename A>
ostream & operator<<(ostream & os, const vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
      os << x[i] << array_sep;
    os << array_end;
    return os;
}


template<typename A, typename B> 
ostream & operator<<(ostream & os, const pair<A, B> & x)
{
    os << x.first << pair_sep << x.second << pair_end;
    return os;
}


template<typename A> 
istream & operator>>(istream & is, vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
      is >> x[i];
    return is;
}


template<typename A, typename B> 
istream & operator>>(istream & is, pair<A, B> & x)
{
    is >> x.first >> x.second;
    return is;
}


template<typename _key, typename _val> 
ostream & operator<<(ostream & os, map<_key, _val> & mp)
{
    for(auto it : mp)   // not for C++98 or earlier
      os << it->F << map_sep << it->S << map_end;
    return os;
}

template<typename _key, typename _val> 
ostream & operator<<(ostream & os, unordered_map<_key, _val> & mp)
{
    for(auto it : mp)   // not for C++98 or earlier
      os << it->F << map_sep << it->S << map_end;
    return os;
}

template<typename _key> 
ostream & operator<<(ostream& os, set<_key>& st)
{
    os << "{";
    for(auto& it: st)
        os << it << ", ";
    os << "}";
}


template<typename _response> 
void die(_response ans)
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

int n, m;

struct edge
{
    int x, y;
};

/* 
    Systema niaźvazanych mnostvaŭ
*/

class dsu
{
private:
    vector<int> parent, rnk;
public:
    void make(int n) // Builds a multiplicity of sets, n == number of nodes
    {
        parent.resize(n);
        rnk.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int getSet(int v) // Gets the set, node V belongs to
    {
        return (parent[v] == v ? v : parent[v] = getSet(parent[v]));
    }

    void uniteSet(int a, int b) // Unites set A and set B
    {
        a = getSet(a),
        b = getSet(b);

        if (a != b)
        {
            if (rnk[a] < rnk[b])
                swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b])
                ++rnk[a];
        }
    }

    void uniteSet(edge x)
    {
        int a = x.x, b = x.y;
        uniteSet(a, b);
    }

    int getParent(int x)
    {
        return parent[x];
    }

    int getRank(int x)
    {
        return rnk[x];
    }

    dsu(int n)
    {
        make(n);
    }

    dsu()
    {}
};

dsu merge(dsu a, dsu b)
{
    dsu res = a;
    for (int i = 0; i < n; ++i)
        if (a.getSet(i) != b.getSet(i))
            res.uniteSet(a.getSet(i), b.getSet(i));
    return res;
}

int getComponent(dsu x)
{
    set<int> diffComponents;
    for (int i = 0; i < n; ++i)
        diffComponents.insert(x.getSet(i));
    return int(diffComponents.size());
}

int main()
{
    // ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif // LOCAL
    scanf("%d %d", &n, &m);
    vector<dsu> prefix(m), suffix(m);
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", edges[i].x, edges[i].y);
        edges[i].x--;
        edges[i].y--;   
    }

    prefix[0].make(n);
    prefix[0].uniteSet(edges[0]);
    for (int i = 1; i < m; ++i)
    {
        prefix[i] = prefix[i - 1];
        prefix[i].uniteSet(edges[i]);
    }

    suffix[m - 1].make(n);
    suffix[m - 1].uniteSet(edges[m - 1]);
    for (int i = m - 2; i > -1; --i)
    {
        suffix[i] = suffix[i + 1];
        suffix[i].uniteSet(edges[i]);
    }

    int k;
    scanf("%d", &k);
    while (k--)
    {
        cerr << k << endl;
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;

        if (l == 0)
        {
            printf("%d\n", getComponent(suffix[r + 1]));
            continue;
        }

        if (r == m - 1)
        {
            printf("%d\n", getComponent(prefix[l - 1]));
            continue;
        }

        printf("%d\n", getComponent(merge(prefix[l - 1], suffix[r + 1])));
    }

    return 0;
}