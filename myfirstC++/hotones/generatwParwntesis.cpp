#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n)
{
    stack<char>S;
    vector<string>res;
    string temp="";
    for(int i=n;i>=1;i--)
    {
        int count=i;
        while (count>0)
        {
             S.push('(');
             count--;
        }
        
    }
}
int main()
{
}