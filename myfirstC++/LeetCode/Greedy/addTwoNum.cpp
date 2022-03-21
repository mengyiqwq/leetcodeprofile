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
ListNode *addTwoNum(ListNode *l1, ListNode *l2, int carry)
{
    if (!l1 && !l2)
    {
        if (!carry)
            return nullptr;
        return new ListNode(carry);
    }
    if (!l1)
    {
        int temp = carry + l2->val;
        l2->val = temp % 10;
        l2->next = addTwoNum(l1, l2->next, temp / 10);
        return l2;
    }
    if (!l2)
    {
        int temp = carry + l1->val;
        l1->val = temp % 10;
        l1->next = addTwoNum(l1->next, l2, temp / 10);
        return l1;
    }
    int temp = l1->val + l2->val + carry;
    l2->val = temp % 10;
    l2->next = addTwoNum(l1->next, l2->next, temp / 10);
    return l2;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
   return addTwoNum(l1,l2,0);
}
int main()
{
}