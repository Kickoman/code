#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

long long a[1000100], s=0;

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        s += a[i];
    if (s % n != 0){
        cout << "NO" << endl;
        cout << n - (s % n) << endl;
        return 0;
    }
    long long k = 0;
    s /= n;
    for (int i=0; i<n; i++){
        if (a[i] > s) k += a[i] - s;
    }
    cout << "YES" << endl << k << endl;
    return 0;
}

