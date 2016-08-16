// Algarytm dla pošuku minimalnych adlechłaściaŭ pamiž usimi viaršyniami u grafie.

vector<vector<int>> g(n, vector<int>(n, INF)), // Matryca sumiežnaści
                    d(n, vector<int>(n, INF)), // Matryca dla Floyda
                    p(n, vector<int>(n, -1));  // Matryca prodkaŭ
                 // p[x][y] - pieradapošniaja viaršynia na šlachu z 'x' u 'y'                    

while (m--) // Čytańnie grafa 
{
	int a, b, c; // adkul, kudy, vaha
	scanf("%d %d %d", &a, &b, &c);
	--a, --b;
	if (c < g[a][b])
		g[a][b] = g[b][a] = c,
		p[a][b] = a, // zabivajem abaviazkova prodkaŭ
		p[b][a] = b;
}             

d = g; // kab nie psavać aryginalnuju matrycu (NIE ABAVIAZKOVA)

for (int i = 0; i < n; ++i)
	d[i][i] = INF; // 'ZANULAJEM' hałoŭnuju dyjaganal, kab paźbiehnuć pietlaŭ

/* UVAHA! FLOYD! */
// n - kolkaść viaršyniaŭ
for (int l = 0; l < n; ++l)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (d[i][j] > d[i][l] + d[l][j])
				d[i][j] = d[i][l] + d[l][j],
				p[i][j] = p[l][j];

// Voś i ŭvieś Floyd

/* Daŭžynia minimalnaha šlachu z viaršyni s u viaršyniu t */
int minimal_way_lng = d[s][t];


/* Atrymać sam šlach: */
vector<int> way;
way.push_back(t); // t - numar finalnaje viaršyni
while (p[s][t] != s)
{
	way.push_back(p[s][t]),
	t = p[s][t];
	cerr << t << " ";
	if (t == -1)
	{
		cerr << "PAMYŁKA! BŁAD! ERROR!\n";
		printf("\nPAMYŁKA\nPRAGRAMA SPYNIENAJA\n");
		return 1;
	}
}
way.push_back(s);
reverse(way.begin(), way.end());
