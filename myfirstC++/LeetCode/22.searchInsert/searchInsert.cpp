#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int mid = (l + r) / 2;
    if (nums[r] < target)
        return r + 1;
    while (nums[mid] != target)
    {
        if (l >= r)
            return l;
        if (nums[mid] > target)
            r = mid;
        else
            l = mid + 1;
        mid = (r + l) / 2;
        /* code */
    }
    return mid;
}
int main()
{
    vector<int> arr = {1};
    cout << searchInsert(arr, 0);
}