// Given N x M character matrix A of O's and X's, 
// where O = white, X = black.
// Return the number of black shapes. A black shape consists of 
// one or more adjacent X's (diagonals not included) 
// Input Format:
//     The First and only argument is a N x M character matrix.
// Output Format:
//     Return a single integer denoting number of black shapes.
// Constraints:
//     1 <= N,M <= 1000
//     A[i][j] = 'X' or 'O'
// Example:
// Input 1:
//     A = [ OOOXOOO
//           OOXXOXO
//           OXOOOXO  ]
// Output 1:
//     3
// Explanation:
//     3 shapes are  :
//     (i)    X
//          X X
//     (ii)
//           X
//     (iii)
//           X
//           X
// Note: we are looking for connected shapes here.
// XXX
// XXX
// XXX
// is just one single connected black shape.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<string> &A,int x, int y){
    A[x][y] = 'P';
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    for(int i =0;i<4;i++){
        int newX = x+dx[i];
        int newY = y+dy[i];
        if(newX >=0 && newY >= 0 && newX < A.size() && 
        newY < A[0].size()){
            if(A[newX][newY] == 'X') DFS(A,newX,newY);
        }
    }
}
int Solution(vector<string> &A) {
    int count = 0;
    for(int i = 0;i<A.size();++i){
        for(int j = 0;j<A[0].size();++j){
            if(A[i][j] == 'X') {DFS(A,i,j);count++;};
        }
    }
    return count;
}
