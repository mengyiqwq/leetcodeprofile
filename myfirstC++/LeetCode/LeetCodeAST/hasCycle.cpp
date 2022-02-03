#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// 哈希摆烂
bool hasCycle(ListNode*head)
{ 
   unordered_map<ListNode*,int>hashMap;
   hashMap[head]++;
   while (head!=nullptr)
   {
       if(!hashMap.count(head))
       hashMap[head->next]++;
       else return true;
       head=head->next;
   }
   return false;
}
// 快慢指针，当有环时总会使得快指针最后追上慢指针
bool hasCycle(ListNode*head)
{
    ListNode*Qptr=head;
    ListNode*Sptr=head;
    while (Qptr!=nullptr)
    {
        if(Qptr->next!=nullptr)
        {
           Qptr=Qptr->next->next;
           Sptr=Sptr->next;
           if(Qptr==Sptr)
           return true;
        }
        else
        return false;
    }
    return false;
}
int main()
{
}