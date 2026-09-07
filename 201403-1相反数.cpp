#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a, b;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x > 0){
            a.push_back(x);
        }
        else if(x < 0){
            b.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int count = 0, i = 0, j = 0;
    while(count < min(a.size(), b.size())){
        if(i >= a.size() || j >= b.size()){
            break;
        }
        if(a[i] + b[j] > 0){
            j ++;
        }else if(a[i] + b[j] < 0){
            i ++;
        }else{
            count ++;
            i ++;
            j ++;
        }
    }

    cout << count << endl;
    return 0;
}