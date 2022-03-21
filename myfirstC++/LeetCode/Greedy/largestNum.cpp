#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 每次先选最高位最大，再是次高位最大,类似于桶排序
string largestNumber(vector<int> &nums)
{
    string res="";
    sort(nums.begin(),nums.end(),[=](int a,int b){
     string aa=to_string(a);
     string bb=to_string(b);
     return aa+bb>bb+aa;
    });
    for(int i:nums)
    res+=to_string(i);
    return res[0]=='0'?"0":res;
}
int main()
{
}