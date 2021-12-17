#include <iostream>
using namespace std;

void mergearray(int a[],int first,int mid,int end,int temp[])//合并两个子数组函数
{
  int firstIdx=first;
  int SencondIdx=mid+1;//一个从开始到mid,另一个从mid到end
  int count=0;
  while (firstIdx<=mid&&SencondIdx<=end)//将两个子数组进行比较添加到temp数组中，
                                        //然后再将temp数组来更新原数组
  {
      if(a[firstIdx]>a[SencondIdx])
      {temp[count]=a[SencondIdx];
      SencondIdx++;
      }
      else 
      {temp[count]=a[firstIdx];
      firstIdx++;}
      count++;
  }
  while (firstIdx<=mid)
  {
       temp[count]=a[firstIdx];
       count++;
       firstIdx++;
  }
   while (SencondIdx<=end)
  {
       temp[count]=a[SencondIdx];
       count++;
       SencondIdx++;
  }
  for(int i=0;i<count;i++)
  {
    a[first+i]=temp[i];//将计算的结果放回原先对应的数组,不然原来的数组不会改变
  }
}
void mergesort(int a[],int first,int end,int temp[])
{
   if(first<end)
   { 
     int mid=(first+end)/2;
     mergesort(a,first,mid,temp);
     mergesort(a,mid+1,end,temp);
     mergearray(a,first,mid,end,temp);
   }
    
}
int main()
{
  int a[]={10,2,3,5,7,4};
  int b[6]={0};
  mergesort(a,0,5,b);
  for (int i:b)
  {
    cout<<i<<endl;
  }
  
}