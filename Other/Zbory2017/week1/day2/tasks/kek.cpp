#include <bits/stdc++.h>

using namespace std;

void kek(int &govno, int &parasha)
{
    govno *= 2;
    parasha /= 4;
    return;
}

int main()
{
    int x = 4;
    int y = 24;
    kek(x, y);
    cout << x << " " << y << endl;
    return 0;
}