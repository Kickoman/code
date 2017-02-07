vector<int> prefix_function(string s)
{
    int n = int(s.size());
    vector<int> pi(n);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> z_function(string s) 
{
    int n = (int) s.size();
    vector<int> z (n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
    return z;
}

vector<int> z_to_pref(vector<int> &Z)
{
    int n = Z.size();
    vector<int> P(n);
    for(int i = 1; i < n; i++)
        if(Z[i])
            for(int j = Z[i] - 1; j >= 0 && !(P[i + j]); j--)
                P[i + j] = j + 1;
    return P;
}

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