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
const ll MOD =  (1e17) + 7;
const ll MOD1 = (1e17) + 3;
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

// const int p = 31;
// vector<pair<ll, ll>> p_pow;

// void init(int n = 1000000)
// {
//     p_pow.resize(n, {0, 0});
//     p_pow[0].F = 1;
//     p_pow[0].S = 1;
//     for (int i = 1; i < p_pow.size(); i++)
//     {
//         p_pow[i].F = (1ll * p_pow[i - 1].F * p) % MOD;
//         p_pow[i].S = (1ll * p_pow[i - 1].S * p) % MOD1;
//     }
// }


// struct Hash
// {
//     int n;
//     vector<pair<ll, ll> > hsh;

//     Hash()
//     {
//         n = 0;
//     }

//     Hash(string s)
//     {
//         n = (int)s.size();
//         hsh.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             hsh[i].F = (i ? (1ll * hsh[i - 1].F * p % MOD) : 0);
//             hsh[i].F += 1ll * (s[i] - 'a' + 1) % MOD;
//             hsh[i].F %= MOD;
//             hsh[i].S = (i ? (1ll * hsh[i - 1].S * p % MOD1) : 0);
//             hsh[i].S += 1ll * (s[i] - 'a' + 1) % MOD1;
//             hsh[i].S %= MOD1;
//             if (hsh[i].F < 0) hsh[i].F += MOD;
//             if (hsh[i].S < 0) hsh[i].S += MOD1;
//         }
//     }

//     pair<ll, ll> get(int l, int r)
//     {
//         int len = r - l + 1;
//         ll h1 = hsh[r].F;
//         if (l)
//             h1 -= 1ll * hsh[l - 1].F * p_pow[len].F % MOD;
//         h1 %= MOD;
//         if (h1 < 0) h1 += MOD;
//         ll h2 = hsh[r].S;
//         if (l)
//             h2 -= 1ll * hsh[l - 1].S * p_pow[len].S % MOD1;
//         h2 %= MOD1;
//         if (h2 < 0) h2 += MOD1;
//         return {h1, h2};
//     }


//     pair<ll, ll> getHash()
//     {
//         return hsh[n - 1];
//     }
// };

ll bad(vector<ll> &v, int l, int r)
{
    if (l == 0)
        return v[r];
    return v[r] - v[l - 1];
}

const int p = 29;


int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    freopen(TASK ".err", "w", stderr);
#endif // LOCAL
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//#endif // LOCAL
    string s;
    cin >> s;
    string letters;
    cin >> letters;
    int k;
    cin >> k;

    int n = s.size();
    map<ll, int> diff;
    
    vector<int> bads(n);
    for (int i = 0; i < n; ++i)
        if (letters[s[i] - 'a'] == '0')
            bads[i] = 1;

    vector<ll> pref(s.size());
    pref[0] = bads[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + bads[i];

    // vector<ll> pp;
    // auto all = all_hashes(s, pp);

    string cur = "";
    for (int i = 0; i < n; ++i)
    {
        cur = "";
        ll curhash = 0;
        ll ppow = 29;
        for (int j = i; j < n; ++j)
        {
            if (bad(pref, i, j) > k) break;
            curhash += (s[j] - 'a' + 1) * ppow;
            ppow *= p;
            ppow %= ll(1e17);
            // curhash = add_symbol(curhash, s[j], ppow);
            // auto kek = hs.get(i, j);
            // diff.insert(kek);
            diff[curhash]++;
        }
    }

    cout << diff.size() << endl;
    return 0;
}