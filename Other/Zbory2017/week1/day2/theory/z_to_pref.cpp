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
