#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node(int Nodevalue, Node *nextPtr = nullptr)
    {
        value = Nodevalue;
        next = nextPtr;
    }
};
Node *initList(vector<int> Arr)
{
    if (Arr.size() == 0)
        return nullptr;
    Node *head = new Node(Arr[0]);
    for (int i = 1; i < Arr.size(); i++)
    {
        head = new Node(Arr[i], head);
    }
    return head;
}
void showList(Node *headPtr)
{
    Node *ptr = headPtr;
    while (ptr != nullptr)
    {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
    cout << endl;
}
// 链表加法(直接法，待优化)
Node *addList(Node *Listptr1, Node *Listptr2)
{
    Node *result = new Node(-1);
    Node *firstNode = nullptr;
    int AddIn = 0;
    while (Listptr2 != nullptr || Listptr1 != nullptr)
    {
        if (Listptr1 == nullptr)
        {
            Listptr1 = new Node(0, Listptr1);
        }
        if (Listptr2 == nullptr)
        {
            Listptr2 = new Node(0, Listptr2);
        }
        if (result->value == -1)
            firstNode = result;
        if (Listptr1->value + Listptr2->value + AddIn < 10)
        {
            result->next = new Node(Listptr1->value + Listptr2->value + AddIn);
            AddIn = 0;
        }
        else
        {
            result->next = new Node(Listptr1->value + Listptr2->value + AddIn - 10);
            AddIn = 1;
        }
        Listptr2 = Listptr2->next;
        Listptr1 = Listptr1->next;
        result = result->next;
    }
    if (Listptr2 == nullptr && Listptr1 == nullptr && AddIn == 1)
    {
        result->next = new Node(1);
        result = result->next;
    }
    return firstNode->next;
}
int main()
{
    vector<int> a(3, 7);
    Node *headPtr = initList(a);
    showList(headPtr);
    vector<int> b(8, 5);
    Node *headPtr2 = initList(b);
    showList(headPtr2);
    Node *result = addList(headPtr, headPtr2);
    showList(result);
}