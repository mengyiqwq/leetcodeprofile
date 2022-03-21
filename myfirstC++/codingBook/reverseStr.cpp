#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseStr(string s, int k)
{
    string res="";
    stack<int>S;
    for(int i=0;i<s.size();i++)
    {  
        if((i/k)%2)//奇数时是不需要进行反转的部分
        {
           while (!S.empty())
           {
               auto cur=S.top();
               res+=cur;
               S.pop();
           }
           res+=s[i];
        }
        else 
        {
            S.push(s[i]);
        }
    }
    return res;
}
int main()
{
}