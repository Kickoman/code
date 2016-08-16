#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define F first
#define S second

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return (a.F == b.F ? a.S < b.S : a.F > b.F);
}

int sti(string s)
{
	int res = 0, nop = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			nop = i;
			break;
		}
		res = res * 10 + (int) (s[i] - '0');
	}
	if (nop < 0)
		res *= 100;
	else
	{
		int k = 0;
		for (int i = nop + 1; i < s.size(); ++i)
			res = res * 10 + (int) (s[i] - '0'),
			k++;
		for (int i = k; i < 2; ++i)
			res *= 10;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<int> p(n), q(n);
	int nou = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		nou += p[i];
	}
	for (int i = 0; i < n; ++i)
		cin >> q[i];

	vector<vector<pair<int, int> > > users(n);

	for (int i = 0; i < nou; ++i)
	{
		int uid, gid;
//		double a, b, c, d;
		string a, b, c, d;
		cin >> uid >> gid >> a >> b >> c >> d;
		int w = sti(a) + sti(b) + sti(c) + sti(d);

		--gid;
		users[gid].push_back(make_pair(w, uid));
	}

	vector<pair<int, int> > ans;

	for (int i = 0; i < n; ++i)
	{
		sort(users[i].begin(), users[i].end(), comp);
//		cerr << users[4][0].F << " " << users[4][1].F << endl;
		int a = users[i][q[i] - 1].F;
		for (int j = 0; j < users[i].size() && users[i][j].F >= a && users[i][j].F > 0; ++j)
			ans.push_back(users[i][j]);
	}

	sort(ans.begin(), ans.end(), comp);

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].S << " " << (double) ans[i].F / 100  << "\n";

	return 0;
}
