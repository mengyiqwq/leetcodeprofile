#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
{
    vector<pair<int, int>> mymap;
    for (int i : nums)
    { 
        int temp = 0;
        int tempi=i;
        int count = 1;
        if(i==0) temp=mapping[0];
        else 
        while (i > 0)
        {
            temp += (mapping[i % 10] * count);
            i /= 10;
            count*=10;
        }
       
        mymap.push_back({tempi,temp});
    }
    stable_sort(mymap.begin(),mymap.end(),[&](auto &a,auto &b){
    return a.second<b.second;
    });
    vector<int>res;
    for(auto i:mymap)
    {
        res.push_back(i.first);
    }
    return res;
}
int main()
{
    vector<int> mapp={8,9,4,0,2,1,3,5,7,6};
    vector<int>aa={991,338,38};
    sortJumbled(mapp,aa);

}