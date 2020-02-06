#include <bits/stdc++.h>

using namespace std;
void foridWarshial(vector<vector<int>>& Dist){
    for(int k = 0;k<Dist.size();k++){
        for(int i = 0;i<Dist.size();i++){
            for(int j = 0;j<Dist.size();j++){
                if(Dist[i][k] != INT_MAX && Dist[k][j] != INT_MAX && 
                Dist[i][j] > Dist[i][k] + Dist[k][j]){
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
                }
            }
        }
    }
}

pair<int, long long> getAns(vector<vector<int>>& Dist, int u, int v){
    
    //Calculate answer
    u--;v--;
    int f = INT_MAX;
    int p = 0;
    for(int i = 0;i<Dist.size();i++){
        if(f > max(Dist[i][u], Dist[i][v])){
            f = max(Dist[i][u], Dist[i][v]);
            p = i;
        }
    }
    return {p+1,f+1};
}
int main()
{

    int N;
    cin >> N;

    vector<vector<int>> Dist(N,vector<int>(N,INT_MAX));
    for(int i = 0; i < N - 1; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        Dist[a][b] = w;
    }
    for(int i = 0; i < N ; i++){
        Dist[i][i] = 0;
    }
    foridWarshial(Dist);

    int Q;
    cin >> Q;

    while(Q--){

        int u, v;
        cin >> u >> v;

        pair<int, long long>P = getAns(Dist, u, v);

        cout << P.first << " " << P.second << endl;
    }

    return 0;
}