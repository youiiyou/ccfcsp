#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int n, count = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; ++i){
        if(a[i + 1] - a[i] == 1){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}