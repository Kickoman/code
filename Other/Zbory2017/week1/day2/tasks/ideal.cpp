#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair

bool check(const vector<int>& t, int a, int b, const vector<int>& bi, const vector<int>& sm)
{
    if(bi[a] != -1 && t[b] > t[b-(a - bi[a])])
        return false;
    if(sm[a] != -1 && t[b] < t[b-(a - sm[a])])
        return false;
    return true;
}

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


vector <int> pref(vector <int> a, vector <int> b)
{
    int n = a.size();
    vector<int> p(n);
    vector<int> res, bi, sm;
    bas(a, &bi, &sm);
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && !check(a, j, i, bi, sm))
            j = p[j - 1];
        if (check(a, j, i, bi, sm))
            j++;
        p[i] = j;
    }
    int ans = 0;
    for(int i = 0; i < b.size(); i++)
    {
        while(ans && !check(b, ans, i, bi, sm))
            ans = p[ans-1];
        if(check(b, ans, i, bi, sm))
            ans ++;
        if(ans == n)
        {
            res.push_back(i - n + 1);
            ans = p[ans - 1];
        }
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector <int> p(n), t(m);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        p[x] = i;
    }
    for (int i = 0; i  < m; i++)
        cin >> t[i];
    vector <int> ans = pref(p, t);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';
}