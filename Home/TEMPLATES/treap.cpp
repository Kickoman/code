#include <bits/stdc++.h>

using namespace std;

struct treap
{
    int key;
    int priority;

    treap * l;
    treap * r;

    treap(){}

    treap(int x)
    {
        key = x;
        priority = rand();
        l = r = nullptr;
    }
};

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

    if (l->priority > r->priority)
    {
        t = l;
        merge(l->r, r, t->r);
    } else {
        t = r;
        merge(l, r->l, t->l);
    }
}

void split(treap * t, treap *& l, treap *& r, int split_key)
{
    if (t == nullptr)
    {
        l = r = nullptr;
        return;
    }

    if (t->key <= split_key)
    {
        l = t;
        split(t->r, l->r, r, split_key);
    } else {
        r = t;
        split(t->l, l, r->l, split_key);
    }
}

void insert(treap *& t, int value)
{
    treap *l;
    treap *r;

    split(t, l, r, value);
    treap *nt = new treap(value);
    merge(l, nt, l);
    merge(l, r, t);
}

void erase(treap *& t, int key)
{
    // auto first = split(t, key);
    // auto second = split(first.first, key - 1);
    treap *a, *b;
    split(t, a, b, key);
    treap *c, *d;
    split(a, c, d, key - 1);
    merge(c, b, t);
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
    // cerr << "lll" << endl;
    if (t == nullptr)
        return;
    printTreap(t->l);
    cout << t->key << " ";
    printTreap(t->r);
}


int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    srand(time(NULL));
    treap *t = nullptr;

    int n = 15;
    for (int i = 0; i < n; ++i)
    {
        int x = rand() % 20;
        cin >> x;
        cout << x << " ";
        insert(t, x);
    }
    cout << endl;
    printTreap(t);

    cout << "\n\n";

    treap *a, *b;
    split(t, a, b, 5);
    printTreap(a);
    cout << endl;
    printTreap(b);

    cout << "\n\n";

    treap *nt;
    if (a->key < b->key) swap(a, b);
    merge(b, a, nt);
    printTreap(nt);
    
    return 0;
}