#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path)
{
    vector<string> Q;
    string temp = "";
    path+='/';
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
        {
            if (temp == "." || temp == "")
            {
                temp = "";
                continue;
            }
            else if (temp == "..")
            {
                if (!Q.empty())
                    Q.pop_back();
            }
            else
                Q.push_back(temp);
            temp = "";
        }
        else
            temp += path[i];
    }
    // if (temp == ".." && !Q.empty())
    // {
    //     Q.pop_back();
    //     temp="";
    // }
    string res = "";
    for (string i : Q)
    {
        res += '/';
        res += i;
    }
    if (res == "")
        res += '/';
    // if (temp != ""||temp!=".")
    //     res += temp;
    return res;
}
int main()
{
}