#include <iostream>
#include <string>
#include <vector>
using namespace std;
void insertsorting(vector<int>& Arr)
{
    int temp;
    int record;
   for (int i = 0; i < Arr.size(); i++)
   {
       temp=i;
       record=Arr[i];
      while (Arr[i]<=Arr[temp])
      {
       if(temp!=0)
          temp--;
       else  break;
      }
      if(temp!=0)
      temp+=1;
      for (int j=i;j>temp;j--)
    {
        if(j-1>=0)
         Arr[j]=Arr[j-1];
      }
      Arr[temp]=record;
   }
   
}
// 网上更好的写法
void InsertSort(vector<int>&Arr)
{
    for (int i = 1; i < Arr.size(); i++)
    {
         int temp=Arr[i];
         int j=i-1;
         while (j>=0&&temp<Arr[j])
         {
           Arr[j+1]=Arr[j];//不断给后面的复制过去.跨越性地进行试探
            j--;
         }
         Arr[j+1]=temp;
    }
    
}
int main()
{
vector<int> a={4,2,1,3,9};
InsertSort(a);
for(int i:a)
{
    cout<<i<<" ";
}
}