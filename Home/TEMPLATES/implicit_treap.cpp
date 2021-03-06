#include <bits/stdc++.h>

#define TASK "task"

#define S second
#define F first
#define mp make_pair

#ifndef LOCAL
#define cerr if(0)cerr
#endif // LOCAL

using namespace std;

struct treap
{
    int size;
    int priority;
    int key;

    treap * l;
    treap * r;

    treap(){}

    treap(int x)
    {
        key = x;
        size = 1;
        priority = rand();
        l = r = nullptr;
    }
};

int getSize(treap *t)
{
    return t == nullptr ? 0 : t->size;
}

void update(treap *& t)
{
    if (t == nullptr) return;
    t->size = getSize(t->l) + getSize(t->r) + 1;
    return;
}

void merge(treap * l, treap * r, treap *& t)
{
    if (l == nullptr)
    {
        t = r;
        return;
    }

    if (r == nullptr)
    {
        t = l;
        return;
    }

    update(l);
    update(r);

    if (l->priority > r->priority)
    {
        t = l;
        update(l);
        merge(l->r, r, t->r);
    } else {
        t = r;
        update(r);
        merge(l, r->l, t->l);
    }
    update(t);
}

pair<treap*, treap*> split(treap* t, int split_key)
{
    if (t == nullptr)
        return {nullptr, nullptr};
    if (getSize(t->l) <= split_key)
    {
        pair<treap*, treap*> right = split(t->r, split_key - getSize(t->l) - 1);
        t->r = right.first;
        right.first = t;
        update(right.first);
        update(right.second);
        return right;
    } else {
        pair<treap*, treap*> left = split(t->l, split_key);
        t->l = left.second;
        left.second = t;
        update(left.first);
        update(left.second);
        return left;
    }

}

void insert(treap *& root, int key, int pos)
{
    pair<treap*, treap*> spl = split(root, pos - 1);
    merge(spl.first, new treap(key), spl.first);
    merge(spl.first, spl.second, root);
}

void erase(treap *& t, int key)
{
    auto first = split(t, key);
    auto second = split(first.first, key - 1);
    merge(second.first, first.second, t);
}


int find(treap *t, int value)
{
    if (t == nullptr)
        return -1;

    if (t->key < value)
        return find(t->r, value);
    
    int nt = find(t->l, value);

    if (nt != -1)
        return nt;

    return t->key;
}

void printTreap(treap *t)
{
    if (t == nullptr)
        return;
    printTreap(t->l);
    cout << t->key << " ";
    printTreap(t->r);
}

void printSz(treap *t)
{
    if (t == nullptr)
        return;
    printSz(t->l);
    cout << t->size << " ";
    printSz(t->r);
}

int main()
{
#ifdef LOCAL
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    // freopen(TASK ".err", "w", stderr);
#endif
    int n, m;
    scanf("%d %d", &n, &m);

    treap *t = nullptr;
    for (int i = 0; i < n; ++i)
        insert(t, i + 1, i);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        auto first = split(t, r);
        auto second = split(first.first, l - 1);
        merge(second.second, second.first, t);
        merge(t, first.second, t);
    }
    printTreap(t);=
    return 0;
}