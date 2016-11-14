// Aĺgarytm dla pošuku minimaĺnych adliechlaściaŭ pamiž usimi viaršyniami u grafie.

vector<vector<int>> g(n, vector<int>(n, INF)), // Matryca sumiežnaści
                    d(n, vector<int>(n, INF)), // Matryca dla Floyda
                    p(n, vector<int>(n, -1));  // Matryca prodkaŭ
                 // p[x][y] - pieradapošniaja viaršynia na šliachu z 'x' u 'y'                    

while (m--) // Čytańnie grafa 
{
	int a, b, c; // adkuĺ, kudy, vaha
	scanf("%d %d %d", &a, &b, &c);
	--a, --b;
	if (c < g[a][b])
		g[a][b] = g[b][a] = c,
		p[a][b] = a, // zabivajem abaviazkova prodkaŭ
		p[b][a] = b;
}             

d = g; // kab nie psavać aryginaĺnuju matrycu (NIE ABAVIAZKOVA)

for (int i = 0; i < n; ++i)
	d[i][i] = INF; // 'ZANULIAJEM' haloŭnuju dyjaganaĺ, kab paźbiehnuć pietliaŭ

/* UVAHA! FLOYD! */
// n - koĺkaść viaršyniaŭ
for (int l = 0; l < n; ++l)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (d[i][j] > d[i][l] + d[l][j])
				d[i][j] = d[i][l] + d[l][j],
				p[i][j] = p[l][j];

// Voś i ŭvieś Floyd

/* Daŭžynia minimaĺnaha šliachu ź viaršyni s u viaršyniu t */
int minimal_way_lng = d[s][t];


/* Atrymać sam šliach: */
vector<int> way;
way.push_back(t); // t - numar finaĺnaje viaršyni
while (p[s][t] != s)
{
	way.push_back(p[s][t]),
	t = p[s][t];
	cerr << t << " ";
	if (t == -1)
	{
		cerr << "PAMYLKA! BŁAD! ERROR!\n";
		printf("\nPAMYLKA\nPRAGRAMA SPYNIENAJA\n");
		return 1;
	}
}
way.push_back(s);
reverse(way.begin(), way.end());
