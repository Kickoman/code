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
const int MOD = 1000000007;
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

// const int N = 3e5;
int N;
ll ans;
vector<int> sz;
vector<char> used;
vector<vector<pair<int, int>> > g;

int computeSize(int x, int pr = -1) {
    cerr << "computing : " << x << endl;
    sz[x] = 1;
    for (auto to : g[x]) {
        if (to.F == pr || used[to.F]) continue;
        sz[x] += computeSize(to.F, x);
    }
    return sz[x];
}

int findCentroid(int x) {
    const int M = sz[x];
    bool run = true;
    int pr = -1;
    while (run) {
        run = false;
        for (auto to : g[x]) {
            if (to.F == pr || used[to.F]) continue;
            if (sz[to.F] >= M / 2) {
                pr = x;
                x = to.F;
                run = true;
                break;
            }
        }
    }
    return x;
}

void dfs(int v, int path, vector<int> &cnt, int p)
{
    cnt[path % 3]++;
    for (auto to: g[v])
    {
        if (to.F == p || used[to.F]) continue;

        dfs(to.F, path + to.S, cnt, v);
    }
}

void solve(int x) {
    computeSize(x);
    cerr << x << endl;
    x = findCentroid(x);

    ll a = 0, b = 0, c = 0;

    for (auto to: g[x])
    {
        if (used[to.F]) continue;
        vector<int> cnt(3, 0);
        dfs(to.F, to.S, cnt, x);
        cerr << "NOW: " << x << endl << cnt << endl << endl;

        ans += 1ll * a * cnt[0] + 1ll * b * cnt[2] + 1ll * c * cnt[1] + cnt[0];
        ans %= MOD;

        a += cnt[0], b += cnt[1], c += cnt[2];
    }
    cerr << "TEMP: " << a << " " << b << " " << c << " " << ans << endl;

    // nie kranać
    used[x] = true;
    for (auto to : g[x]) {
        if (used[to.F]) continue;
        solve(to.F);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    freopen(TASK ".err", "w", stderr);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif // LOCAL
    scanf("%d", &N);
    g.resize(N);
    sz.resize(N + 1);
    used.resize(N);

    for (int i = 0; i < N-1; ++i)
    {
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        --x, --y;

        g[x].push_back({y, cost});
        g[y].push_back({x, cost});
    }

    solve(0);

    printf("%lld\n", ans);
    return 0;
}