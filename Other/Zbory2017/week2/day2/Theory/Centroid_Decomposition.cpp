/*
    Centroid Decomposition by Arthur
    Author: https://github.com/petuhovskiy
*/

const int N = 3e5;
int sz[N];
bool used[N];
vector<vector<pair<int, int>> > g;

int computeSize(int x, int pr = -1) {
    sz[x] = 1;
    for (auto to : g[x]) {
        if (to.F == pr || used[to.F]) continue;
        sz[x] += computeSize(to.F, x);
    }
    return sz[x];
}

int findCentroid(int x) {
    const int M = sz[x];
    bool run = true;
    int pr = -1;
    while (run) {
        run = false;
        for (auto to : g[x]) {
            if (to.F == pr || used[to.F]) continue;
            if (sz[to.F] >= M / 2) {
                pr = x;
                x = to.F;
                run = true;
                break;
            }
        }
    }
    return x;
}

void dfs(int v, int path, vector<int> &cnt, int p)
{
    cnt[path % 3]++;
    for (auto to: g[v])
    {
        if (to.F == p || used[to.F]) continue;

        dfs(to.F, path + to.S, cnt, v);
    }
}

void solve(int x) {
    computeSize(x);
    cerr << x << endl;
    x = findCentroid(x);

    ll a = 0, b = 0, c = 0;

    // SOME CODE

    // nie kranać
    used[x] = true;
    for (auto to : g[x]) {
        if (used[to.F]) continue;
        solve(to.F);
    }
}