#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 希尔排序思想是多做几次插排
void insertsort(vector<int>&Arr,int size,int begin=0)
{
    for (int i = begin+size; i < Arr.size(); i+=size)
    {
        int temp=Arr[i];
        int j=i-size;
        while (j>=0&&Arr[j]>temp)
        {
            Arr[j+size]=Arr[j];
            j-=size;
        }
        Arr[j+size]=temp;
    }
}
void shellsort(vector<int>&Arr)
{
    for (int size=Arr.size()/2; size >=1 ; size/=2)
    {
        insertsort(Arr,size);
    }
}
int main()
{
vector<int>a={2,3,5,1,9,10,8};
shellsort(a);
for(int i:a)
{
    cout<<i<<" ";
}
}