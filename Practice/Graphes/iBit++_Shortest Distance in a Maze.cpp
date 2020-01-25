#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> > &A, int x, int y, 
            vector<vector<int> > &Dist,vector<vector<int> > &visited){
    // if(visited[x][y] == 1){
    //     return;
    // }
    cout << x << "  " << y << endl;
    visited[x][y] = 1;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    for(int i =0;i<4;i++){
        int d0 = Dist[x][y];
        int newX = x + dx[i];
        int newY = y + dy[i];
        bool check = false;
        while(newX >=0 && newY >=0 && newX <A.size() &&
                newY < A[0].size() && A[newX][newY] == 0){
            d0++;
            // cout << x << "  " << y << " " << newX << " " << newY << endl;
            cout <<"Dist up :: " << Dist[newX][newY] << "  "<<d0 << endl;
            if(Dist[newX][newY] > d0){
                Dist[newX][newY] = d0;
            }else{
                
            }
            
            newX = newX + dx[i];
            newY = newY + dy[i];
            // cout << "E  :" << newX << "  " << newY << endl;
            // cout << "EE" << endl;
            check = true;
        }
        newX = newX - dx[i];
        newY = newY - dy[i];
        cout << x << "  " << y << " " << newX << " " << newY << endl;
        if(x != newX || y != newY)
            DFS(A,newX,newY,Dist,visited);
    }
}
int Solution(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    vector<vector<int> > Dist(A.size(),vector<int>(A[0].size(),INT_MAX));
    vector<vector<int> > visited(A.size(),vector<int>(A[0].size(),0));
    Dist[B[0]][B[1]] = 0;
    DFS(A,B[0],B[1],Dist,visited);
    for(auto d : Dist){
        for(int x : d){
            cout << x << "  ";
        }cout << endl;
    }
    return Dist[C[0]][C[1]] == INT_MAX ? -1 : Dist[C[0]][C[1]];
}
int main(){
    int n ;int m;
    cin >> n ; cin >> m;
    vector<vector<int>> A(n,vector<int>(m,0) ) ;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin >> A[i][j];
        }
    }
    vector<int> B(2,0);
    cin >> B[0]; cin >> B[1]; 
    vector<int> C(2,0);
    cin >> C[0]; cin >> C[1];
    Solution(A,B,C);
}
// 5 5
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
// 0 4
// 3 2