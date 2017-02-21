#include <bits/stdc++.h>

using namespace std;

class Treap
{
public:
    int key, pr;
    Treap *left, *right;
    
    static Treap *merge(Treap *l, Treap *r)
    {
        Treap *res;

        if (l == nullptr)
        {
            res = r;
            return res;
        }
        if (r == nullptr)
        {
            res = l;
            return res;
        }

        if (r->pr > l->pr)
        {
            res = r;
            res->left = merge(l, r->left);
        } else {
            res = l;
            res->right = merge(l->right, r);
        }

        recalc(res);
    }   

    //                  zychodnaje dreva, kliuč, vyniki
    static void split(Treap *v, int key, Treap *&l, Treap *&r)
    {
        if (v == nullptr)
        {
            l = r = nullptr;
            return;
        }

        if (v->key <= key)
        {
            l = v;
            split(v->right, key, l->right, r);
        } else {
            r = v;
            split(v->left, key, l, r->left);
        }
    }

    void add(Treap *&t, int x)
    {
        Treap *l;
        Treap *r;
        split(t, x, l, r);
        Treap 
    }

    /*
        dadać značeńnie:
        1. split dreva pa kliučy X
        2. mergym vyniki l + new + r
    */

    /*
        vydalić značeńnie:
        1. split pa kliučy X
        2. u vynikach.R - x užo niama.
           split vynik.L pa (x - 1)
        3. mergym vyniki
    */
};

int main()
{
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);



    return 0;
}