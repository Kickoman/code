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
    #define TASK "movetofront"
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

int lg = 1;
vector<ll> dist;
vector<vector<pair<int, ll>>> g;
vector<vector<int>> up;
vector<int> dist_ones;

void build_dist()
{
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i].first,
                ln = g[v][i].second;

            dist[to] = dist[v] + ln;
            dist_ones[to] = dist_ones[v] + 1;
            q.push(to);
        }
    }

    logger("Distances successfully caclulated.", 1);
}

void dfs(int v, int p = 0)
{
    up[v][0] = p;
    // cerr << lg << endl;
    for (int i=1; i<=lg; ++i)
    {
        up[v][i] = up[up[v][i-1]][i-1];
        // cerr << i << " ";
    }
    for (size_t i=0; i<g[v].size(); ++i) 
    {
        int to = g[v][i].first;
        if (to != p)
            dfs (to, v);
    }
}

int get(int v, int normal)
{
    for (int i = lg; i >= 0; --i)
        if (dist[up[v][i]] >= normal)
            v = up[v][i];
    return v;
}

int main()
{
//#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//#endif // LOCAL
    int n;
    ll l;
    scanf("%d %lld", &n, &l);
    while ((1 << lg) <= n) ++lg;
    g.resize(n);
    dist.resize(n);
    dist_ones.resize(n);
    up.resize(n, vector<int> (30));
    for (int i = 0; i < n - 1; ++i)
    {
        int x;
        ll len;
        scanf("%d %lld", &x, &len);

        --x;
        g[x].pb({i + 1, len});
        // g[i + 1].pb({x, len});
    }

    build_dist();

#ifdef LOCAL
    printf("Distances:\n");
    for (int i = 0; i < n; ++i)
        printf("%lld ", dist[i]);
    printf("\n####\n");
#endif // LOCAL

    dfs(0);

#ifdef LOCAL
    printf("Up:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 15; ++j)
            printf("%d ", up[i][j]);
        printf("\n");
    }
#endif // LOCAL

    vector<ll> bu_dist = dist;
    sort(bu_dist.begin(), bu_dist.end());
    cerr << bu_dist << endl;
    ll need_dist = l;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
    {
        ll normal = dist[i] - l;
        cerr << get(i, normal) << " " << i << " " << normal << endl;
        if (normal <= 0)
            ans[i] = dist_ones[i] + 1;
        else
            ans[i] = dist_ones[i] - dist_ones[get(i, normal)] + 1;
    }  
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;   
}