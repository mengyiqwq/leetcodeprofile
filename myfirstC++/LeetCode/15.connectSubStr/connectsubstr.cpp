#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// 解法一.遍历法，双重循环，编历第一个单词的长度，对每个字母进行哈希建表等长度得进行不断判断
// 思路为一个字母一个字母移动目标大小的子串，再每次比较循环看看该子串是否满足要求，使用哈希表
// 该时间复杂度为O(n*m),空间复杂度为O(m),最后记得验证子串和原来子串相等
vector<int> findSubstring(string s, vector<string> &words)
{
  // 将数组中的值初始化在哈希表中
  map<string, int> Map;
  vector<int> res;
  if (words.size() == 0)
    return res;
  for (string i : words)
  {
    Map[i]++;
  }
  int singlesize = words[0].size();
  int totalsize = words.size();

  map<string, int> tempMap;
  for (int i = 0; i + singlesize * totalsize <= s.size(); i++) //对于目标结果串长度小于被验证串
  {
    int j = 0;
    for (j = i; j < i + singlesize * totalsize; j += singlesize) //对于每次被验证的目标串长度
    {
      string tempStr = s.substr(j, singlesize); //取j开始的第一个子串
      if (Map[tempStr] == 0)
        break; //m1中没有该子串时跳出,将整个目标结果后移一个字母
      else
      {
        tempMap[tempStr]++;
        if (Map[tempStr] < tempMap[tempStr])
          break;
      }
    }
    if (j == i + singlesize * totalsize)
      res.push_back(i);
    tempMap.clear();
  }
  return res;
}
// 优化，每次移动一个Word的长度，当目标串可以匹配时，往后移动寻找其它匹配的目标串，
// 当不能匹配时，在不能匹配的单词后开始，当匹配次数过多时，移除过多的单词
vector<int> findsubString(string s, vector<string> words)
{
  map<string, int> Map;
  vector<int> res;
  if (words.size() == 0)
    return res;
  int singlesize = words[0].size();
  int totalsize = words.size();
  for (string i : words)
    Map[i]++;

  map<string, int> tempMap;
  for (int i = 0; i < singlesize; i++)
  {
    int j = i;
    int tempindex = i;
    tempMap.clear();
    while (j + singlesize * totalsize <= s.size())
    {
      string subStr = s.substr(tempindex, singlesize);
      if (Map.count(subStr) == 0)
      {
        j = tempindex + singlesize;
        tempindex = j;
        tempMap.clear();
      }
      else
      {
        tempMap[subStr]++;
        tempindex += singlesize;
       while (Map[subStr] < tempMap[subStr])
        {
          tempMap[s.substr(j, singlesize)]--;
          j += singlesize;
        }
        if (Map == tempMap)
        {
          res.push_back(j);
          tempMap[s.substr(j,singlesize)]--;
          j += singlesize;
        }
      }
    }
  }
  return res;
}

int main()
{
  string s = "barfoothefoobarman";
  vector<string> words = {"foo","bar"};
  vector<int> res = findsubString(s, words);
  for (int i : res)
  {
    cout << i << " ";
  }
}
// lingmindraboofooowingdingbarrwingmonkeypoundcake