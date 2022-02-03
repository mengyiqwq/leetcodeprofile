#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 哈希,或者使用数组哈希更快
int firstUniqChar(string s)
{
    unordered_map<char, int> Map;
    for(char i:s)
    {
        Map[i]++;
    }
    for(int i;i<s.size();i++)
    {
      if(Map[i]>=2)
       continue;
      else 
      return i;
    }
    return -1;
}
// 使用哈希加上队列，使用延迟删除也可以
int main()
{
}