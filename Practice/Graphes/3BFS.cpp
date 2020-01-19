#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int> >& adj,int start, vector<int>& visited){
    queue<int> Q;
    visited[start] = 1;
    Q.push(start);
    while(!Q.empty()){
        start = Q.front();
        cout << Q.front() << "  ";
        Q.pop();
        for(int a : adj[start]){
            if(!visited[a]){Q.push(a);visited[a]=1;}
        }
    }
}
// 12 11
// 8 1
// 8 3
// 7 4
// 7 5
// 2 6
// 0 7
// 2 8
// 0 9
// 2 0
// 5 0
// 10 11
int main(){
    int n;
    int e;
    cin >> n;
    cin >> e;
    vector<int> p;
    vector<vector<int> >  adj(n,p);
    vector<int> vistiedArr(n,0);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cout << "Edge connection between :: ";
        cin >> x;
        cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(auto a : adj){
        for(int x : a){
            cout << x << " ";
        }
        cout << endl;
    }
    for(int i = 0;i < n; i++){
        if(!vistiedArr[i])BFS(adj,i,vistiedArr);
    }
    // BFS(adj,0,vistiedArr);
}