#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class heap
{
private:
    static const int size = 20;
    int Arr[size];
    int maxsize = 0;

public:
    heap()
    {
        maxsize = 0;
        Arr[0] = INT32_MIN;
    }
    heap(vector<int> &arr)
    {
        Arr[0] = INT32_MIN;
        int length = arr.size();
        maxsize = length;
        for (int i = 1; i <= length; i++)
            Arr[i] = arr[i - 1];
        allPercolateDown(1);
    }
    int min()
    {
        return Arr[1];
    }
    void build(vector<int> arr)
    {
        for(int i:arr)
        insert(i);
    }
    // 递归建堆的方法，另有一种通过叶子节点数量为（n-1)/2,然后将每个内点进行向下渗透即可。
    void allPercolateDown(int index)
    {
        if (2 * index > maxsize)
            return;
        int minindex = 2 * index;
        if (2 * index + 1 <= maxsize)
            minindex = Arr[2 * index] < Arr[2 * index + 1] ? 2 * index : (2 * index + 1);
        if (Arr[minindex] < Arr[index])
        {
            swap(Arr[minindex], Arr[index]);
            percolateUP(index);
        }
        allPercolateDown(2 * index);
        if (2 * index + 1 <= maxsize)
        allPercolateDown(2 * index + 1);
    }
    void percolateDown(int index)
    {
        if (2 * index > maxsize)
            return;
        int minindex = 2 * index;
        if (2 * index + 1 <= maxsize)
            minindex = Arr[2 * index] < Arr[2 * index + 1] ? 2 * index : (2 * index + 1);
        if (Arr[minindex] < Arr[index])
            swap(Arr[minindex], Arr[index]);
        percolateDown(minindex);
    }
    void percolateUP(int index)
    {
        if (Arr[index / 2] > Arr[index])
            swap(Arr[index / 2], Arr[index]);
        else
            return;
        percolateUP(index / 2);
    }
    void insert(int num)
    {
        if (maxsize + 1 <= size)
        {
            Arr[maxsize + 1] = num;
            maxsize++;
        }
        percolateUP(maxsize);
    }
    void deleteMin()
    {
        Arr[1] = Arr[maxsize];
        maxsize--;
        percolateDown(1);
    }
    void printArr()
    {
        for (int i = 1; i <= maxsize; i++)
        {
            cout << Arr[i] << endl;
        }
    }
};
int main()
{
    vector<int> a = {55,63,44,38,75,80,31,56};
    heap Heap(a);
    // Heap.build(a);
    Heap.printArr();
}