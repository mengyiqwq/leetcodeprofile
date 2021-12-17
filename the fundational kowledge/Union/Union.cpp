#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// 数据结构中的Union联合,数组实现，在每一个数组元素中直接放其父节点是谁即可
// 优化，一个是可以根据权重来接，以及利用find函数时进行路径的压缩，组织成一棵树时可以方便接
// 主要为合并以及查找操作
class Union{
    private:vector<int>Set;//本数组不一定全为同一个父节点
    public:
    Union()
    {

    }
    Union(vector<int>Arr)
    {
       for(int i:Arr)
       Set.push_back(i);
    }
    void show()
    {
        for(int i:Set)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int getEle(int Idx)
    { 
       return Set[Idx];
    }
    int size(){
        return Set.size();
    }
    vector<int>getSet()
    {
        return Set;
    }
    void connectTwo(int Idx1,int Idx2)
    {
        Set[find(Idx1)]=find(Idx2);
    }
    int find(int Idx)//寻找某个节点的集合代表
    {
      int res=Idx; 
      int temp=res;
       while (Set[res]!=res)//路径压缩
       {
         if(Set[Set[res]]!=Set[res])
            Set[res]=Set[Set[res]];
           res=Set[res];
       }
    return res;
    }
};
int main()
{
vector<int>a={1,2,3,3,5,6,6};
Union A(a);
cout<<A.find(0)<<" ";
cout<<A.find(3)<<endl;
A.connectTwo(0,3);
cout<<A.find(0)<<"->"<<A.find(3)<<endl;
cout<<A.find(0)<<endl;
A.show();
}