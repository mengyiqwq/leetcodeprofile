#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
     int lSubStr=0,rSubStr;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]==' ')
       {
         rSubStr=i-1;
       }
     else if(i==s.size()-1)
       {
        rSubStr=i;
       }
       else  continue;
      for(int j=lSubStr;j<=(lSubStr+rSubStr)/2;j++)
      {
          swap(s[j],s[rSubStr+lSubStr-j]);
      }
       lSubStr=rSubStr+2;
   }
   return s;
}
int main()
{
   string s="Let's take LeetCode contest";
   cout<<"结果为"<< reverseWords(s);
}