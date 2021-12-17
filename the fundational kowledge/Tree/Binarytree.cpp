#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
    node(int v1 = -1, node *l = nullptr, node *r = nullptr)
    {
        left = l;
        right = r;
        value = v1;
    }
};
// 构建一个二叉树
node *addAnode(int value, node *root = nullptr)
{
    if (root == nullptr)
    {
        root = new node(value);
        return root;
    }
    // 递归的核心是下面使用的操作类似，因此采用调用自身的方式封装.
    if (value < root->value)
        root->left = addAnode(value, root->left);
    if (value > root->value)
        root->right = addAnode(value, root->right);
    //    上面两个递归没有跑完是不会返回的，此处的返回是每次调用的时候不为空节点时的返回
    return root;
}
node *find(int value, node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->value == value)
        return root;
    if (value < root->value)
        return find(value, root->left);
    if (value > root->value)
        return find(value, root->right);
    return nullptr;
}
node *findmin(node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr)
        return root;
    else
        return findmin(root->left);
}
node *findmax(node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->right == nullptr)
        return root;
    else
        return findmax(root->right);
}
// 删除特点数字的节点，并返回新树的根节点
// 递归法的精髓在于确定好输入和输出，并将其当作是已有的函数进行调用。
node *deleteanode(int num, node *root)
{

    if (root == nullptr)
        return nullptr;
    //   发现右边为空指针时进行直接拼接
    if (num < root->value)
    {
        root->left = deleteanode(num, root->left);
        return root;
    }
    else if (num > root->value)
    {
        root->right=deleteanode(num,root->right);
        return root;
    }
    else
    {
        if (root->left == nullptr)
        {
            // 用一个节点来存储上下一个节点的位置，删除当前节点，返回下一个节点，即通过函数可以得到截取后的根节点
            node*rightNode=root->right;
            delete root;
            return rightNode;
        }
        if (root->right == nullptr)
        {
          node*leftNode=root->left;
          delete root;
          return leftNode;
        }
        // 找到右边最小节点的值赋值给要删除的节点，最后仍然返回根节点
        root->value=findmin(root->right)->value;
        delete findmin(root->right);
        return root;
    }
}
int main()
{
    int arr[] = {4, 2, 3, 5};
    node *root = nullptr;
    for (int i = 0; i < end(arr) - begin(arr); i++)
    {
        root = addAnode(arr[i], root);
    }
    cout<<root->value;
    // cout<<find(7,root);
    // cout << findmin(root)->value << endl;
    // cout << findmax(root)->value;
    // cout << find(3, root)->value;
    deleteanode(4, root);
    cout << find(4, root);
    cout<<root->value<<"  "<<endl;
    //    node* tree= createAtree(arr,3);
    //    delete tree;
    return 0;
}