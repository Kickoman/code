class Treap
{
public:
    int pr;
    Treap *left, *right;
    int size;
    int value;

    void recalc()
    {

    }
    
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

        // trzeba pafixić
        if (v->left.size + 1 <= key)
        {
            l = v;
            split(v->right, key - v->left.size - 1, l->right, r);
        } else {
            r = v;
            split(v->left, key, l, r->left);
        }
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

