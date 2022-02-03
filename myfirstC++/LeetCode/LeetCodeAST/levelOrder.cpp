#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 层序遍历,使用队列广度优先,每次计算队列的大小,并都取出来即可
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {{}};
    vector<vector<int>> res;
    queue<TreeNode *> Q;
    Q.emplace(root);
    while (!Q.empty())
    {
        res.push_back({});
        int length = Q.size();
        for (int i = 0; i < length; i++)
        {
            res[res.size() - 1].push_back(Q.front()->val);
            if (Q.front()->left != nullptr)
                Q.emplace(Q.front()->left);
            if (Q.front()->right != nullptr)
                Q.emplace(Q.front()->right);
            Q.pop();
        }
    }
    return res;
}
int main()
{
}