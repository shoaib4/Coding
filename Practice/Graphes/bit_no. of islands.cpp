// Number of islands
// Given a matrix of integers A of size N x M consisting 
// of 0 and 1. A group of connected 1's forms an island. 
// From a cell (i, j) such that A[i][j] = 1 you can visit any 
// cell that shares a corner with (i, j) and value in that cell is 1. 
// More formally, from any cell (i, j) if A[i][j] = 1 you can visit:
// (i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
// (i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
// (i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
// (i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
// (i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
// (i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
// (i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
// (i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
// Return the number of islands. Note:
// Rows are numbered from top to bottom and columns are numbered 
// from left to right.
// Your solution will run on multiple test cases. If you are using 
// global variables, make sure to clear them.

// Input Format
// The only argument given is the integer matrix A.
// Output Format
// Return the number of islands.
// Constraints
// 1 <= N, M <= 100
// 0 <= A[i] <= 1
// For Example
// Input 1:
//     A = [   [0, 1, 0]
//             [0, 0, 1]
//             [1, 0, 0]   ]
// Output 1:
//     2

// Input 2:
//     A = [   [1, 1, 0, 0, 0]
//             [0, 1, 0, 0, 0]
//             [1, 0, 0, 1, 1]
//             [0, 0, 0, 0, 0]
//             [1, 0, 1, 0, 1]    ]
// Output 2:
//     5
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> > &A , int x, int y){
    vector<int> dx = {0,1,0,-1,1,1,-1,-1};
    vector<int> dy = {1,0,-1,0,1,-1,-1,1};
    A[x][y] = -1;
    for(int i = 0;i<8;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newY >= 0 && newX < A.size() && newY < A[0].size()){
            if(A[newX][newY] == 1){
                DFS(A,newX,newY);
            }
        }
    }
}
int Solution(vector<vector<int> > &A) {
    int count = 0;
    for(int i = 0;i<A.size(); i++){
        for(int j = 0;j<A[0].size();++j){
            if(A[i][j] == 1){
                DFS(A,i,j);
                count++;
            }
        }
    }
    return count;
}
