#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dikstra(vector<vector<pair<int,int>>> &Adj,vector<int> &Dist, int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    Dist[start] = 0;
    cout << start << endl;
    while (!pq.empty())
    {   
        pair<int,int> top = pq.top();
        int u = top.second;
        pq.pop();
        cout << top.second << endl;
        for(int i = 0;i < Adj[top.second].size();i++){
            int v = Adj[top.second][i].first;
            int w = Adj[top.second][i].second;
            if( Dist[v] > Dist[u] + w ){
                cout << u+1 << "  --  " << v+1 << "  ::  " << w << " D " <<Dist[v] << endl;
                Dist[v] = Dist[u] + w;
                pq.push({Dist[v],v});
            }
        } 
    }
    
}
int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<pair<int,int>> p;
    vector<vector<pair<int,int>>> Adj(n,p);
    vector<int> Dist1(n,INT_MAX);
    vector<int> Dist2(n,INT_MAX);
    for(int i = 0;i < e;i++){
        int a,b,w;
        cin >> a;cin >> b;cin >> w;
        a--;b--;
        Adj[a].push_back({b,w});
        Adj[b].push_back({a,w});
        
    }
    int start = 3;
    int end = 5;
    dikstra(Adj,Dist1,start);
    dikstra(Adj,Dist2,end);
    int f= INT_MAX;
    int node = 0;
    for(int i = 0;i <n ;i++ ){
        if( max(Dist1[i],Dist2[i]) < f ){
            f = max(Dist1[i],Dist2[i]);
            node = i;
        }
    }
    cout << "ans = " << f << "   "<< node   << endl;


    
// 6 5 1 3 2 3 5 4 1 2 3 2 6 5 2 4 7
}