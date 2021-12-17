// #ifndef MyGraph
// #define MyGraph
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct node
{
    string value;
    node *next;
    node(string V = "N", node *N = nullptr) : value(V), next(N){};
};
class Graph //Graph类，实现利用vector来生成图的功能，
{
private:
    vector<node *> GraphArr;
    int size;
    vector<vector<int> > pathcost;
    int SearchIndex(string s)
    {
        for (int i = 0; i < size; i++)
        {
            if (s == GraphArr[i]->value)
                return i;
        }
        return -1;
    }

public:
    Graph(int Num, vector<string> &Arr, vector<vector<int>> &Cost)
    {
        size = Num;
        pathcost = Cost;
        int Arrsize = Arr.size();
        int beginIdx = 0;
        GraphArr.resize(Num, nullptr);
        while (Arr[beginIdx] == "N")
            beginIdx++;
        int subArrEnd = beginIdx + 1;
        node *tempptr = new node(Arr[beginIdx]);
        for (int i = beginIdx; i < Num; i++)
        {
            GraphArr[i] = tempptr;
            for (int j = subArrEnd; j < Arrsize; j++)
            {
                if (tempptr != nullptr)
                {
                    if (Arr[j] != "N")
                    {
                        tempptr->next = new node(Arr[j]);
                        tempptr = tempptr->next;
                    }
                    else
                    {
                        subArrEnd = j + 2;
                        if (j <= Arrsize - 2)
                            tempptr = new node(Arr[j + 1]);
                        break;
                    }
                }
            }
        }
    }
    void show()
    {
        for (node *i : GraphArr)
        {
            if (i != nullptr)
            {
                node *tempptr = i;
                while (tempptr != nullptr)
                {
                    cout << tempptr->value << "->";
                    tempptr = tempptr->next;
                }
                if (tempptr == nullptr)
                    cout << "NULL" << endl;
            }
            else
                cout << "NULL" << endl;
        }
    }
    vector<string> topusort()
    {
        vector<string> res;
        map<string, int> Map;
        map<string, int>::iterator iter;
        map<string, int>::iterator tempiter;
        node *tempptr;
        for (node *i : GraphArr)
        {
            if (i == nullptr)
                continue;
            tempptr = i;
            while (tempptr != nullptr)
            {
                Map[tempptr->value]++;
                tempptr = tempptr->next;
            }
        }
        while (!Map.empty())
            for (iter = Map.begin(); iter != Map.end();)
            {
                if (iter->second == 1)
                {
                    res.push_back(iter->first);

                    for (node *i : GraphArr)
                    {
                        if (i == nullptr)
                            continue;
                        if (i->value == iter->first)
                        {
                            node *Temp = i->next;
                            while (Temp != nullptr)
                            {
                                Map[Temp->value]--;
                                Temp = Temp->next;
                            }
                            break;
                        }
                    }
                    tempiter = iter;
                    iter++;
                    Map.erase(tempiter);
                }
                else
                    iter++;
            }
        for (string i : res)
            cout << i << "->";
        cout << "NULL";
        return res;
    }
    // 在图中的最短路径问题
    // 贪心算法实现。
    // 算法思想：初始化一个cost数组，cost数组的起点为0
    // 子节点的度为父节点加上路径
    // 遍历子节点算值，将自己固定，找到剩下数组的最小度作为当前，循环上面两步
    // 核心在于它每次都在除了已选的点中进行寻找最小度的点进行下一步的移动
    int ShortestPath(string beginStr, string endStr) //cost数组以-1来表示每次输入的结束
    {
        int begin = SearchIndex(beginStr);
        int end = SearchIndex(endStr);
        if (begin == -1 || end == -1)
        {
            return -1;
        }
        // begin和end是起始和终止点的索引
        // 首先遍历起点的邻近点，初始化
        map<string, int> cost; //记录每个节点的度
        int curmin;
        int Idx = 0;
        for (node *i : GraphArr)
        {
            cost[i->value] = INT16_MAX;
        }
        map<string, int> Map; //记录已经到达过的结点
        cost[GraphArr[begin]->value] = 0;
        node *tempptr = GraphArr[begin]->next;
        while (1)
        {
            curmin = INT16_MAX;
            while (tempptr != nullptr)
            {
                if (cost[tempptr->value] > cost[GraphArr[begin]->value] + pathcost[begin][Idx])
                    cost[tempptr->value] = cost[GraphArr[begin]->value] + pathcost[begin][Idx];
                tempptr = tempptr->next;
                Idx++;
            }
            Map[GraphArr[begin]->value]++;
            if (Map[GraphArr[end]->value])
                return cost[GraphArr[end]->value];
            for (int i = 0; i < size; i++)//此处的找最小值过程可以用堆来进行优化
            {
                if (cost[GraphArr[i]->value] < curmin && !Map[GraphArr[i]->value])
                {
                    curmin = cost[GraphArr[i]->value];
                    begin = i;
                }
            }
            tempptr = GraphArr[begin]->next;
            Idx = 0;
        }
        return cost[GraphArr[end]->value];
    }
    // 每次对于目标点的值进行更新即是找到了一条更短的路径,然后后面路径只需要在前面基础上加即可
    vector<string> myPath(string beginStr, string endStr) //cost数组以-1来表示每次输入的结束
    {
        int begin = SearchIndex(beginStr);
        int end = SearchIndex(endStr);
        // begin和end是起始和终止点的索引
        if (begin == -1 || end == -1)
        {
            vector<string> error(1, "输入出错");
            return error;
        }
        // 首先遍历起点的邻近点，初始化
        map<string, int> cost; //记录每个节点的度
        int curmin;
        vector<string> temp;
        vector<vector<string>> res(size);
        res[begin].push_back({GraphArr[begin]->value});
        int Idx = 0;
        for (node *i : GraphArr)
        {
            cost[i->value] = INT16_MAX;
        }
        map<string, int> Map; //记录已经到达过的结点
        Map[GraphArr[begin]->value] = 0;
        cost[GraphArr[begin]->value] = 0;
        node *tempptr = GraphArr[begin]->next;
        if (tempptr == nullptr)
            return res[end];
        while (1)
        {
            curmin = INT16_MAX;
            while (tempptr != nullptr)
            {
                if (cost[tempptr->value] > cost[GraphArr[begin]->value] + pathcost[begin][Idx])
                {
                    cost[tempptr->value] = cost[GraphArr[begin]->value] + pathcost[begin][Idx];
                    temp = res[begin];
                    temp.push_back(tempptr->value);
                    res[SearchIndex(tempptr->value)] = temp;
                }
                tempptr = tempptr->next;
                Idx++;
            }
            Map[GraphArr[begin]->value]++;

            if (Map[GraphArr[end]->value])
                return res[end];

            for (int i = 0; i < size; i++)
            {
                if (cost[GraphArr[i]->value] < curmin && !Map[GraphArr[i]->value])
                {
                    curmin = cost[GraphArr[i]->value];
                    begin = i;
                }
            }
            tempptr = GraphArr[begin]->next;
            Idx = 0;
        }

        return res[end];
    }
    vector<string> requiredpath(string begin, string midpoint, string end)
    {
        vector<string> res = {"NOT SUCH PATH"};
        vector<string> BgToMid = myPath(begin, midpoint);
        vector<string> MidToEd = myPath(midpoint, end);
        MidToEd.erase(MidToEd.begin());
        if (!BgToMid.size() || !MidToEd.size())
            return res;
        for (string i : MidToEd)
            BgToMid.push_back(i);
        return BgToMid;
    }
    void updatecost(vector<vector<int>> cost)
    {
        pathcost = cost;
    }
};
// #endif
int main()
{
    vector<string> a = {"v1", "v3", "v5", "v6", "N",
                        "v2", "v3", "N",
                        "v3", "v4", "N",
                        "v4", "v6", "N",
                        "v5", "v4", "v6", "N",
                        "v6", "N"};
    vector<vector<int>> milecost = {{10, 30, 100}, {5}, {50}, {10}, {20, 60}};
    vector<vector<int>> timecost = {{5, 100, 13}, {7}, {11}, {15}, {22, 77}};
    Graph Map(6, a, milecost);
    Map.show();
    cout << endl;
    Map.topusort();
    cout<<endl;
    vector<string> bestpath = Map.myPath("v1", "v4");
    cout << "The nearest path:";
    for (string i : bestpath)
        cout << i << "->";
    cout << "FINISH" <<",the total cost is:"<<Map.ShortestPath("v1","v4")<< endl;
    cout<<"If v1 must go to v5 in a path including v3:";
    bestpath=Map.requiredpath("v1","v3","v6");
    for (string i : bestpath)
        cout << i << "->";
        cout<<"FINISH"<<endl;
    Map.updatecost(timecost);
    bestpath = Map.myPath("v1", "v4");
    cout << "The fastest path:";
    for (string i : bestpath)
        cout << i << "->";
    cout << "FINISH"<<",the total cost is:"<<Map.ShortestPath("v1","v4");
}
