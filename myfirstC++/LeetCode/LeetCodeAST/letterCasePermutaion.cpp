#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 注意asii码，字母小写的更大
string temp;
vector<string> res;
void dfs(int cur, string s)
{
    if (cur > s.size() - 1)
    {
        res.push_back(temp);
        return;
    }
    if (s[cur] < 'A')
    {
        dfs(cur + 1, s);
        return;
    }
    temp[cur]= s[cur];
    dfs(cur + 1, s);
    if(temp[cur]>='a')
    temp[cur]= (s[cur] + 'A' - 'a');
    else temp[cur]=(s[cur]+'a'-'A');
    dfs(cur + 1, s);
}
vector<string> letterCasePermutation(string s)
{   temp=s;
    dfs(0, s);
    return res;
}
int main()
{
    vector<string> r;
    string s = "C";
    r = letterCasePermutation(s);
    cout << s;
}