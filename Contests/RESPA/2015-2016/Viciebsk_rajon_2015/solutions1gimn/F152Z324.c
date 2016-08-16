#include <fstream>

bool **Map;

bool A(int a,int b, int c)
{
    if(Map[a][b])
        return false;
    else if(c == 0)
        return true;
    return (!A(a-1,b,c-1) && !A(a,b-1,c-1) && !A(a-1,b-1,c-1));
}

int main()
{
    ifstream fin("input.txt");
    int M,N;
    fin >> N >> M;
    Map = new bool*[N];
    for(int i(0);i < N;i++)
        Map[i] = new bool[M];
    for(int i(0);i < N;i++)
        for(int j(0);j < M;j++)
            fin >> Map[i][j];
    fin.close();
    int e = 0;
    for(int i(0);i < N;i++)
        for(int j(0);j < M;j++)
            for(int l(0);l < M && l < N;l++)
                if(A(j,i,l)) e++;
    ofstream fout("output.txt");
    fout << e;
    fout.close();
    return 0;
}
