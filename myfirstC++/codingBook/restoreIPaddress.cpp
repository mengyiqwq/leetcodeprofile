#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> res;
vector<int> temp;
void dfs(int first, string s, int maxlen, int minlen, int cnt)
{
    if (cnt == 1)
    {
        string ss = s.substr(first, s.size() - first);
        if ((ss[0] == '0' && ss != "0")||ss==""||ss.size()>3)
            return;
        int _int = stoi(ss);
        if (_int >= 0 && _int <= 255)
        {
            string str = "";
            for (int i : temp)
            {
                str += to_string(i);
                str += '.';
            }
            str += to_string(_int);
            res.push_back(str);
        }
        return;
    }

    for (int i = minlen; i <= maxlen; i++)
    {
        if (first+i >= s.size())
            return;
        string str = s.substr(first, i);
        if ((str[0] == '0' && str != "0")||str==""||str.size()>3)
            return;
        int _int = stoi(str);
        if (_int >= 0 && _int <= 255)
        {
            temp.push_back(_int);
            dfs(first + i, s, maxlen, minlen, cnt - 1);
            temp.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s)
{
    //    优化剪枝，求出最少取得长度
    int minlen = 1;
    int maxlen = 3;
    dfs(0, s, maxlen, minlen, 4);
    return res;
}
int main()
{
    string s = "0279245587303";
    restoreIpAddresses(s);
}