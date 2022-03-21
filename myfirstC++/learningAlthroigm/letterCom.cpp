#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> Map = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}};
vector<string> res;
string temp;
void dfs(int cur, string digi)
{
    if (cur >= digi.size())
    {
        res.push_back(temp);
        return;
    };
    for (char i : Map[digi[cur]-'2'])
    {
        temp += i;
        dfs(cur + 1, digi);
        temp.pop_back();
    }
    return;
}
vector<string> letterCombinations(string digits)
{
    if(digits=="") return {};
    dfs(0,digits);
    return res;
}
int main()
{
}