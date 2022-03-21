#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node *isNullRoot(Node *root)
{
    if (!root)
        return nullptr;
    if (root->left != nullptr)
        return root->left;
    if (root->right != nullptr)
        return root->right;
    return isNullRoot(root->next);
}
Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    if (!root->left && !root->right)
        return root;
    if (root->left && root->right)
    {
        root->left->next = root->right;
        root->right->next=isNullRoot(root->next);
    }
    else if (!root->left)
    {
        root->right->next = isNullRoot(root->next);
    }
    else
        root->left->next = isNullRoot(root->next);
    root->left = connect(root->left);
    root->right = connect(root->right);
    return root;
}
int main()
{

}