#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void floidWarshal(vector<vector<int>>& Dist){
    for(int k = 0;k < Dist.size(); k++){
        for(int i = 0;i < Dist.size(); i++){
            for(int j = 0;j < Dist.size(); j++){
                if(
                    Dist[i][k] != INT_MAX && Dist[k][j] != INT_MAX && 
                    Dist[i][j] > Dist[i][k] + Dist[k][j]){
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
                }
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> Dist(n,vector<int>(n,INT_MAX));
    for(int i = 0;i<n;i++)Dist[i][i] = 0; 
    for(int i = 0;i < e;i++){
        int a,b,w;
        cin >> a;cin >> b;cin >> w;
        a--;b--;
        Dist[a][b] = w; 
    }
    floidWarshal(Dist);
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x;cin >> y;
        x--;y--;
        int force = INT_MAX;
        int point = 0;
        for(int i = 0;i<n;i++){
            if(force > max(Dist[i][x],Dist[i][y])){
                force = max(Dist[i][x],Dist[i][y]);
                point = i;
            }
        } 
        cout << " ans " << point+1 << "  " << force+1 << endl;   
    }
}