#include <iostream>
#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
int findMax(vector<int> &nums)
{

    int max_i = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[max_i])
            max_i = i;
    }
    return max_i;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    if(nums.size()==0) return nullptr;
    int max_i = findMax(nums);
    TreeNode *root = new TreeNode(nums[max_i]);

    if (max_i != 0)
    {   vector<int> leftside;
        for(int i=0;i<=max_i-1;i++)
        leftside.push_back(nums[i]);
        root->left = constructMaximumBinaryTree(leftside);
    }
    if (max_i != nums.size() - 1)
    {
        vector<int> rightside;
        for(int i=max_i+1;i<=nums.size()-1;i++)
        {
           rightside.push_back(nums[i]);
        }
        root->right = constructMaximumBinaryTree(rightside);
    }
    return root;
}

int main()
{
}