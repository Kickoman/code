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

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    for (int i=0; i<n; i++){
        int j = i;
        while (j < n*m){
            cout << s[j];
            j += n;
        }
    }
    cout << endl;
    return 0;
}

