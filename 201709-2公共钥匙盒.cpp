#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    map<int, vector<int>> a, b;
    int w, s, c, maxt = 0;
    for(int i = 0; i < k; i++){
        cin >> w >> s >> c;
        c += s;
        maxt = max(maxt, c);
        a[s].push_back(w);
        b[c].push_back(w);
    }

    vector<int> ans(n);
    for(int i = 0; i < n; ++i){
        ans[i] = i + 1;
    }

    for(int i = 0; i <= maxt; ++i){
        if(b[i].size() > 0){
            sort(b[i].begin(), b[i].end());
            for(int j = 0; j < b[i].size(); ++j){
                for(int l = 0; l < n; ++l){
                    if(ans[l] == 0){
                        ans[l] = b[i][j];
                        break;
                    }
                }
            }
        }

        if(a[i].size() > 0){
            for(int j = 0; j < a[i].size(); ++j){
                for(int l = 0; l < n; ++l){
                    if(ans[l] == a[i][j]){
                        ans[l] = 0;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}