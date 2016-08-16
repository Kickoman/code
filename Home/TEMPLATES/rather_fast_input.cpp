#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int readInt()
{
    int res = 0;
    char c;
    while ((c = getchar()) < '0' || c > '9');
    res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9' && c != EOF)
        res *= 10,
        res += (c - '0');
    return res;
}

long long readLong()
{
    long long res = 0;
    char c;
    while ((c = getchar()) < '0' || c > '9');
    res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9' && c != EOF)
        res *= 10,
        res += (c - '0');
    return res;
}

double readDouble()
{
    double res = 0;
    char c;
    while ((c = getchar()) < '0' || c > '9');
    res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9' && c != EOF)
        res *= 10,
        res += (c - '0');
    cerr << fixed << setprecision(10);
    if (c == '.')
    {
        double r = 0.1;
        while ((c = getchar()) >= '0' && c <= '9' && c != EOF)
        {cerr << res << endl;
            res += (c - '0') * r,
            r /= 10;
            }
    }
    return res;
}

int main()
{
    int a = readInt();
    long long b = readLong();
    double c = readDouble();
}
