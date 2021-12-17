#include <iostream>
#include <map>
using namespace std;
void print(map<int,string>Map){
map<int,string>::iterator iter;
for(iter=Map.begin();iter!=Map.end();iter++)
cout<<iter->first<<" "<<iter->second<<endl;
cout<<Map.size()<<endl;
}
int main(){
map<int,string>Map;
// 通过pair插入数据
Map.insert(pair<int,string>(2,"ssss"));
Map.insert(pair<int,string>(1,"你好"));
// 通过value_type插入数据
Map.insert(map<int,string>::value_type (3,"顶顶顶"));
// 通过数组插入数据
Map[4]="我是啊啊";
// 对于数组方式，当key值重复时，后面的会覆盖前面的,而对于前两种方式，插入无效
Map[3]="我不是啊啊";

// 以下为正向迭代
map<int,string>::iterator iter;
for(iter=Map.begin();iter!=Map.end();iter++)
cout<<iter->first<<" "<<iter->second<<endl;
cout<<Map.size()<<endl;
// 以下为反向迭代
map<int,string>::reverse_iterator iter1;
for(iter1=Map.rbegin();iter1!=Map.rend();iter1++)
cout<<iter1->first<<" "<<iter1->second<<endl;
//使用数组形式读数
for(int i=1;i<=Map.size();i++)
cout<<Map[i]<<endl<<endl; 

// map数据的查找
// 1.cout判断是否存在某个数据
cout<<Map.count(3)<<endl;
cout<<Map.count(5)<<endl;
// 2.使用find来寻找数据的位置
map<int,string>::iterator iter2;
iter2=Map.find(1);
cout<<iter2->first<<" "<<iter2->second<<endl;
// 找不到时返回end的迭代器
iter2=Map.find(19);
if(iter2==Map.end())
cout<<"not find"<<endl<<endl;

// 删除map中的元素
Map.erase(1);
print(Map);
Map.erase(Map.begin(),Map.end());
print(Map);
// 注意，当map中的key值没有内置的“<”来使得map进行比较排序时，要自行重载<来保证排序
}