#include <iostream>
using namespace std;
#include <vector>
int maxArea(vector<int>&height)
{
    int ptr1=0;
    int ptr2=height.size()-1;
    int max=0;
    while (ptr1<ptr2)
    {
        if(height[ptr1]>height[ptr2])
        {
            if(height[ptr2]*(ptr2-ptr1)>max)
           max=height[ptr2]*(ptr2-ptr1);
           else
            ptr2--;
        }
       else
       {
        if(height[ptr1]*(ptr2-ptr1)>max)
           max=height[ptr1]*(ptr2-ptr1);
        else
            ptr1++;
       }
    }
    return max;
}
int main()
{
    vector<int>a={1,2,1};
    cout<<maxArea(a);
}