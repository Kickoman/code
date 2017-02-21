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

struct enlarged_edge
{
    int to, cost, index;
};

bool comp(edge a, edge b)
{
    return a.cost < b.cost;
}

int n, m;
vector<edge> edges;
vector<int> answer, tin, up;
vector<vector<pair<int, int>>> g;
int timer;
dsu d;

void dfs(int v, int p)
{
    tin[v] = up[v] = ++timer;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i].F;
        int index = g[v][i].S;
        if (index == p)
            continue;
        if (tin[to] != 0)
            up[v] = min(up[v], tin[to]);
        else
        {
            dfs(to, index);
            up[v] = min(up[v], up[to]);
            if (up[to] > tin[v])
                answer[index] = 2;
        }
    }
}

void solve(int start, int fin)
{
    vector<int> cur_vertexes;
    for (int i = start; i <= fin; ++i)
    {
        int x = edges[i].x, y = edges[i].y, cost = edges[i].cost, index = edges[i].index;

        x = d.getSet(x);
        y = d.getSet(y);


        answer[index] = 1;

        if (x == y) 
        {
            answer[index] = 0;
            continue;
        }

        g[x].push_back({y, index});
        g[y].push_back({x, index});

        cur_vertexes.push_back(x);
        cur_vertexes.push_back(y);
    }

    timer = 0;
    for (int i = 0; i < cur_vertexes.size(); ++i)
    {
        int v = cur_vertexes[i];
        if (tin[v] == 0)
            dfs(v, -1);
    }

    for (int i = 0; i < cur_vertexes.size(); ++i)
    {
        int v = cur_vertexes[i];
        g[v].resize(0);
        tin[v] = 0;
        up[v] = 0;
    }
    for (int i = start; i <= fin; ++i)
    {
        int x = edges[i].x, y = edges[i].y;
        d.uniteSet(x, y);
    }
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
    scanf("%d %d", &n, &m);
    edges.resize(m);
    answer.resize(m);
    d.make(n);
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        --x, --y;
        edges[i] = {x, y, z, i};
    }
    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < m;)
    {
        int start = i;
        int fin = i;
        for (; fin < m - 1 && edges[fin + 1].cost == edges[start].cost; ++fin);
        solve(start, fin);

        i = fin + 1;
    }


    for (int i = 0; i < m; ++i)
        if (answer[i] == 0)
            printf("none\n");
        else if (answer[i] == 1)
            printf("at least one\n");
        else 
            printf("any\n");
    return 0;
}