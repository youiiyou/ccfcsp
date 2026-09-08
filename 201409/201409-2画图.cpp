// #include <bits/stdc++.h>
// using namespace std;

// int n;
// struct Point {
//     double x, y;
// };
// vector<pair<Point, Point>> a;

// int main() {
//     ios::sync_with_stdio(false);   
//     cin.tie(nullptr);

//     cin >> n;
//     for(int i = 0; i < n; ++i){
//         Point p1, p2;
//         cin >> p1.x >> p1.y >> p2.x >> p2.y;
//         a.push_back({p1, p2});
//     }
//     int count = 0;
//     for(int i = 0; i < 100; ++i){
//         for(int j = 0; j < 100; ++j){
//             Point p = {(double)i + 0.5, (double)j + 0.5};
//             for(int k = 0; k < n; ++k){
//                 Point p1 = a[k].first, p2 = a[k].second;
//                 if(p.x > p1.x && p.x < p2.x && p.y > p1.y && p.y < p2.y){
//                     count++;
//                     break;
//                 }
//             }
//         }
//     }

//     cout << count << endl;
//     return 0;
// }



// #include<iostream>
// using namespace std;
// const int N=110;
// bool st[N][N];

// int main()
// {
//     int n;
//     cin>>n;
//     while(n--) // n个矩形
//     {
//         int x1,y1,x2,y2;
//         cin>>x1>>y1>>x2>>y2;
//         for(int i=x1+1;i<=x2;i++) // 涂颜色
//             for(int j=y1+1;j<=y2;j++)
//                 st[i][j]=true;
//     }
//     int res=0; // res表示涂颜色的总个数
//     for(int i=1;i<=100;i++)
//         for(int j=1;j<=100;j++)
//             if(st[i][j]==true)
//                 res++;
//     cout<<res<<endl; // 输出涂颜色的总个数
//     return 0;
// }




#include<iostream>
using namespace std;
const int N=110;
int a[N][N];

void insert(int x1,int y1,int x2,int y2) // 差分模板
{
    a[x1][y1]++;
    a[x1][y2+1]--;
    a[x2+1][y1]--;
    a[x2+1][y2+1]++;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++,y1++;//左闭右开，原本y坐标应该少一格，这里直接不用变
        insert(x1,y1,x2,y2); // 差分插入函数
    }
    int res=0; // res表示涂颜色的总个数
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]; // 前缀和
            if(a[i][j]) res++; // 染色个数加一
        }
    cout<<res<<endl; // 输出涂颜色的总个数
    return 0;
}
