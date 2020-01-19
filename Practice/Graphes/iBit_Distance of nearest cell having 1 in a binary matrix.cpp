// Distance of nearest cell having 1 in a binary matrix
// Given a matrix of integers A of size N x M consisting of 0 or 1. 
// For each cell of the matrix find the distance of nearest 1 in the matrix. 
// Distance between two cells (x1, y1) and (x2, y2) is defined 
// as |x1 - y1| + |x2 - y2|. Find and return a matrix B of size N x M which 
// defines for each cell in A distance of nearest 1 in the matrix A. Note:
// Your solution will run on multiple test cases. If you are 
// using global variables, make sure to clear them.
// There is atleast one 1 is present in the matrix.

// Input Format
// The first argument given is the integer matrix A.
// Output Format
// Return the matrix B.
// Constraints
// 1 <= N, M <= 1000
// 0 <= A[i] <= 2
// For Example
// Input 1:
//     A = [   [0, 0, 0, 1]
//             [0, 0, 1, 1]
//             [0, 1, 1, 0]   ]
// Output 1:
//         [   [3, 2, 1, 0]
//             [2, 1, 0, 0]
//             [1, 0, 0, 1]   ]

// Input 2:
//     A = [   [1, 0, 0]
//             [0, 0, 0]
//             [0, 0, 0]   ]
// Output 2:
//         [   [0, 1, 2]
//             [1, 2, 3]
//             [2, 3, 4]   ]
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int> > &A,int x,int y){
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {-1,0,1,0};
    for(int i = 0;i<4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newY >= 0 && newX < A.size() && newY < A[0].size() ){
            if(A[newX][newY] > A[x][y]+1 ){
                A[newX][newY] = A[x][y]+1;
                DFS(A,newX,newY);
            }
        }
    }
}
vector<vector<int> > Solution(vector<vector<int> > &A) {
    for(int i =0;i<A.size();i++){
        for(int j =0;j<A[0].size();++j){
            if(A[i][j] == 0) {A[i][j] = INT_MAX;}
            else if(A[i][j] == 1){A[i][j] = 0;}
        }
    }
    for(int i =0;i<A.size();i++){
        for(int j =0;j<A[0].size();++j){
            if(A[i][j] == 0) {
                DFS(A,i,j);
            }
        }
    }
    return A;
}