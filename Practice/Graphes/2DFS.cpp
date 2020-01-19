#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int> >& adj, int start,vector<int>& vistied ){
    vistied[start]  = 1;
    // iterative print
    cout << " DFS" << start << endl; 
    for(int a : adj[start]){
        if(!vistied[a]) DFS(adj,a,vistied);
    }
    // topological sort
    cout << " top " << start <<endl; 
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
int main()
{
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
    
    // DFS
    for(int i = 0;i<adj.size();i++){
        if(!vistiedArr[i]) DFS(adj,i,vistiedArr);
    }
}