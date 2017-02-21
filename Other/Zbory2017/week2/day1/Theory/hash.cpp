const int MOD = int(1e9) + 7;
const int MOD1 = int(1e9) + 9;

ll p = rand() | 1;
pair<ll, ll> p_pow[MAXN]; // compute this before;

struct Hash {
    int n;
    vector<pair<int, int> > hash;
    
    Hash() {
        n = 0;
    }
    
    Hash(string s) {
        n = (int)s.size();
        hash.resize(n);
        for (int i = 0; i < n; i++) {
            hash[i].F = (i ? (1ll * hash[i - 1].F * p % MOD) : 0);
            hash[i].F += 1ll * (s[i] - 'a' + 1) % MOD;
            hash[i].F %= MOD;
            
            hash[i].S = (i ? (1ll * hash[i - 1].S * p % MOD1) : 0);
            hash[i].S += 1ll * (s[i] - 'a' + 1) % MOD1;
            hash[i].S %= MOD1;
            
            if (hash[i].F < 0) hash[i].F += MOD;
            if (hash[i].S < 0) hash[i].S += MOD1;
        }
    }
    
    pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        int h1 = hash[r].F;
        if (l) h1 -= 1ll * hash[l - 1].F * p_pow[len].F % MOD;
        h1 %= MOD;
        if (h1 < 0) h1 += MOD;
        
        int h2 = hash[r].S;
        if (l) h2 -= 1ll * hash[l - 1].S * p_pow[len].S % MOD1;
        h2 %= MOD1;
        if (h2 < 0) h2 += MOD1;
        return {h1, h2};
    }
    
    
    pair<int, int> getHash() {
        return hash[n - 1];
    }
};