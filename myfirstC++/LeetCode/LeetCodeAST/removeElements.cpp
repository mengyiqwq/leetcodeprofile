#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 递归摆烂
ListNode *removeElements(ListNode *head, int val)
{
    if(head==nullptr)
    return nullptr;
    ListNode*temp;
    if(head->val==val)
    {
       temp=head->next;
       delete head;
       return removeElements(temp,val);
    }
    else head->next= removeElements(head->next,val);
    return head;
}
int main()
{
}