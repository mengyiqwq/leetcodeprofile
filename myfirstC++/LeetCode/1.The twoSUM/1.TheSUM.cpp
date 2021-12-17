#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 两个for
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
        
    }
    return {};
};
// 使用哈希表
vector<int> hashtwoSum(vector<int>&nums,int target)
{
    map<int,int>a;
    for(int i=0;i<nums.size();i++)
    {
        a.insert(map<int,int>::value_type (nums[i],i));
    }
    for(int i=0;i<nums.size();i++)
    {
        // 注意key为数组的实际值，而value为下标，而对应的下标不和原来的下标重合
        if(a.count(target-nums[i])>0&&a[target-nums[i]]!=i)
        {
            return {a[i],a[target-nums[i]]};
        }
    }
    return {};
};
int main()
{
    int target = 6;
    const int n = 6;
    vector<int> a = {1, 7, 4, 5, 3};
    vector<int>result;
    result= hashtwoSum(a,6); 
    cout<<result[0]<<" "<<result[1]<<endl;
    result=twoSum(a, 6);
    cout<<result[0]<<" "<<result[1]<<endl;
}