#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> cellsInRange(string s)
{
    char max_c='A';//k
    char min_c='Z';
    char max_r='1';
    char min_r='9';
    for(char i:s)
    {
        if(i==':')
        continue;
        if(i>='A'&&i<='Z')
        {max_c=max(i,max_c);
        min_c=min(i,min_c);}
        if(i>='1'&&i<='9')
        {max_r=max(i,max_r);
        min_r=min(i,min_r);}
    }
    vector<string>res;
    for(char i=min_c;i<=max_c;i++)
    {
        for(char j=min_r;j<=max_r;j++)
        {
            string temp="";
            temp+=i;
            res.push_back(temp+j);
        }
    }
    return res;
}
int main()
{
    string s="K1:L2";
    cellsInRange(s);
}