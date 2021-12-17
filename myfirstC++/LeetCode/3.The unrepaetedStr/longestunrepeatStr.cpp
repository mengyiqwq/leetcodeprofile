#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;
// 使用哈希表,在这个过程中，每当出现重复时会重新截断遍历，时间复杂度为O(n^2)
//思路是将字符串在出现重复时进行了截取 代码有待优化
int countLongsubStr(string Str)
{
    map<char, int> Map;
    int count = 0;
    int result = 0;
    int i = 0;
    while (i < Str.length())
    {
        Map.insert(pair<char, int>(Str[i], i));
        count++;
        if (count > result)
        {
            result = count;
        }
        if (Map.count(Str[i + 1]))
        {
            Str = Str.substr(Map.find(Str[i + 1])->second);
            Map.clear();
            i = 0;
            count = 0;
        }
        i++;
    }
    return result;
}

// 滑动窗口算法，时间复杂度为O(n)
int countByWindow(string s)
{
    unordered_set <char> window;//创建一个窗口容器
    int left=0;
    int result=0;
    for(int i=0;i<s.size();i++)
    {
        // 使用while是要进行连续移动左边,直到不再出现重复元素
       while (window.find(s[i])!=window.end())
       {
           window.erase(s[left]);
           left++;
       }
       window.insert(s[i]);
       if(window.size()>result)
       result=window.size();
    }
    return result;
}
int main()
{
    string a = "ddddd";
    cout << countLongsubStr(a)<<endl;
    cout<<countByWindow(a);
}