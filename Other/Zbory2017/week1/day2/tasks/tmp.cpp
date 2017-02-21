#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

template<typename _type>
_type sum(_type x, _type y)
{
	return x + y;
}

// template<typename _type>
// void make(_type x, _type y, _type (*func)())
// {
// 	cout << func(x, y) << endl;
// }

template<typename _type> 
class segtree
{
private:
	vector<_type> t;
	int n;
public:

	void build(vector<_type> &v)
	{
		for (int i = n; i < 2 * n; ++i) t[i] = v[i - n];
		for (int i = n - 1; i > 0; --i) t[i] = (*func)(t[i >> 1], t[i >> 1 ^ 1]);
	}

	segtree(vector<_type> &v)
	{
		n = int(v.size());
		t.resize(n >> 1 + 1);
	}
};

int main()
{
	freopen("task.in", "r", stdin);
	freopen("task.out", "w", stdout);
	// make(17, 29, sum);
	cout << sum(5, 2);
	// vector<int> a;
	// int n;
	// srand(time(NULL));

	// n = rand() % 10 + 1;

	// for (int i = 0; i < n; ++i)
	// 	a.push_back(rand() % 100);

	// segtree<int, sum> tree(a);
	return 0;
}