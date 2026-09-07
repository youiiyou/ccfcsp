#include<bits/stdc++.h>
using namespace std;
int n;
string s;
unordered_map<char,int> mp;
// mp[c]=1：无参选项；mp[c]=2：带参选项
void work()
{
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]==' ') break;
        if(s[i]!=':' && s[i+1]==':') mp[s[i]]=2;    //有参字符，标记为2
        else
            if(s[i]!=':') 
                mp[s[i]]=1; //无参字符，标记为1
    }
}
int main()
{
    cin>>s;
    s=s+' ';   // 手动末尾加空格，配合work循环判断break
    work();
    cin>>n;
    getchar(); // 吃掉n后面的换行符，防止getline读空行

    for(int i=1;i<=n;i++)
    {
        map<char,string> mq;    // map自带key升序！存本次解析到的选项:值；无参就存占位字符串
        getline(cin,s);
        stringstream ssin(s);
        vector<string> str;     
        while(ssin>>s) str.push_back(s); // 按空格切割全部字符串存入str
        
        // str[0]是程序名ls，j从1开始遍历选项部分
        for(int j=1;j<str.size();j++)   
        {
            // 判断是否形如 -x；str[j][0]='-'，长度必须等于2，第二个是小写字母
            if(str[j][0]!='-' || str[j][1]<'a' || str[j].size()!=2) break;  

            char c=str[j][1];
            if(mp[c]==1){
                mq[c]=c;   //无参选项，存入map；重复会覆盖，自动保留最后一次
            }
            else if(mp[c]==2 && (j+1)<str.size()){ 
                mq[c]=str[j+1]; //保存参数
                j++;   //消耗掉参数，j向后跳一格
            }
            else {
                break;     //不合法，停止解析
            }
        }
        cout<<"Case "<<i<<":";
        for(auto x:mq)
            if(mp[x.first]==1) 
                cout<<" -"<<x.first;    
            else 
                cout<<" -"<<x.first<<" "<<x.second;    
        cout<<endl;
    }
    return 0;
}
