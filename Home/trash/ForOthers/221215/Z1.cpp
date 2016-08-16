/**
  *     gównokod by candelabra
***/

#include <iostream>
#include <cstdio>
#include <string>

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

const int INF = (int) 1e7;

string min_cyclic_shift (string s) {
	s += s;
	int n = (int) s.length();
	int i=0, ans=0;
	while (i < n/2) {
		ans = i;
		int j=i+1, k=i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j])
				k = i;
			else
				++k;
			++j;
		}
		while (i <= k)  i += j - k;
	}
	return s.substr (ans, n/2);
}

int main()
{
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << min_cyclic_shift(s);
    return 0;
}
