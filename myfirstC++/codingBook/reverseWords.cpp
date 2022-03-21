#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    // 答案是去记录每一个有效的单词
    int length = 0;
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (!length)
                continue;
            else
            {
                res += ' ';
                res += s.substr(i+1, length);
                length = 0;
            }
        }
        else
            length++;
    }
    if (length)
    {
        res += ' ';
        res += s.substr(0, length);
    }
    if(res[0]==' ') res.erase(res.begin());
    return res;
}
int main()
{
}