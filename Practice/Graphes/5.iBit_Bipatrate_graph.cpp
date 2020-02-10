#include <bits/stdc++.h>
using namespace std;
bool ans = true;
void dfs(vector<vector<int>>& adj, int u, vector<int>& visited,vector<int>& color ){
    visited[u] = 1;
    // cout << u << " ";
    for(auto v : adj[u]){
        if(visited[v] == 0){
            color[v] = -1*color[u];
            dfs(adj,v,visited,color);
        }else{
            if(color[v] != 0 && color[v] != -1*color[u]){
                ans &= false;
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    ans = true;
    vector<vector<int>> adj(A,vector<int>());
    vector<int> visited(A,0);
    vector<int> color(A,0);
    for(auto b : B){
        adj[b[0]].push_back(b[1]);
        adj[b[1]].push_back(b[0]);
    }
    for(int i = 0;i<A;i++){
        if(visited[i] == 0){
            color[i] = 1;
            dfs(adj,i,visited,color);
        }
    }
    // for(int i = 0;i<A;i++){
    //     cout << color[i] << " ";
    // }
    return ans;
}
