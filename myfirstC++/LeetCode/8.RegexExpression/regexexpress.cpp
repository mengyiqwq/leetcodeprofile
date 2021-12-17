#include <iostream>
#include <string>
#include <vector>
#include <typeinfo> 
using namespace std;
// 动态规划一般使用二维数组，然后根据前面的元素对下一些值进行计算，写出状态转移方程
bool isMatch(string s, string p)
{
    int m=s.size();
    int n=p.size();
    //匹配规则函数
    auto matches =[&](int i,int j)
    {
        if(i==0)//对于0，0位置上当作空字符，不匹配
       return false;
       if(p[j-1]=='.')//当匹配到.时无论i为什么均当作成功
       return true;
       return s[i-1]==p[j-1];//对于
    };
    vector<vector<int>>f(m+1,vector<int>(n+1));//创建一个m+1,n+1的表来记录
    f[0][0]=true;//当均为空串时为匹配
    for (int i = 0; i <=m; i++)//对于s串，被验证串当i为0时作为结束条件
    {
       for(int j=1;j<=n;j++)//对于p串中从第1个字符开始
       {
         if(p[j-1]=='*')
         {
             f[i][j]|=f[i][j-2];//当不匹配的情况，可以将星号和数字一起去掉
             if(matches(i,j-1))
             {
                 f[i][j]|=f[i-1][j];//当匹配时，则只匹配后跳过该字符看看后面还有没有一样的字符
             }
         }
         else if(matches(i,j))
         {
             f[i][j]|=f[i-1][j-1];//一般情况下只需要对上一个串进行匹配
         }
       }
        
    }
    return f[m][n];
}
int main()
{
    string a = "daf";
    string b = "dafd*";
    cout << isMatch(a, b);
    // cout<<(a==b);
}