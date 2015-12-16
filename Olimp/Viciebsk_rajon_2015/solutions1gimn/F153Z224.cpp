#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector <vector <char> > a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(m);
    int k = 0;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++, k++)
            a[i][j] = s[k];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << a[i][j];
    return 0;
}
