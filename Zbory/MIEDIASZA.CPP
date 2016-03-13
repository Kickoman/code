next[alph] // spasyłki // O(l) M(l * alph);

a možna 
map<char, int> next; // tak my budziem zachoŭvać tolki tyja spasyłki, jakija my majem   // O(L * log(alph)); M(L);

/* 
    Kali alfabet, naprykład, roŭny 26 (tolki łacinskija maleńkija litary), to lepiej pisaci pieršy varyjant (int next[alph]);
    Kali ž alfabet, naprykład, 100, dyk tady ŭžo lepiej pisać map;
*/

    /* Jeśli chcesz, mogę pisać i po-polsku */

int v = 0;
for (int i = 0; i < l - 1; ++i) // l - daŭžynia radka
{
    if (next[v][int(s[i]] - 'a') == -1)
    {
        next[v][s[i]] = sz;
        init(sz);
        sz++;
    }
    v = next[v][s[i]];
}
leaf[v] = 1;

r = 0;
for (int i = 0; i < n - 1; ++i)
    if (next[v][s[i]] == -1)
        return -1;
    r =  next[v][s[i]];
return num[v];