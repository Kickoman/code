T = 70; // pačatkovaja temperatura [5; 100]
m = 40; // koĺkaść iteracyjaŭ [20; 200]
K = 0.997; // kaeficyjent (amaĺ kanstanta, prykladna takaja musi być zaŭždy)
E = f(start); // horaj stan - boĺš značeńnie funkcyi

while (T > 1e-3) // 1e-3 - možna pahuliacca ŭ dyjapazonie [1e-3, 1e-1]
{
    T *= K;
    for (int i = 0; i < m; ++i)
    {
        cur -> next; // stan
        Enew = f(next);

        if (Enew < E || FORMULA)
        {
            E = Enew;
            if (E < Ebest)
            {
                Ebest = E;
                cur = next;
            } else {
                // spytaj u Zachara
            }
        }
    }
}

// Niejkaja Luchta nasamreč. Ničoha narmaĺna nie patlumačyŭ, alie liepš za niekatorych.