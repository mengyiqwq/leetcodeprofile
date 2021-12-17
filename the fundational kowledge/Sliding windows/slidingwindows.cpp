#include <iostream>
using namespace std;
#include <unordered_set>
// 详见第3题
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
    
}