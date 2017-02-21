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

const int MAXN = 1000000;
const int MOD = 1000000007;
const int MOD1 = 1000000009;
ll p = max(rand(), 239017) | 1;
pair<ll, ll> p_pow[MAXN];

struct Hash {
    int n;
    vector<pair<ll, ll> > hash;
    
    Hash() {
        n = 0;
    }
    
    Hash(string s) {
        n = (int)s.size();
        hash.resize(n);
        for (int i = 0; i < n; i++) {
            hash[i].F = (i ? (1ll * hash[i - 1].F * p % MOD) : 0);
            hash[i].F += 1ll * (s[i] - '0' + 1) % MOD;
            hash[i].F %= MOD;
            
            hash[i].S = (i ? (1ll * hash[i - 1].S * p % MOD1) : 0);
            hash[i].S += 1ll * (s[i] - '0' + 1) % MOD1;
            hash[i].S %= MOD1;
            
            if (hash[i].F < 0) hash[i].F += MOD;
            if (hash[i].S < 0) hash[i].S += MOD1;
        }
    }
    
    pair<ll, ll> get(int l, int r) {
        int len = r - l + 1;
        ll h1 = hash[r].F;
        if (l) h1 -= 1ll * hash[l - 1].F * p_pow[len].F % MOD;
        h1 %= MOD;
        if (h1 < 0) h1 += MOD;
        
        ll h2 = hash[r].S;
        if (l) h2 -= 1ll * hash[l - 1].S * p_pow[len].S % MOD1;
        h2 %= MOD1;
        if (h2 < 0) h2 += MOD1;
        return {h1, h2};
    }
    
    
    pair<ll, ll> getHash() {
        return hash[n - 1];
    }
};

ll get_palindromes(string s)
{
    int n = s.size();
    vector<int> d2 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
        while (i+k-1 < n && i-k >= 0 && s[i+k-1] != s[i-k])  ++k;
        d2[i] = --k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     // debug("%d ", d1[i]);
    //     cerr << d1[i] << " ";
    // }
    // debug("\n");
    // cerr << endl;
    // for (int i = 0; i < n; ++i)
    //     // debug("%d ", d2[i]);
    //     cerr << d2[i] << " ";
    // // debug("\n");
    // cerr << endl;


    ll result = 0;
    // for (auto x: d1)
    //     result += x - 1;
    for (auto x: d2)
        result += x;
    return result;
}

inline void print_all_sequences(string s)
{
    string buffer;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        buffer = "";
        for (int j = i; j < n; ++j)
        {
            buffer += s[j];
            cout << "SEQ_" << ++cnt << ": " << buffer << endl;
        }
    }
    cout << "END OF SEQUENCES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    string s;
    cin >> s;

    p_pow[0] = {1, 1};
    for (int i = 1; i < n + 1; ++i)
        p_pow[i].F = (p_pow[i - 1].F * p) % MOD,
        p_pow[i].S = (p_pow[i - 1].S * p) % MOD1;

    // print_all_sequences(s);

    // debug("palindromes:\n%d\n", get_palindromes(s));
    // debug("All: %d\n", n * (n - 1) / 2);

    Hash hash(s);

    set<pair<ll, ll>> ans;
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;

        ans.insert(hash.get(l, r));
    }
    cout << get_palindromes(s) << endl;
    cout << ans.size() << endl;
    return 0;
}