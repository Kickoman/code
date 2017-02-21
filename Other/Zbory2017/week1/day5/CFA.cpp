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

int len;
vector<pair<int, int>> a;
vector<vector<int>> answer;

//insert_after(answer, position, i);

inline void insert_after(vector<int> &v, int pos, int value)
{
    cerr << "inserting " << value << " to " << pos << endl;
    vector<int> tmp;
    for (int i = 0; i < pos; ++i)
        tmp.push_back(v[i]);
    tmp.push_back(value);
    for (int i = pos; i < int(v.size()); ++i)
        tmp.push_back(v[i]);
    v = tmp;
}

inline void rebuild(vector<vector<int>> &source, vector<int> &blocks)
{
    cerr << "rebuilding\n";
    vector<int> tmp;
    for (int i = 0; i < source.size(); ++i)
        for (int j = 0; j < source[i].size(); ++j)
            tmp.push_back(source[i][j]);

    int n = int(tmp.size());
    len = (int) sqrt(1.0 * n) + 1;
    vector<int> b(len);
    for (int i = 0; i < n; ++i)
        b[i / len] = max(b[i / len], a[tmp[i]].F);
    blocks = b;

    vector<vector<int>> nw(len);
    for (int i = 0; i < n; ++i)
        nw[i / len].push_back(tmp[i]);
    source = nw;
}

int get_block(vector<int> blocks, int value, int &c)
{
    int res = blocks.size() - 1;
    while (res > 0 && c >= answer[res - 1].size())
    {
        cerr << "gb: " << res << " " << blocks[res -1] << " " << value << " " << answer[res].size() << endl;
        if (blocks[res - 1] <= value)
            --res, c -= answer[res + 1].size();
        else
            break;
    }
    return res;
}

void modify(vector<int> &blocks, vector<vector<int>> &ans, int block, int value, int c, int i)
{
    cerr << "modifying\n" << block << " " << value << " " << c << " " << i << endl;
    int pos = ans[block].size();
    cerr << "pos: " << pos << endl;
    while (pos > 0)
    {
        if (a[ans[block][pos - 1]].F < value && c > 0)
            --c, -- pos;
        else 
            break;
    }
    cerr << "pos_: " << pos << endl;
    insert_after(ans[block], pos, i);
    blocks[block] = max(blocks[block], value);
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
    int n;
    scanf("%d", &n);
    vector<int> blocks;
    // vector<vector<int>> answer;
    int root = int(sqrt(ld(n)));
    
    {
        int x, y;
        scanf("%d %d", &x, &y);
        blocks.push_back(x);
        answer.push_back(vector<int> (1, 0));
        a.pb({x, y});
    }

    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb({x, y});

        int block = get_block(blocks, x, y);

        modify(blocks, answer, block, x, y, i);


        {   

            cerr << "###BLOCKS#####" << i << "#######\n";
            for (int i = 0; i < blocks.size(); ++i)
                cerr << blocks[i] << " ";
            cerr << "\n############################\n";

            cerr << "###ANSWER#####" << i << "#######\n";
            for (int i = 0; i < answer.size(); ++i)
            {
                cerr << "block " << i << ": ";
                for (int j = 0; j < answer[i].size(); ++j)
                    cerr << answer[i][j] + 1 << " ";
                cerr << endl;
            }
            cerr << "\n############################\n\n\n";
        }   


        if (i % root == 0) rebuild(answer, blocks);
    }

    for (int i = 0; i < answer.size(); ++i)
        for (int j = 0; j < answer[i].size(); ++j)
            printf("%d ", answer[i][j] + 1);
    return 0;
}