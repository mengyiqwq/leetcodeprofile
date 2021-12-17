#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// 先找到中间位置然后再进行分别的二分查找算法，最差时可能会到达O(n)
int binarysearch(vector<int> &nums, int target, int begin, int end)
{
    int mid = (begin + end) / 2;
    if (nums[mid] == target)
        return mid;
    else if (begin >= end)
        return -1;
    if (target < nums[mid])
        return binarysearch(nums, target, begin, mid);
    else
        return binarysearch(nums, target, mid + 1, end);
    return -1;
}
int search(vector<int> &nums, int target)
{
    int length = nums.size();
    if (length <= 3)
    {
        for (int i = 0; i < length; i++)
            if (nums[i] == target)
                return i;
        return -1;
    }
    int moveMid = length / 2;
    while (nums[moveMid] < nums[0])
    {
        moveMid--;
        if (nums[moveMid] == target)
            return moveMid;
    }
    while (nums[moveMid] > nums[0])
    {

        if (moveMid < length - 1)
            moveMid++;
        else
            break;
        if (nums[moveMid] == target)
            return moveMid;
    }
    if (nums[moveMid] < nums[0])
        moveMid--;
    // 二分查找，为log(n)
    int res = binarysearch(nums, target, 0, moveMid);
    if (res != -1)
        return res;
    return binarysearch(nums, target, moveMid + 1, length - 1);
}
// 更加巧妙的解法，每次只对于有序的部分进行二分查找
// 关键是理解当左边有序，不在左边时，找右边的那一半部分有序的，此时问题又变成原来的问题了
// 如果就在左边则直接二分查找即可.写代码时可以通过设置的左右标记跳着走，然后每次取的中间也跟着跳
int Search(vector<int> &nums, int target)
{
    int length = nums.size();
    int l = 0, r = length - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > nums[0])
        {
            if (nums[0] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else 
        {
            if(nums[mid]<target&&target<=nums[length-1])
             l=mid+1;
             else
             r=mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {0, 1, 3, 4, 6, 8, 9};
    cout << search(a, 6)<<endl;
    cout<<Search(a,6);
}