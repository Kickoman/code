class dsu
{
private:
    vector<int> parent, rnk;
public:
    void make(int n) // Builds a multiplicity of sets, n == number of nodes
    {
        parent.resize(n);
        rnk.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int getSet(int v) // Gets the set, node V belongs to
    {
        return (parent[v] == v ? v : parent[v] = getSet(parent[v]));
    }

    void uniteSet(int a, int b) // Unites set A and set B
    {
        a = getSet(a),
        b = getSet(b);

        if (a != b)
        {
            if (rnk[a] < rnk[b])
                swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b])
                ++rnk[a];
        }
    }

    dsu(int n)
    {
        make(n);
    }
};
