#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


#define INF (1<<30)
#define INFll (1ll<<62)
#define F first
#define S second
#define MOD 1000000007
#define mkp(a, b) make_pair(a, b)


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define FOR(I, A, B) for(int (I) = (A); (I) < (B); (I)++)
#define ROF(I, A, B) for(int (I) = (A); (I) >= (B); (I)--)
#define SQR(A) 1ll*(A)*(A)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const char array_sep[] = "\n";
const char array_end[] = "";


const char pair_sep[] = " ";
const char pair_end[] = "";


const char map_sep[] = "->";
const char map_end[] = "\n";


const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};


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


template<typename _response> void die(_response ans)
{
    cout << ans << endl;
    exit(0);
}

class Treap
{
public:
    Treap* l = nullptr;
    Treap* r = nullptr;
    int key;
    int prior;
    int cnt = 1;

    Treap() {}
    Treap(int x) : key(x), prior(rand()) {};
};

int sizeOf(Treap* res)
{
    return (res == nullptr ? 0 : res->cnt);
}

void cnt(Treap* res)
{
    if(res == nullptr) return;
    res->cnt = sizeOf(res->l) + sizeOf(res->r) + 1;
}

Treap* merge(Treap* L, Treap* R)
{
    if(L == nullptr) return R;
    if(R == nullptr) return L;

    cnt(L);
    cnt(R);

    if(L->prior >= R->prior)
    {
        L->r = merge(L->r, R);
        cnt(L);
        return L;
    }
    else
    {
        R->l = merge(L, R->l);
        cnt(R);
        return R;
    }
}

pair<Treap*, Treap*> split(Treap* res, int key)
{
    if(res == nullptr) return mkp(nullptr, nullptr);

    if(sizeOf(res->l) <= key)
    {
        pair<Treap*, Treap*> rightSplit = split(res->r, key - sizeOf(res->l) - 1);
        res->r = rightSplit.F;
        rightSplit.F = res;
        cnt(rightSplit.F);
        cnt(rightSplit.S);
        return rightSplit;
    }
    else
    {
        pair<Treap*, Treap*> leftSplit = split(res->l, key);
        res->l = leftSplit.S;
        leftSplit.S = res;
        cnt(leftSplit.F);
        cnt(leftSplit.S);
        return leftSplit;
    }
}

Treap* add(Treap* root, int key, int pos)
{
    pair<Treap*, Treap*> spl = split(root, pos-1);
    spl.F = merge(spl.first, new Treap(key));
    return merge(spl.first, spl.second);
}

int get(Treap*& root, int pos)
{
    auto spl = split(root, pos);
    cerr << "# " << sizeOf(spl.F) << ":" << sizeOf(spl.S) << endl;
    if(sizeOf(spl.F) == 1)
    {
        int res = spl.F->key;
        root = merge(spl.F, spl.S);
        return res;
    }

    auto leftSpl = split(spl.F, pos-1);
    int result;

    result = leftSpl.S->key;

    root = merge(merge(leftSpl.F, leftSpl.S), spl.S);
    return result;
}

void printTreap(Treap* res)
{
    if(res == nullptr) return;

    printTreap(res->l);
    cerr << res->key << " ";
    printTreap(res->r);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("errlog.log", "w", stderr);
    ios_base::sync_with_stdio(0);
//  cout << fixed << setprecision(3);
//  srand(time(0));

    Treap* res = nullptr;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res = add(res, x, i);

    }

    for(int i = 0; i < n; i++)
        cerr << get(res, i) << endl;
    return 0;
}