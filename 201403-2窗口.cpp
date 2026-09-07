#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    struct Point{
        int x, y;
    };
    vector<int> ans;
    vector<pair<Point, Point>> a;
    for(int i = 0; i < n; ++i){
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        a.push_back({p1, p2});
        ans.push_back(i + 1);
    }

    for(int i = 0; i < m; ++i){
        Point p;
        cin >> p.x >> p.y;
        int flag = 0, index = 0;
        pair<Point, Point> item;
        for(int j = n - 1; j >= 0; --j){
            if(p.x >= a[j].first.x && p.x <= a[j].second.x && p.y >= a[j].first.y && p.y <= a[j].second.y){
                cout << ans[j] << endl;
                flag = 1;
                index = j;
                item = a[j];
            }
            if(flag) break;
        }
        if(!flag) cout << "IGNORED" << endl;
        else{
            a.erase(a.begin() + index);
            a.push_back(item);
            int temp = ans[index];
            ans.push_back(temp);
            ans.erase(ans.begin() + index);
        }

    }

    return 0;
}