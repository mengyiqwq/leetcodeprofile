#include <iostream>
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int pathSumIII(TreeNode *root, int sum)
{
    if (root == nullptr)
        return 0;
    return count(root, sum) + pathSumIII(root->left, sum - (root->val)) + pathSumIII(root->right, sum - (root->val));
}
// 以当前节点为开头，可以构造出的路径
int count(TreeNode *root, int sum)
{
    if (root == nullptr)
        return 0;
    return (sum == root->val) + count(root->left, sum - root->val) + count(root->right, sum - root->val);
}
int main()
{
}