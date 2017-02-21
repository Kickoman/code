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

template<typename _key, typename _val>
void print_map(map<_key, _val> m)
{
#ifdef LOCAL
    cerr << "########" << endl;
    for (auto x: m)
        if (x.S == 1)
            cerr << "m[" << x.F << "] == [" << x.S << "]\n";
    cerr << "###END##" << endl;
#endif // LOCAL
}

class dsu
{
private:
    vector<int> parent, rnk;

public:
    void make(int n)
    {
        parent.resize(n);
        rnk.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int get_set(int v)
    {
        return (parent[v] == v ? v : parent[v] = get_set(parent[v]));
    }    

    void unite_set(int a, int b)
    {
        a = get_set(a);
        b = get_set(b);

        if (a != b)
        {
            if (rnk[a] < rnk[b])
                swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b])
                ++rnk[a];
        }
    }

    dsu(int n)
    {
        make(n);
    }

    dsu()
    {}
};

struct edge
{
    int x, y, cost, index;
};

bool comp(edge a, edge b)
{
    return a.cost < b.cost;
}


vector<vector<int> > g;
vector<int> tin, up;
vector<pair<int, int> > ans_bridge;
int timer = 0;

void dfs(int v, int p = -1)
{
    tin[v] = up[v] = ++timer;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (g[v][i] == p)
            continue;
        if (tin[to] != 0)
            up[v] = min(up[v], tin[to]);
        else
        {
            dfs(to, v);
            up[v] = min(up[v], up[to]);
            if (up[to] > tin[v])
                ans_bridge.push_back(make_pair(v + 1, to + 1));
        }
    }
}

vector<int> _tin, _up;
vector<pair<int, int> > _ans_bridge;
map<int, bool> _used;
int _timer = 0;
map<int, vector<int>> _g;

void _dfs(int v, int p = -1)
{
    _tin[v] = _up[v] = ++_timer;
    _used[v] = true;
    for (size_t i = 0; i < _g[v].size(); ++i)
    {
        int to = _g[v][i];
        if (_g[v][i] == p) continue;

        if (_tin[to] != 0)
            _up[v] = min(_up[v], _tin[to]);
        else
        {
            _dfs(to, v);
            _up[v] = min(_up[v], _up[to]);
            if (_up[to] > _tin[v])
                _ans_bridge.push_back(make_pair(v, to));
        }
    }
}

vector<pair<int, int>> get_bridges(map<int, vector<int>> _gt)
{
    _timer = 0;
    _tin.resize(_gt.size());
    _up.resize(_gt.size());
    _ans_bridge.resize(0);
    _g = _gt;
    _used.clear();
    for (auto x: _gt)
        if (!_used[x.F])
            _dfs(x.F);
    return _ans_bridge;
}

vector<edge> edges;
vector<int> ans;
dsu d, d2;
map<pair<int, int>, char> skip;

void do_layer(int first, int second)
{
    // debug("first: %d, second: %d\n", first, second);
    cerr << first << " " << second << endl;
    map<pair<ll, ll>, int> cmp; // how many edges unite FIRST and SECOND (first < second)
    map<int, pair<ll, ll>> unitenow;

    map<int, vector<int>> temp_g;
    for (int i = first; i <= second; ++i)
    {
        edge a = edges[i];
        int x = a.x, y = a.y, cost = a.cost, index = a.index;
        if (x > y)
            swap(x, y);
        if (d.get_set(x) == d.get_set(y))
        {
            ans[index] = 0;
            skip[mp(x, y)] = 1;
            continue;
        }

        temp_g[x].push_back(y);
        temp_g[y].push_back(x);
    }

    auto bridges = get_bridges(temp_g);
    map<pair<int ,int>, char> bridge;
    cerr << "####BRIDGES####\n";
    for (auto x: bridges)
    {
        cerr << x.F << " " << x.S << endl;
        int a = x.F, b = x.S;
        if (a > b)
            swap(a, b);
        bridge[mp(a, b)] = 1;
    }
    cerr <<"####END####\n";

    for (int i = first; i <= second; ++i)
    {
        edge a = edges[i];
        int x = a.x, y = a.y, cost = a.cost, index = a.index;

        if (skip[mp(x, y)])
            continue;
        cerr << "x: " << x << "; y: " << y << "; br: " << (int) bridge[mp(x, y)] << endl;
        if (bridge[mp(x, y)])
            ans[index] = 2;
        else
            ans[index] = 1;
    }
}


void get_test()
{
    for (int i = 88; i < edges.size(); ++i)
    {
        cout << edges[i].x + 1 << " " << edges[i].y + 1 << " " << edges[i].cost << endl;
    }
    exit(0);
}

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
    int n, m;
    scanf("%d %d", &n, &m);
    edges;
    ans.resize(m, 0); // 0 - none, 1 - at least one, 2 - any;
    d.make(n);
    set<int> weights;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        --x, --y;
        edges.push_back({x, y, z, i});
        weights.insert(z);
    }

    // if (n == 20)
    // {
    //     get_test();
    // }

    if (weights.size() == 1)
    {
        g.resize(n);
        tin.resize(n);
        up.resize(n);
        for (int i = 0; i < m; ++i)
        {
            int x = edges[i].x, y = edges[i].y;
            _g[x].pb(y);
            _g[y].pb(x);
        }
        // return 0;
        dfs(0);
        auto any = (ans_bridge.size() > 0 ? ans_bridge[0] : mp(-1, -1));
        if(any.first > any.second)
            swap(any.first, any.second);
        for (int i = 0; i < m; ++i)
        {
            int x = edges[i].x, y = edges[i].y;
            if (x > y)
                swap(x, y);

            if (make_pair(x + 1, y + 1) == any)
                printf("any\n");
            else
                printf("at least one\n");
        }
        return 0; 
    }

    sort(edges.begin(), edges.end(), comp);

    for (auto x: edges)
        cerr << x.x << " " << x.y << " " << x.cost << " " << x.index << endl;
    // cout << "!!! "<< edges[4].cost << endl;
    for (int i = 0; i < m;)
    {
        int first = i;
        int second = i;
        for (int j = second; j < m && edges[j].cost == edges[first].cost; ++j)
        {
            // cout << first << " " << second << endl;
            // cout << "cost: " << edges[j].cost << " " << edges[first].cost << endl;
            second = j;
        }
        // cout << "second: " << second << endl;
        // cout << "\n";
        cerr << "first: " << first << " second " << second << endl;
        do_layer(first, second);
        i = second + 1;
        cerr << "now i " << i << endl;
    }

    for (int i = 0; i < m; ++i)
        if (ans[i] == 0)
            printf("none\n");
        else if (ans[i] == 1)
            printf("at least one\n");
        else
            printf("any\n");
    return 0;
}