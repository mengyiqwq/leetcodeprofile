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
ListNode *BuildAList(vector<int> Arr)
{
    ListNode *temp;
    ListNode *head = new ListNode(Arr[0]);
    temp = head;
    for (int i : Arr)
    {
        if (i != head->val)
        {
            head->next = new ListNode(i);
            head = head->next;
        }
    }
    return temp;
}
void printAList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}
// 自己写的，用多个指针进行循环遍历，时间复杂度为O(n^2)，空间复杂度为O(1)
// ,但由于这里构建链表时是不停new出来的，因此消耗较大，因此要想办法不去new,而是只通过调整指针来做
// 其实直接拿一个新的指针来不断连接即可
// 还有一种优化时间的思路就是将链表数组的第一个进行排序，
ListNode *mergeKLists(vector<ListNode *> &Lists)
{
    if (Lists.size() == 0)
        return nullptr;
    ListNode *res = nullptr;
    ListNode *head = nullptr;
    int count = 0;
    int index;
    int min = INT32_MAX;
    while (1)
    {
        for (int i = 0; i < Lists.size(); i++)
        {
            if (Lists[i] == nullptr)
            {
                count++;
                if (count == Lists.size())
                    return head;
                continue;
            }
            if (Lists[i]->val <= min)
            {
                min = Lists[i]->val;
                index = i;
            }
        }
        if (res != nullptr)
        {
            res->next = Lists[index];
            res = res->next;
        }
        else
        {
            res = Lists[index];
            head = res;
        }
        if (Lists[index] != nullptr)
            Lists[index] = Lists[index]->next;
        count = 0;
    }
    return head;
}
int main()
{
    vector<int> a = {2, 3};
    vector<int> b = {1};
    //    vector<int>c={2,6};
    vector<ListNode *> input;
    input.push_back(BuildAList(a));
    input.push_back(BuildAList(b));
    //    input.push_back(BuildAList(c));
    ListNode *res = mergeKLists(input);
    printAList(res);
}