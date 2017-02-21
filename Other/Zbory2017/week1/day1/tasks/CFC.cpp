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
    #define TASK "next"
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

class Treap
{
public:
    int key, pr;
    Treap *left, *right;

    Treap()
    {}

    Treap(int k)
    {
        key = k;
        pr = rand() % MOD;
        left = right = nullptr;
    }
    
    static Treap *merge(Treap *l, Treap *r)
    {
        Treap *res;

        if (l == nullptr)
        {
            res = r;
            return res;
        }
        if (r == nullptr)
        {
            res = l;
            return res;
        }

        if (r->pr > l->pr)
        {
            res = r;
            res->left = merge(l, r->left);
        } else {
            res = l;
            res->right = merge(l->right, r);
        }
    }   

    //                  zychodnaje dreva, kliuč, vyniki
    static void split(Treap *v, int key, Treap *&l, Treap *&r)
    {
        if (v == nullptr)
        {
            l = r = nullptr;
            return;
        }

        if (v->key <= key)
        {
            l = v;
            split(v->right, key, l->right, r);
        } else {
            r = v;
            split(v->left, key, l, r->left);
        }
    }

    static void add(Treap *&v, int key)
    {
        Treap *l;
        Treap *r;
        split(v, key, l, r);
        Treap *res = new Treap(key);
        v = merge(merge(l, res), r);
    }

    /*
        dadać značeńnie:
        1. split dreva pa kliučy X
        2. mergym vyniki l + new + r
    */

    static int next(Treap *v, int value)
    {
        int res = 2 * INF;
        Treap *cur = v;
        while (cur != nullptr)
        {
            // cerr << "value: " << value << endl;
            // cerr << cur->key << endl;
            if (cur->key >= value)
            {
                res = min(cur->key, res);
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }
    /*
        vydalić značeńnie:
        1. split pa kliučy X
        2. u vynikach.R - x užo niama.
           split vynik.L pa (x - 1)
        3. mergym vyniki
    */
};

void prtr(Treap* res)
{
    if(res == nullptr) return;

    prtr(res->left);
    cout << res->key << " ";
    prtr(res->right);
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
    Treap *tr = nullptr;
    // Treap::add(tr, 4);
    // prtr(tr);
    for (int i = 0, prv = -228; i < n; ++i)
    {
        char c;
        int x;
        scanf(" %c %d", &c, &x);
        if (c == '+')
        {
            if (prv == -228)
            {
                Treap::add(tr, x);
            } else {
                Treap::add(tr, (x + prv) % int(1e9));
                prv = -228;
            }
        } else {
            int res = Treap::next(tr, x);
            printf("%d\n", (res == 2 * INF ? -1 : res));
            prv = (res == 2 * INF ? -1 : res);
        }
        // prtr(tr);
        // cout << endl;
    }
    return 0;
}