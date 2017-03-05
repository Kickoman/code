#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int readInt()
{
    int res = 0;
    char c;
    while (!isdigit(c = getchar()) && c != EOF);
    if (c == EOF)
        return -228;

    res = c - '0';
    while (isdigit(c = getchar()))
        res *= 10,
        res += (c - '0');
    return res;
}

long long readLong()
{
    long long res = 0;
    char c;
    while (!isdigit(c = getchar()) && c != EOF);
    if (c == EOF)
        return -228;
    while (isdigit(c = getchar()))
        res *= 10,
        res += (c - '0');
    return res;
}

long double readDouble()
{
    long double res = 0;
    char c;
    while (!isdigit(c = getchar()) && c != EOF);
    if (c == EOF)
        return -228;

    res = c - '0';
    while (isdigit(c = getchar()))
        res *= 10,
        res += (c - '0');
        
    if (c == '.')
    {
        long double r = 0.1;
        while (isdigit(c = getchar()))  
            res += (c - '0') * r,
            r /= 10;
    }
    return res;
}
int main()
{
    int a = readInt();
    long long b = readLong();
    double c = readDouble();
}
