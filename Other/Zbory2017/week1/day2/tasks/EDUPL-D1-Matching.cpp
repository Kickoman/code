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


// template<typename A> ostream & operator<<(ostream & os, const vector<A> & x)
// {
//     for(int i = 0; i < x.size(); i++)
//       os << x[i] << array_sep;
//     os << array_end;
//     return os;
// }


// template<typename A, typename B> ostream & operator<<(ostream & os, const pair<A, B> & x)
// {
//     os << x.first << pair_sep << x.second << pair_end;
//     return os;
// }


// template<typename A> istream & operator>>(istream & is, vector<A> & x)
// {
//     for(int i = 0; i < x.size(); i++)
//       is >> x[i];
//     return is;
// }


// template<typename A, typename B> istream & operator>>(istream & is, pair<A, B> & x)
// {
//     is >> x.first >> x.second;
//     return is;
// }


// template<typename _key, typename _val> ostream & operator<<(ostream & os, map<_key, _val> & mp)
// {
//     for(auto it : mp)   // not for C++98 or earlier
//       os << it->F << map_sep << it->S << map_end;
//     return os;
// }

// template<typename _key, typename _val> ostream & operator<<(ostream & os, unordered_map<_key, _val> & mp)
// {
//     for(auto it : mp)   // not for C++98 or earlier
//       os << it->F << map_sep << it->S << map_end;
//     return os;
// }

// template<typename _key> ostream & operator<<(ostream& os, set<_key>& st)
// {
//     os << "{";
//     for(auto& it: st)
//         os << it << ", ";
//     os << "}";
// }


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

vector<int> gr, ls;

void bas(vector<int> t, vector<int>* b, vector<int>* sm)
{
    int n = t.size();
    vector<int> nxt(n), dr(n), pos(n);
    b -> resize(n);
    sm -> resize(n);

    for(int i = 0; i < n; i++)
    {
        nxt[i] = i+1;
        dr[i] = i-1;
        pos[t[i]] = i ;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if (nxt[t[i]] == n)
            (*b)[i] = -1;
        else
            (*b)[i] = pos[nxt[t[i]]];
        if(dr[t[i]] == -1)
            (*sm)[i] = -1;
        else
            (*sm)[i] = pos[dr[t[i]]];
        if(dr[t[i]] != -1)
            nxt[dr[t[i]]] = nxt[t[i]];
        if(nxt[t[i]] != n)
            dr[nxt[t[i]]] = dr[t[i]];

    }
}


bool nice(int i, int j, vector<int> &templ)
{
    // int cur_pos = p[i];

    bool res = true;

    // if (ls[cur_pos] != -1)
    //     res = res && ()

    if (ls[j] != -1 && templ[i] < templ[i - (j - ls[j])])
        return false;
    if (gr[j] != -1 && templ[i] > templ[i - (j - gr[j])])
        return false;

    // cerr << 
    // if (ls[cur_pos] != -1)
    //     res = res && (s[i] > s[i - cur_pos + ls[cur_pos]]) && (s[j] > s[j - cur_pos + ls[cur_pos]]);
    // if (gr[cur_pos] != -1)
    //     res = res && (s[i] < s[i - cur_pos + gr[cur_pos]]) && (s[j] < s[j - cur_pos + gr[cur_pos]]);
    return true;
}

vector<int> prefix_function(vector<int> s)
{
    int n = int(s.size());
    vector<int> pi(n);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && /*!(nice(i, j, s, pi))*/ s[i] != s[j])
            j = pi[j - 1];
        if (/*nice(i, j, s, pi)*/s[i] == s[j])
            ++j;
        pi[i] = j;
        // cout << "pref[" << i << "]: " << pi << endl;
    }
    return pi;
}


vector<int> prefix_function_mod(vector<int> &templ, vector<int> &s)
{
    // int n = int(s.size());
    int n = templ.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && !(nice(i, j, templ)) /*s[i] != s[j]*/)
            j = pi[j - 1];
        if (nice(i, j, templ)/*s[i] == s[j]*/)
            ++j;
        pi[i] = j;
        // cout << "pref mod[" << i << "]: " << pi << endl;
    }  
    int ans = 0;
    vector<int> res;
    for(int i = 0; i < s.size(); i++)
    {
        while(ans && !nice(i, ans, s)/*!check(b, ans, i, bi, sm)*/)
            ans = pi[ans-1];
        if(nice(i, ans, s)/*check(b, ans, i, bi, sm)*/)
            ans ++;
        if(ans == n)
        {
            res.push_back(i - n + 1);
            ans = pi[ans - 1];
        }
    }
    return res;
    // return pi;
}

vector<int> z_function(vector<int> s) {
    int n = (int) s.size();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int main()
{
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
// #else
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int j = 0; j < m; ++j)
        scanf("%d", &b[j]);

    vector<int> templ(n), equals(n);
    for (int i = 0; i < n; ++i)
    {
        templ[a[i] - 1] = i;
        equals[i] = a[i] - 1;
        // cerr << i << " " << a[i] - 1 << "\n";
    }
    // for (int i = 0; i < n; ++i)
    //     equals[templ[i]] = i;

    // cout << templ << endl;
    // cout << equals << endl;
    
    gr.resize(n, -1);
    ls.resize(n, -1);
    bas(templ, &gr, &ls);
    if (0)
    {
        set<int> cur;
        for (int i = 0; i < n; ++i)
        {
            cerr << i << endl;
            set<int>::iterator g = cur.lower_bound(templ[i]);
            cerr << i << endl;
            set<int>::iterator l = g; 
            if (g != cur.begin())
                ls[i] = equals[*(--l)];

            cerr << i << endl;
            cerr << *g << " " << *l << endl;
            if (cur.empty()) 
            {
                cur.insert(templ[i]);
                continue;
            }

            if (g != cur.end())
                gr[i] = equals[*g];

            cur.insert(templ[i]);
        }
    }
    vector<int> ans = prefix_function_mod(templ, b);
    // for (size_t i = 0; i < zfunc.size(); ++i)
    // {
    //     if (zfunc[i] == n)
    //         ans.push_back(i);
    // }

    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); ++i)
        printf("%d ", ans[i] + 1);

    return 0;
}