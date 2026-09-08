#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    int a[25], b[25], c[25];
    c[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i){
        cout << m % a[i] << ' ';
        m /= a[i];
    }

    return 0;
}