// Capture Regions on Board
// Given a 2D board containing 'X' and 'O', capture all 
// regions surrounded by 'X'. A region is captured by flipping 
// all 'O's into 'X's in that surrounded region. Input Format:
//     First and only argument is a N x M character matrix A
// Output Format:
//     make changes to the the input only as matrix is passed by reference.
// Constraints:
//     1 <= N,M <= 1000
// For Example:
// Input 1:
//     A = [ [X, X, X, X],
//           [X, O, O, X],
//           [X, X, O, X],
//           [X, O, X, X] ]
// Output 1:
//     After running your function, the board should be:
//     A = [ [X, X, X, X],
//           [X, X, X, X],
//           [X, X, X, X],
//           [X, O, X, X] ]
// Explanation:
//     O in (4,2) is not surrounded by X from below.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<char> > &A , int x, int y){
    A[x][y]='P';
    vector<int>dx = {0,1,0,-1};
    vector<int>dy = {1,0,-1,0};
    for(int i = 0;i<4;i++){
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx>=0 && newx<A.size() && newy>=0 && newy<A[0].size()){
            if(A[newx][newy] == 'O' ){
                DFS(A,newx,newy);
            }
        }
    }
}
void Solution (vector<vector<char> > &A) {
    for(int i = 0;i <A.size();i++){
        if(A[i][0] == 'O') DFS(A,i,0);
    }
    for(int i = 0;i <A.size();i++){
        if(A[i][A[0].size()-1] == 'O') DFS(A,i,A[0].size()-1);
    }
    for(int i = 0;i<A[0].size();i++){
        if(A[0][i] == 'O') DFS(A,0,i);
    }
    for(int i = 0;i<A[0].size();i++){
        if(A[A.size()-1][i] == 'O') DFS(A,A.size()-1,i);
    }
    
    for(int i = 0;i<A.size();++i){
        for(int j = 0;j<A[0].size();++j){
            if(A[i][j] == 'O') A[i][j] = 'X';
            else if(A[i][j] == 'P') A[i][j] = 'O';
        }
        // cout << endl;
    }
}
