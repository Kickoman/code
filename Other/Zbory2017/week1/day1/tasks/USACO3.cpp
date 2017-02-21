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
    #define TASK "mroute"
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

struct edge
{
    int to;
    ll lat, cap;
};

ld x;

vector<vector<edge>> g;

ld ans = INFll;

bool used[100000];
vector<ld> tans;

void bfs(int star_vertex)
{
    queue<pair<int, pair<ll, ll>>> q;
    q.push({star_vertex, {0, ld(INFll)}});
    // used[0] = true;
    while (!q.empty())
    {
        int v = q.front().first;
        pair<ll, ll> cur_ans = q.front().second;
        q.pop();

        // cerr << cur_ans.F << " " << cur_ans.S << " - this is debug, suka\n";

        if (v == int(g.size()) - 1)
        {
            // cerr << cur_ans.F << " " << cur_ans.S << endl;
            if (cur_ans.S != 0) ans = min(ans, 1.0 * cur_ans.F + x / cur_ans.S);
            continue;
        }

        for (size_t i = 0; i < g[v].size(); ++i)
        {
            edge cur = g[v][i];

            ll cur_cap = min(cur_ans.S, cur.cap);
            
            int new_ans = (cur_cap != 0 ? (cur_ans.F + cur.lat) + x / cur_cap : INFll);
            if (new_ans < tans[cur.to])
            {
                tans[cur.to] = new_ans;
                q.push({cur.to, {cur_ans.F + cur.lat, min(cur_ans.S, cur.cap)}});
            } 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
// #ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif // LOCAL
    int n, m;
    // scanf("%d %d %LF", &n, &m, &x);
    cin >> n >> m >> x;
    // cerr << n << endl;
    // cerr << m << endl;
    // cerr << x << endl;
    g.resize(n);
    tans.resize(n, ld(INFll));
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        ll l, c;
        // cerr << i << endl;
        // scanf("%d %d %lld %lld", &x, &y, &l, &c);
        cin >> x >> y >> l >> c;
        --x, --y;

        // cerr << i << endl;
        // cerr << x << " " << y << " " << l << " " << c << endl;
        g[x].push_back({y, l, c});
        g[y].push_back({x, l, c});

    }
    // cerr << "ee\n";
    used[0] = true;

    // cerr << "done kek\n\n";
    bfs(0);
    // int ans = dfs(0);
    cout << (ll) floor(ans) << endl;
    // printf("%lF\n", ans);
    return 0;
}