#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> A,vector<int> B){
    return A[2] < B[2];
}
int find(int a ,vector<int>& parent){
    if(a != parent[a]) parent[a] = find(parent[a],parent);
    return parent[a];
}
void merge(int a ,int b , vector<int>& parent, vector<int>& rank){
    int pa = find(a,parent);
    int pb = find(b,parent);
    if(rank[pa] > rank[pb]){
        parent[pb] = pa;
        rank[pa] += rank[pb];
    }else{
        parent[pa] = pb;
        rank[pb] += rank[pa];
    }
}
int solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),cmp);
    vector<int> parent(A,0);
    vector<int> rank(A,1);
    for(int i = 0;i<A;i++){
        parent[i] = i;
    }
    int totalCost = 0;
    for(auto b : B){
        if(find(b[0]-1,parent) == find(b[1]-1,parent)){
            continue;
        }
        totalCost += b[2];
        merge(b[0]-1,b[1]-1,parent,rank);
    }
    return totalCost;
}
