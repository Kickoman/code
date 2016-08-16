#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);

    int  n , m;
    char c = ' ';
    cin >> n >> m;
    char s[ (n * m) + 1];
    int l = n * m;
    int i;
    for (i = 0; i < l ;i++){
        cin >> s[i];
    }

    i = 0;
    while (i<n){
        int j=i;
        while (j<l){
            cout << s[j];
            j+=n;
        }
        i++;
    }

    cout << endl;

    return 0;
}

