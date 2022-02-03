#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 数组哈希还是更快些
bool canConstruct(string ransomNote,string magazine)
{
    unordered_map<char,int>Map;
    for(char i:magazine)
    {
       Map[i]++;
    }
    for(char i:ransomNote)
    {
       if(Map[i]>0)
       Map[i]--;
       else
       return false;
    }
    return true;
}
int main()
{
}