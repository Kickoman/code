
vector<int> pref_to_z(vector<int> &P)
{
    int n = P.size();
    vector<int> Z(n);
    for(int i = 1; i < n; i++) // 1 krok.
        if(P[i])
                Z[i - P[i] + 1] = P[i];

    Z[0] = n;

    if(Z[1]) // 2 krok.
            for(int i = 1; i < Z[1]; i++)
                    Z[i + 1] = Z[1] - i;

    int t;
    for(int i = Z[1] + 1; i < n - 1; i++) // 3 krok.
    {
            t = i;
            if(Z[i] && !Z[i + 1])
                    for(int j = 1; j < Z[i] && Z[i + j] <= Z[j]; j++)
                    {
                            Z[i + j] = min(Z[j], Z[i] - j);
                            t = i + j;
                    }
            i = t;
    }
    return Z;
}