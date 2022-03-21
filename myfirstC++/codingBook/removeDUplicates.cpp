#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s)
{
    // 把不一样的往栈里面塞
    vector<char> S;
    for (char i : s)
    {
        if (!S.empty())
        {
            if (S.back() == i)
            {
                S.pop_back();
                continue;
            }
        }
        S.push_back(i);
    }
    string res = "";
    for(char i:S)
    res+=i;
    return res;
}
int main()
{
}