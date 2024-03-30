#include<bits/stdc++.h>
using namespace std;
int weight=0;
int find(int x, vector<int> &parent)
{
    if(parent[x]==-1)   return x;
    return find(parent[x],parent);
}
void kruskaltraversal(vector<vector<int>> &edges, int n)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(auto x: edges)  pq.push({x[2],x[0],x[1]});
    vector<int> parent(n,-1);
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        if(find(node[1],parent)==find(node[2],parent))  continue;
        weight+=node[0];
        parent[find(node[1],parent)]=find(node[2],parent);
        cout<<"\n  "<<node[1]<<"-> "<<node[2];
    }
}
int main()
{
    vector<vector<int>> edges={
        {0,1,4},{0,7,8},{1,7,11},{1,2,8},{2,8,2},{7,8,7},{6,7,1},{5,6,2},{4,5,10},{3,4,9},{3,5,14},{2,5,4},{6,8,6},{2,3,7}
    };
    kruskaltraversal(edges,9);
    cout<<"\n"<<weight;
}