#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 自己的写法
ListNode*swapPairs(ListNode*head)
  {
      if(head==nullptr||head->next==nullptr)
      return head;
      ListNode*Fptr=head->next;
      ListNode*Sptr=head->next->next;
      Fptr->next=head;
      head->next=swapPairs(Sptr);
      return Fptr;
  }
  // 更好的写法，将交换的中间节点记录,节省一个变量,将第一个节点先连到后面，再去改变中间的节点
  ListNode*SwapPairs(ListNode*head)
  {
      if(head==nullptr||head->next==nullptr)
      return head;
      ListNode*Fptr=head->next;
      head->next=SwapPairs(Fptr->next);
     Fptr->next=head;
      return Fptr;
  }
int main()
{
  
}