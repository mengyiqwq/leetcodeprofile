#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    ListNode *next;
};
// 直接遍历
ListNode *middleNode(ListNode *head)
{
    int count = 0;
    ListNode *SPtr = head;
    while (SPtr != nullptr)
    {
        SPtr = SPtr->next;
        count++;
    }
    count /= 2;
    SPtr = head;
    while (count > 0)
    {
        SPtr = SPtr->next;
        count--;
    }
    return SPtr;
}
// 快慢指针法
ListNode*middleNode(ListNode*head)
{
    ListNode*quickPtr=head;
    ListNode*slowPtr=head;
    while (quickPtr!=nullptr&&quickPtr->next!=nullptr)
    {
        quickPtr=quickPtr->next->next;
        slowPtr=slowPtr->next;
    }
    return slowPtr;
}
int main()
{
}