// Rotten Oranges
// Given a matrix of integers A of size N x M consisting of 0, 1 or 2. Each cell can have three values:
// The value 0 representing an empty cell.
// The value 1 representing a fresh orange.
// The value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange.
// If this is impossible, return -1 instead. Note:
// Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.

// Input Format
// The first argument given is the integer matrix A.
// Output Format
// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  
// If this is impossible, return -1 instead.
// Constraints
// 1 <= N, M <= 1000
// 0 <= A[i] <= 2
// For Example
// Input 1:
//     A = [   [2, 1, 1]
//             [1, 1, 0]
//             [0, 1, 1]   ]
// Output 1:
//     4

// Input 2:
//     A = [   [2, 1, 1]
//             [0, 1, 1]
//             [1, 0, 1]   ]
// Output 2:
//     -1


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int> > &A ,vector<vector<int> > &time, int x, int y ){
    vector<int> xd = {0,1,0,-1};
    vector<int> yd = {1,0,-1,0};
    for(int i = 0;i<4;i++){
        int newX = x + xd[i];
        int newY = y + yd[i];
        if(newX >= 0 && newY >= 0 && newX < A.size() && newY < A[0].size()){
            if( A[newX][newY] == 1 && time[newX][newY] > time[x][y]+1 ){
                time[newX][newY] = time[x][y]+1;
                DFS(A,time,newX,newY);
            }
        }
    }
    
}
int Solution(vector<vector<int> > &A) {
    vector<int> p(A[0].size(),INT_MAX);
    vector<vector<int> > time(A.size(),p);
    for(int i = 0;i<A.size();++i){
        for(int j = 0;j<A[0].size();++j){
            if(A[i][j] == 2){
                time[i][j] = 0;
                DFS(A,time,i,j);
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0;i<A.size();++i){
        for(int j = 0;j<A[0].size();++j){
            // int x = time[i][j] == INT_MAX ? 9:time[i][j];
            // cout << x << " ";
            if(A[i][j] == 1) ans = max(ans,time[i][j]);
        }
        // cout << endl;
    }
    return ans == INT_MAX ? -1 : ans;