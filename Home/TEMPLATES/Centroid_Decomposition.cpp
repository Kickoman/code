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

void solve(int x) {
    computeSize(x);
    x = findCentroid(x);

    // SOME CODE

    // nie kranać
    used[x] = true;
    for (auto to : g[x]) {
        if (used[to.F]) continue;
        solve(to.F);
    }
}
