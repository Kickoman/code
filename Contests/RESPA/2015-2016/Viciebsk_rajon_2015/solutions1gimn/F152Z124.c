#include <fstream>

int main()
{
    int a,c(0),e(0);
    bool d = false;
    ifstream fin("input.txt");
    fin >> a;
    int *b = new int[a];
    for(int i(0);i < a;i++)
        fin >> b[i];
    fin.close();
    for(int i(0);i < a;i++)
        c = c + b[i];
    if(c % a == 0)
    {
        d = true;
        c = c / a;
        for(int i(0);i < a;i++)
            if(b[i] > c) e = e + (b[i] - c);
    }
    else
    {
        int M = 1,N = 10000;
        for(int i(0);i < a;i++)
            if(b[i] < N) N = b[i];
        for(int i(0);i < a;i++)
            if(b[i] > M) M = b[i];
        for(int i(N);i < M;i++)
            if(i*a > c)
            {
                e = i*a - c;
                break;
            }
    }
    ofstream fout("output.txt");
    if(b) fout << "YES";
    else fout << "NO";
    fout << endl << e;
    fout.close();
    return 0;
}
