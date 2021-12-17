#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
// 构造函数
 Node(int value1,Node*nextPtr=nullptr)
 {
     value=value1;
     next=nextPtr;
 }
};
struct node
{
  int value=-1;
  node*next=nullptr; //下一个节点指针 
  node*pre=nullptr;//上一个节点指针
  node(int num=-1,node*Pre=nullptr)
  {
    value=num;
    pre=Pre;
  }
};
node*createAlist(vector<int>&Arr)
{
   node*head=new node();
   node*temp=head;
   for(int i=0;i<Arr.size();i++)
   {
      head->next=new node(Arr[i],head);
      head=head->next;
   }
   return temp;
}
void show(node*list)
{
    while (list!=nullptr)
    {  if(list->value!=-1)
        cout<<list->value<<endl;
        list=list->next;
    }
}
int main()
{
    // 没有构造函数时的用法
// Node *head = nullptr;
//     head = new Node;
//     head->value = 11;
//     head->next = nullptr;
//     Node *secondPtr = new Node;
//     secondPtr->value = 12;
//     secondPtr->next = nullptr;
//     head->next = secondPtr;
//     cout << head->value <<"  "<< head->next->value << endl;
// }

// 使用构造函数
Node *second=new Node(2);
Node *head=new Node(1,second);
cout<<head->value<<" "<<second->value<<endl;
// 重新赋值，移动使用的指针
Node *end=new Node(2);
end=new Node(1,end);
cout<<end->value<<" "<<end->next->value<<endl;
}