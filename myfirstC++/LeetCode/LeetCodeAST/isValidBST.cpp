#include <iostream>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
// 方法1：递归遍历使用当前节点作为左边上界，右边下界，并进行是否越界的判断
// 方法2：中序遍历后，BST会是一个顺序排列
TreeNode*findmin(TreeNode*root)
{
    if(root==nullptr) return nullptr;
   while (root->left!=nullptr)
     root=root->left;
     return root;
}
TreeNode*findmax(TreeNode*root)
{
    if(root==nullptr) return nullptr;
   while (root->right!=nullptr)
     root=root->right;
     return root;
}
bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        return true;
    if (root->left != nullptr)
        if (findmax(root->left)->val >= root->val)
            return false;
    if (root->right != nullptr)
        if (findmin(root->right)->val <= root->val)
            return false;
    return isValidBST(root->left)&&isValidBST(root->right);
}

int main()
{
}
