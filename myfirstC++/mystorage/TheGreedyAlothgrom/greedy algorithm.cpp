#include <iostream>
#include <vector>
using namespace std;
// 举例计划会议
vector<int>greeyplan(vector<int>&Arr1,vector<int>&Arr2)
{
  vector<int>result;
  result.push_back(0);
  int temp=Arr2[0];
  for(int i=0;i<Arr1.size();i++)
  {
    if(Arr1[i]>temp)
    {
        result.push_back(i);
        temp=Arr2[i];
    }
  }
  return result;
} 
int main()
{
  vector<int> start={1,3,0,5,6,2,4};
  vector<int> end={2,4,6,7,9,10};
  vector<int>res=greeyplan(start,end);
  for(int i=0;i<res.size();i++)
  {
      cout<<res[i]<<endl;
  }
}