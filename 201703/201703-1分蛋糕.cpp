#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int a[1000],k, n;
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int i = 0, sum = 0, res = 0;
    while(i < n){
        sum += a[i];
        if(sum >= k){
            res++;
            sum = 0;
        }
        i++;
    }
    if(sum > 0) res++;

    cout << res << '\n';

    return 0;
}