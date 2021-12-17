#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    int length = nums.size();
    vector<int> res(2, -1);
    if (length == 0 || target > nums[length - 1] || target < nums[0])
        return res;
    int l = 0, r = length - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (target == nums[mid])
        {
            res[0] = mid - 1;
            res[1] = mid + 1;
            int temp = mid;
            if (res[0] >= 0)
                while (nums[res[0]] == target)
                {
                    res[0]--;
                    if (res[0] < 0)
                    {
                        res[0] = 0;
                        break;
                    }
                }
            else
                res[0] = mid;
            if (res[1] <= length - 1)
                while (nums[res[1]] == target)
                {
                    res[1]++;
                    if (res[1] > length - 1)
                    {
                        res[1] = length - 1;
                        break;
                    }
                }
            else
                res[1] = mid;
            if(nums[res[0]]!=target)
            res[0]++;
            if(nums[res[1]]!=target)
            res[1]--;
            return res;
        }
        if (target >= nums[l] && target < nums[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}
int main()
{
    vector<int> a = {0,0};
    vector<int> res = searchRange(a, 5);
    for (int i : res)
    {
        cout << i << " ";
    }
}