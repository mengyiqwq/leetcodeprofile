#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
// 暴力遍历法，进行子串拆解，然后利用字符串的翻转来进行确认是否为回文串，找最长，时间复杂度为O(n^3)
string longestStr(string s)
{
  string temp="";
  string res="";
  for(int i=0;i<s.length();i++)
   {
    
     for(int j=i;j<s.length();j++)
     { 
        temp=temp+s[j];
        string t=temp;
        reverse(t.begin(),t.end());
        if(t==temp)
        {
            res=temp.length()>res.length()?temp:res;
        }
     }
     temp="";
   }
   return res;
}
// 动态规划方法,动态规划则是通过记录（可通过二维矩阵的方式）每一次的子串是否构成回文串，
// 然后在每次进行更高长度的子串时利用上一次记录的结果，是通过将空间换取时间的方式，
string LongestStr(string s)
{
    int n=s.size();
    vector <vector<int> > dp(n,vector<int>(n));
    int maxLen=0;
    int maxleft=0;
    for (int length = 0; length <n ; length++)
    {   
       for (int left = 0; left+length < n; left++)
       {
           int right=left+length;
           if(length==0)
           {
               dp[left][right]=1;//如果只有长度为1的子串，均构成回文串
           }
           else if(length==1)//子串长度为2时，相等即可得到回文串
           {
               if(s[left]==s[right])
               dp[left][right]=1;
               else
                dp[left][right]=0;
           }
           else //对于大于3为剩余情况
           {
             if(s[left]==s[right]&&dp[left+1][right-1])//对于矩阵，所有需要记录的均分布在左下角
            //  而子串长度为1时放在对角线，为2时放在对角线的下面那斜线，依次类推，对于每个dp点右上角
            //上对应的就是其子串是否为回文串的记录
             dp[left][right]=1;
             else
             dp[left][right]=0;
           }
            if(dp[left][right]&&maxLen<length+1)
            {maxLen=length+1;
             maxleft=left;
            }
       }
       
    }
    return s.substr(maxleft,maxleft+maxLen);
}
//  中心扩散得到的最大回文串长度
int MaxHuiStr(string s,int left,int right)
{
  while (left>=0&&right<s.length()&&s[left]==s[right])
  {
      left--;
      right++;
  }
  return right-left-1;//此处要注意left从0会变成-1，因此通过演算得到要-1才是真正长度
}
// 中心扩散法
string LOngestStr(string s)
{
    int maxsubstr=0;
    int left=0;//存结果的左标
    int right=0;//存结果的右标
    for(int i=0;i<s.length();i++)
    {
      int Len1=MaxHuiStr(s,i,i);//单元素为中心的回文串最大长度
      int Len2=MaxHuiStr(s,i,i+1);//双元素为中心的回文串最大长度
      maxsubstr=maxsubstr>max(Len1,Len2)?maxsubstr:max(Len1,Len2);
      if(maxsubstr>right-left+1)//如果现在更新后的最大回文串长度大于曾经记录下扩散的回文串长度，
    //   将存放的结果左标及右标也更新
      {
          left=i-(maxsubstr-1)/2;//此处的减1主要因为对于双元素中心，默认第一次遇到和第二次遇到为选取情况
        //   根据举例可验证出要-1才是刚好满足条件
          right=i+(maxsubstr)/2;
      }
    }
    return s.substr(left,maxsubstr);
 }
 int max(int num1,int num2)
 {
     if(num1>num2)
     return num1;
     else return num2;
 }

int main()
{
    string a="faaddaa";
    cout<<longestStr(a)<<endl;
    cout<<LongestStr(a)<<endl;
    cout<<LOngestStr(a);
}