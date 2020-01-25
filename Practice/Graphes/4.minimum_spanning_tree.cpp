#include <iostream>
#include <bits/stdc++.h>
#include <chrono> 
using namespace std;
int min_spanning_tree(int A,vector<vector<int>>B){
    vector<int> node(A);
    iota(node.begin(),node.end(),1);
    for(int i : node){
        cout << i << endl;
    }
}

bool cmp(vector<int>a,vector<int>b){
    if(a[2] > b[2]) return 1;
    else if(a[2] < b[2]) return -1;
    else return 0;
}
int solution(int A,vector<vector<int>>B){
    sort(B.begin(),B.end(),cmp);
    return min_spanning_tree(A,B);
}
int main(){
    int A;
    cin >> A;
    int x;
    cin >> x;
    vector<vector<int>> B(x,vector<int>(3,0));
    for(int i = 0;i<x;i++){
        cin >> B[i][0];
        cin >> B[i][1];
        cin >> B[i][2];
    }
    return solution(A,B);
}