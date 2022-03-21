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

ListNode *mergeNodes(ListNode *head)
{
    ListNode *ptr = head->next;
    ListNode *root = head;
    int temp = 0;
    while (ptr != nullptr)
    {
        if (ptr->val != 0)
        {
            temp += ptr->val;
        }
        else
        {
            if (temp)
            {
                root->next = new ListNode(temp);
                root=root->next;
            }
        }
        ptr = ptr->next;
    }
    return head->next;
}
int main()
{
}