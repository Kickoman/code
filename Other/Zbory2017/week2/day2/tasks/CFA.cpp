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
    set<string> folders, files;
    for (int i = 0; i < n; ++i)
    {
        string folder;
        cin >> folder;
        // if (folder.size() > 1 && folder.back() == '/')
        //     folder.pop_back();
        
        string buffer;
        cerr << "current: " << folder << endl;
        for (int j = 0; j < folder.size(); ++j)
        {
            buffer += folder[j];
            cerr << buffer << " " << folder[j] << " " << j << " " << folder.size() << endl;
            if (folder[j] == '/' && j > 0)
            {
                buffer.pop_back();
                cerr << "adding: " << buffer << endl;
                folders.insert(buffer);
                buffer += '/';
            }
        }
    }
    folders.insert("/");

    int m;
    cin >> m;
    while (m--)
    {
        string command, path;
        cin >> command >> path;

        if (path.size() > 1 && path.back() == '/')
            path.pop_back();

        // cerr << path << endl;

        if (command == "CREATE")
        {
            files.insert(path);
        } else {
            // if (folders.count(path) > 0)
            // {
            //     cout << "Directory\n";
            // } else {
            //     cout << "File\n";
            // }
            if (files.count(path) > 0)
            {
                cout << "File\n";
            } else {
                cout << "Directory\n";
            }
        }
    }
    return 0;
}