#include<bits/stdc++.h>
using namespace std;
int weight=0;
void primstraversal(vector<vector<int>> &edges, int n)
{
    vector<vector<pair<int,int>>> graph(n);
    for(auto x: edges)
    {
        graph[x[0]].push_back({x[1],x[2]});
        graph[x[1]].push_back({x[0],x[2]});
    }
    
    vector<bool> vis(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        int currnode=node.second;
        if(vis[currnode])   continue;
        vis[currnode]=true;
        weight+=node.first;
        cout<<" -> "<<currnode;
        for(auto y: graph[currnode])
        {
            if(vis[y.first])    continue;
            pq.push({y.second,y.first});
        }
    }
}
int main()
{
    vector<vector<int>> edges={
        {0,1,4},{0,7,8},{1,7,11},{1,2,8},{2,8,2},{7,8,7},{6,7,1},{5,6,2},{4,5,10},{3,4,9},{3,5,14},{2,5,4},{6,8,6},{2,3,7}
    };
    primstraversal(edges,9);
    cout<<"\n"<<weight;
}