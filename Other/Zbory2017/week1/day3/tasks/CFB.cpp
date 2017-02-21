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

#define NUMERATOR first
#define DENOMINATOR second

struct node
{
    int np, a, b;
};

node make_struct(int x, int y, int z)
{
    node res;
    res.np = x;
    res.a = y;
    res.b = z;
    return res;
}

void improve(pair<ll, ll> &a)
{
    ll gcd = __gcd(a.F, a.S);
    a.F /= gcd;
    a.S /= gcd;
}

pair<ll, ll> add(pair<ll, ll> a, pair<ll, ll> b)
{
    ll lcm = a.DENOMINATOR / __gcd(a.DENOMINATOR, b.DENOMINATOR) * b.DENOMINATOR;

    if (lcm == 0)
    {
        logger(a, 3);
        logger(b, 3);
        Error("lca is zero");
    }

    a.NUMERATOR *= lcm / a.DENOMINATOR;
    b.NUMERATOR *= lcm / b.DENOMINATOR;
    pair<ll, ll> res = {a.NUMERATOR + b.NUMERATOR, lcm};

    improve(res);
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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    ll lcm = a.DENOMINATOR / __gcd(a.DENOMINATOR, b.DENOMINATOR) * b.DENOMINATOR;
    a.NUMERATOR *= lcm / a.DENOMINATOR;
    b.NUMERATOR *= lcm / b.DENOMINATOR;
    pair<ll, ll> res = {a.NUMERATOR + b.NUMERATOR, lcm};
    return (a.NUMERATOR < b.NUMERATOR);
}

int main()
{
//#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#ifdef LOCAL
    freopen(TASK ".err", "w", stderr);
#endif // LOCAL
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//#endif // LOCAL
    int n;
    scanf("%d", &n);
    map<pair<ll, ll>, ll> points, used, number;
    vector<pair<ll, ll>> input(n);
    for (int i = 0; i < n; ++i)
    {
        ll numerator, denominator;
        scanf("%lld %lld", &numerator, &denominator);
        points[{numerator, denominator}] = 1;
        number[{numerator, denominator}] = i + 1;
        input[i] = {numerator, denominator};
    }
    points[{0, 1}] = 1;
    points[{1, 1}] = 1;
    used[{0, 1}] = 1;
    used[{1, 1}] = 1;

    // print_map(points);
/*
    YES
96 351 251
89 96 251       
362 96 351
77 89 251*/
// 1,2 0,1 1,1
// 3,4 1,2 1,1
// 1,4 1,2 0,1
// 7,8 3,4 1,1
    vector<node> ans;

    for (auto a: input)
    {
        // if (!used[a]) continue;
        for (auto b: input)
        {
            // if (!used[b]) continue;
            if (a == b) continue;
            // cerr << a << " " << b << "\n";
            pair<ll, ll> new_point = add(a, b);
            new_point.DENOMINATOR *= 2;
            // cerr << "New point: " << new_point << " from " << a << " " << b << endl;
            // cerr << points[new_point] << " : " << used[new_point] << endl;
            if (points[new_point] && !used[new_point])
            {
                ans.push_back(make_struct(number[new_point], number[a], number[b]));
                used[new_point] = 1;
            }
            // cerr << "size: " << ans.size() << endl;
            // print_map(used);
            cerr << "\n\n";
        }
    }

    if (ans.size() != n - 2)
    {
        printf("NO\n");
        for (auto x: input)
            if (!used[x])
            {
                cerr << "No: " << x << " " << used[x] << endl;
                printf("%lld\n", number[x]);
                break;
            }
    } else {
        printf("YES\n");
        for (auto x: ans)
            printf("%d %d %d\n", x.np, x.a, x.b);
    }
    return 0;
}