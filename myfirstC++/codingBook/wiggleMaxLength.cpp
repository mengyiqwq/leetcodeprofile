#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int wiggleMaxLength(vector<int> &nums)
{
    int length = nums.size();
    if (length == 1)
        return 1;
    if (length == 2)
        return nums[0] == nums[1] ? 1 : 2;
    int max_len = 2;
    int state;
    if (nums[0] == nums[1])
    {
        state = 2;
        max_len=1;
    }
    else if (nums[0] > nums[1])
        state = 0;
    else
        state = 1; // 0代表下降,1代表上升
    // 贪心地选择,或者说后悔解法,在递增或者递减时不停往下去
    for (int i = 2; i < length; i++)
    {
        if (state == 1)
        {
            if (nums[i] < nums[i - 1])
            {
                max_len++;
                state = 0;
            }
        }
        else if (state == 0)
        {
            if (nums[i] > nums[i - 1])
            {
                max_len++;
                state = 1;
            }
        }
        else if (nums[i] != nums[i - 1])
        {
            state = nums[i] > nums[i - 1] ? 1 : 0;
            max_len++;
        }
    }
    return max_len;
}
int main()
{
}