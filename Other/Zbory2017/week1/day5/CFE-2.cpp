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

vector<pair<int, int>> edges;
vector<string> catalogCycles;
int n, m;

void dfs(int u, int endV, vector<pair<int, int>> &edges, vector<char> used, int unEdges, vector<int> &cycle)
{
    if (u != endV)
        used[u] = 2;
    else if (cycle.size() >= 2)
    {
        reverse(cycle.begin(), cycle.end());
        string s = itos(cycle[0]);
        for (int i = 1; i < cycle.size(); ++i)
            s += itos(cycle[i]);
        s.pop_back();

        bool flag = false;


        for (int i = 0; i < catalogCycles.size() && !flag; ++i)
            if (catalogCycles[i] == s)
                flag = true;

        if (!flag)
        {
            reverse(cycle.begin(), cycle.end());
            s = itos(cycle[0]);
            for (int i = 1; i < cycle.size(); ++i)
                s += itos(cycle[i]);
            s.pop_back();
            catalogCycles.push_back(s);
        }
        return;
    }

    for (int w = 0; w < edges.size(); ++w)
    {
        if (w == unEdges)
            continue;

        if (used[edges[w].second] == 1 && edges[w].first == u)
        {
            vector<int> newcycle = cycle;
            newcycle.push_back(edges[w].S);
            dfs(edges[w].S, endV, edges, used, w, newcycle);
            used[edges[w].S] = 1;
        } else if (used[edges[w].F] == 1 && edges[w].S == u)
        {
            vector<int> newcycle = cycle;
            newcycle.pb(edges[w].F);
            dfs(edges[w].F, endV, edges, used, w, newcycle);
            used[edges[w].F] = 1;
        }
    }
}


void get_cycles()
{
    vector<char> used(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            used[j] = 1;

        vector<int> cycle;

        cycle.push_back(i);
        dfs(i, i, edges, used, -1, cycle);
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
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        edges.push_back({x, y});
    }
    get_cycles();
    cout << catalogCycles << endl;
    return 0;
}