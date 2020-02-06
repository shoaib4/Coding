#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> adj(A,vector<int>());
    vector<int> degree(A,0);
    for(int i = 0; i<B.size();i++){
        adj[B[i]-1].push_back(C[i]-1);
        degree[C[i]-1]++;
    }
    int count = 0;
    queue<int> q;
    for(int i = 0;i<A;i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    int i = 0;
    while(!q.empty() && i <= A){
        int u = q.front();q.pop();
        count++;
        for(auto edg : adj[u]){
            int v = edg;
            if(degree[v] > 0){
                degree[v]--;
                if(degree[v] == 0){
                    q.push(v);
                }
            }
        }
    }
    if(count == A){
        return 1;
    }else{
        return 0;
    }
}
