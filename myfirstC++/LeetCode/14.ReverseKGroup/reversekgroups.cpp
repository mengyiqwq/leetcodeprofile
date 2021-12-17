#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
  int value = -1;
  ListNode *next = nullptr; //下一个节点指针
  ListNode(int num = -1, ListNode *Next = nullptr)
  {
    value = num;
    next = Next;
  }
};
ListNode *createAlist(vector<int> &Arr)
{
  ListNode *head = new ListNode();
  ListNode *temp = head;
  for (int i = 0; i < Arr.size(); i++)
  {

    head->next = new ListNode(Arr[i]);
    head = head->next;
  }
  return temp->next;
}
void show(ListNode *list)
{
  while (list != nullptr)
  {
    cout << list->value << endl;
    list = list->next;
  }
}
ListNode *SwapPairs(ListNode *head, int k)
{
  // int count=0;
  if (head == nullptr)
    return nullptr;
  ListNode *tempptr1 = head->next;
  ListNode *tempptr2 = head;
  for (int i = 1; i <= k - 2; i++)
  {
    tempptr2 = tempptr2->next;
    if (tempptr2 == nullptr)
      return head;
  }
  if(tempptr2->next==nullptr)
  return head;
  ListNode *tempptr3 = tempptr2->next;
  if (k <= 2)
  {
    if (k <= 1)
      return head;
    if(tempptr1==nullptr)
    return tempptr2;
    tempptr2->next = tempptr1->next;
    tempptr1->next = tempptr2;
    return tempptr1;
  }
  if (tempptr3 == nullptr)
    return tempptr3;
  head->next = tempptr3->next;
  tempptr2->next = head;
  tempptr3->next = SwapPairs(tempptr1, k - 2);
  return tempptr3;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
  if(head==nullptr)
  return head;
 ListNode*res= SwapPairs(head,k);
 head->next=reverseKGroup(head->next,k);
 return res;
}
int main()
{
  vector<int> a = {1, 2, 3, 4, 5, 6, 7};
  ListNode *head = createAlist(a);
  ListNode *res = reverseKGroup(head, 2);
  show(res);
}