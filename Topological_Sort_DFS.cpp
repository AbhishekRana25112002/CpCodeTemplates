#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, int i, stack<int> &st, vector<bool> &vis) {
    vis[i] = true;
    for(auto &x: graph[i]){
        if(!vis[x])
            dfs(graph, x, st, vis);
    }
    st.push(i);
}

vector<int> topological_sort(vector<vector<int>> &graph, int &n) {
    stack<int> st;
    vector<bool> vis(n,false);
    
    for(int i = 0 ; i < n ; i++) {
        if(!vis[i])
            dfs(graph, i, st, vis);
    }
    vector<int> ans;
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        ans.push_back(top);
    }
    
}
