#include <iostream>
#include <cstdio>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>

#define F first
#define S second
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1000000000; // 10^9
const long long llINF = 10000000000000000ll; // 10^16
const int SWAG = 228;
const int LEET = 1337;

//                  N  E  S   W  NE SE  SW  NW
const int sx[8] = {-1, 0, 1,  0, -1, 1,  1, -1};
const int sy[8] = { 0, 1, 0, -1,  1, 1, -1, -1};

string ans, s;
vector<bool> used;

int main()
{
//  ios_base::sync_with_stdio(0);
//#ifdef LOCAL
//  freopen("task.in", "r", stdin);
//  freopen("task.out", "w", stdout);
//  #define debug(...) printf(__VA_ARGS__)
//#else
//  freopen("arsenal.in", "r", stdin);
//  freopen("arsenal.out", "w", stdout);
//  #define debug(...)
//#endif //LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k;
	scanf("%d\n", &k);
	getline(cin, s);
	int x = 0, start = 0, pl = (k - 1) * 2;
	used.resize(s.size() + pl);
	queue<int> q;
	for (int i = 0; i < s.size() + pl; i += pl)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		used[cur] = true;
		if (cur < s.size())
		{
			ans += s[cur];
		}
		if (cur > 0 && (!used[cur - 1]))
		{
			q.push(cur - 1);
			used[cur - 1] = true;
		}
		if (cur < s.size() - 1 && !used[cur + 1])
		{
			q.push(cur + 1);
			used[cur + 1] = true;
		}
	}
	cout << ans;
	return 0;
}
