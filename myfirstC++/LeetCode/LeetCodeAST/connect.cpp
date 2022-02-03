#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// 递归完事
Node* connect(Node*root)
{
   if(root==nullptr)
   return nullptr;
   if(root->left!=nullptr)
   root->left->next=root->right;
   if(root->next!=nullptr&&root->right!=nullptr)
   root->right->next=root->next->left; 
   root->left=connect(root->left);
   root->right=connect(root->right);
   return root;
}
// 层次遍历，思路是递归遍历一遍并将遍历的节点放进一个队列中，然后依次修改它们的next指针
int main()
{
}