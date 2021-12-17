#include <iostream>
using namespace std;
int Partipation(int Arr[],int low,int high)
{
  int temp=Arr[low];
  while (low<high)
  {//三个while很好地实现了反复颠倒进行遍历
     
      while (Arr[high]>=temp&&low<high)
      high--;
      Arr[low]=Arr[high];    
      while(Arr[low]<=temp&&low<high)
      low++;
      Arr[high]=Arr[low];  
  }
  Arr[low]=temp;
  return low;
}
void quicksort(int Arr[],int low,int high)//快排的时间复杂度为O(nlogn)，最坏情况为O(n^2),但单位操作时间效率高
{
  if (low<high)
  {
     int temp=Partipation(Arr,low,high);//进行分区
     quicksort(Arr,low,temp-1);//对分区左边的部分进行快排，其实是递归分区
     quicksort(Arr,temp+1,high);//对分区右边的部分进行快排，其实是递归分区，
     //通过递归可以每次递归找到每个数该在的位置
  }
}
int main()
{
  int a[10]={3,41,5,6,7,1,4,90,22,44};
  quicksort(a,0,9);
  for (int i:a)
  {
    cout<<i<<endl;
  }
  
}