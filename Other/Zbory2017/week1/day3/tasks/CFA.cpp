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
    #define TASK "missions"
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

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.F.S != b.F.S)
        return a.F.S < b.F.S;
    if (a.F.F != b.F.F)
        return a.F.F < b.F.F;
    return a.S < b.S;
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
    scanf("%d", &n);
    vector<pair<pair<int, int>, int>> a(n);
    vector<pair<pair<int, int>, int>> b(n);
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a[i].F.F, &a[i].F.S);
        a[i].S = i;   
        b[i] = a[i];
        swap(b[i].F.F, b[i].F.S);
        tasks[i] = {a[i].F.F, a[i].F.S};
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    cerr << a[0] << " " << b[0] << endl;

    vector<bool> used(n);
    ll ans = 0;
    if (a[0].S == b[0].S)
    {
        ans = 1ll * a[0].F.F + a[0].F.S,
        used[a[0].S] = true;
        printf("%lld\n%d ", ans, a[0].S + 1);
    } else {
        ll tmp_1 = 1ll * a[0].F.F + tasks[a[0].S].S + b[0].F.F;
        ll tmp_2 = 1ll * b[0].F.F + tasks[b[0].S].F + a[0].F.F;
        used[a[0].S] = used[b[0].S] = true;
        cerr << tmp_1 << " " << tmp_2 << endl;
        if (tmp_1 < tmp_2)
        {
            ans = tmp_1;
            printf("%lld\n", ans);
            printf("%d %d ", a[0].S + 1, b[0].S + 1);
        } else {
            ans = tmp_2;
            printf("%lld\n", ans);
            printf("%d %d ", b[0].S + 1, a[0].S + 1);    
        }
    }
    // auto &ans = (ans_1_val < ans_2_val ? a : b);
    // printf("%lld\n", min(ans_1_val, ans_2_val));
    for (int i = 0; i < n; ++i)
        if (!used[i])
            printf("%d ", i + 1);
    return 0;
}